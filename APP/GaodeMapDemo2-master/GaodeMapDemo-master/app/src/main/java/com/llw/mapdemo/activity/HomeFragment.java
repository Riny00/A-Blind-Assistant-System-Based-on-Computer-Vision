package com.llw.mapdemo.activity;

import static android.content.ContentValues.TAG;
import static com.llw.mapdemo.util.MapUtil.convertToLatLng;
import static com.llw.mapdemo.util.MapUtil.convertToLatLonPoint;

import static java.lang.Thread.sleep;

import androidx.annotation.NonNull;

import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.viewmodel.CreationExtras;
import androidx.navigation.Navigation;

import android.Manifest;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Environment;
import android.os.Looper;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import com.amap.api.location.AMapLocation;
import com.amap.api.location.AMapLocationClient;
import com.amap.api.location.AMapLocationClientOption;
import com.amap.api.location.AMapLocationListener;
import com.amap.api.maps.AMap;
import com.amap.api.maps.LocationSource;
import com.amap.api.maps.MapView;
import com.amap.api.maps.TextureMapView;
import com.amap.api.maps.model.BitmapDescriptorFactory;
import com.amap.api.maps.model.LatLng;
import com.amap.api.maps.model.MarkerOptions;
import com.amap.api.services.core.AMapException;
import com.amap.api.services.core.LatLonPoint;
import com.amap.api.services.core.ServiceSettings;
import com.amap.api.services.geocoder.GeocodeAddress;
import com.amap.api.services.geocoder.GeocodeQuery;
import com.amap.api.services.geocoder.GeocodeResult;
import com.amap.api.services.geocoder.GeocodeSearch;
import com.amap.api.services.geocoder.RegeocodeResult;
import com.amap.api.services.route.BusRouteResult;
import com.amap.api.services.route.DriveRouteResult;
import com.amap.api.services.route.RideRouteResult;
import com.amap.api.services.route.RouteSearch;
import com.amap.api.services.route.WalkPath;
import com.amap.api.services.route.WalkRouteResult;
import com.iflytek.cloud.ErrorCode;
import com.iflytek.cloud.InitListener;
import com.iflytek.cloud.RecognizerResult;
import com.iflytek.cloud.SpeechConstant;
import com.iflytek.cloud.SpeechError;
import com.iflytek.cloud.SpeechEvent;
import com.iflytek.cloud.SpeechRecognizer;
import com.iflytek.cloud.VoiceWakeuper;
import com.iflytek.cloud.WakeuperListener;
import com.iflytek.cloud.WakeuperResult;
import com.iflytek.cloud.ui.RecognizerDialog;
import com.iflytek.cloud.ui.RecognizerDialogListener;
import com.iflytek.cloud.util.ResourceUtil;
import com.llw.mapdemo.MainActivity;
import com.llw.mapdemo.NaviActivity;
import com.llw.mapdemo.R;
import com.llw.mapdemo.RouteActivity;
import com.llw.mapdemo.RouteDetailActivity;
import com.llw.mapdemo.overlay.WalkRouteOverlay;
import com.llw.mapdemo.util.JsonParser;
import com.llw.mapdemo.util.MapUtil;
import com.llw.mapdemo.util.MyTTS;
import com.llw.mapdemo.util.Weather;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.lang.reflect.InvocationTargetException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

import pub.devrel.easypermissions.EasyPermissions;

public class HomeFragment extends Fragment implements AMapLocationListener, LocationSource, RouteSearch.OnRouteSearchListener, AMap.OnMapClickListener, View.OnKeyListener, GeocodeSearch.OnGeocodeSearchListener {
    //*********************通信部分***************************************************************
    Socket socket=null;
    OutputStream outputStream=null;
    String str1="";
    String str2="";
    //发送给服务端的消息
    String msg = "Good Night";
    String Help="";
    //*********************地图导航部分***************************************************************
    String address="";
    Bundle bundle;
    public AMapLocationClient mLocationClient = null;//声明AMapLocationClient类对象
    public AMapLocationClientOption mLocationOption = null;//声明AMapLocationClientOption对象
    private TextureMapView mapView;
    private AMap aMap = null;//地图控制器
    private LocationSource.OnLocationChangedListener mListener;//位置更改监听
    private LatLonPoint mStartPoint;//起点
    private LatLonPoint mEndPoint;//终点
    private RouteSearch routeSearch;//路线搜索对象
    //路线规划详情
    private RelativeLayout bottomLayout;
    //花费时间
    private TextView tvTime;
    //起点、终点
    private EditText etStartAddress, etEndAddress;
    //地理编码搜索
    private GeocodeSearch geocodeSearch;
    //解析成功标识码
    private static final int PARSE_SUCCESS_CODE = 1000;
    //城市
    private String city;

    private double start_lng;// 起终点坐标
    private double start_lat;
    private double endLng = 0.0;
    private double endLat = 0.0;

    //*********************语音唤醒部分***************************************************************
    MyTTS mytts;
    private int curThresh = 1450;//唤醒的阈值
    private String keep_alive = "1";//是否持续唤醒
    private String ivwNetMode = "0";
    private VoiceWakeuper mIvw;// 语音唤醒对象
    private String wordID = "";//存储唤醒词的ID
    private String resultString;// 唤醒结果内容

    //*********************语音识别部分***************************************************************
    private static final String TAG = "HomeFragment";
    private SpeechRecognizer mIat;// 语音听写对象
    private RecognizerDialog mIatDialog;// 语音听写UI
    private HashMap<String, String> mIatResults = new LinkedHashMap<String, String>();// 用HashMap存储听写结果
    private SharedPreferences mSharedPreferences;//缓存
    private String mEngineType = SpeechConstant.TYPE_CLOUD;// 引擎类型
    private String language = "zh_cn";//识别语言
    private TextView tvResult;//识别结果
    private Button btnStart;//开始识别
    private String resultType = "json";//结果内容数据格式
//*********************天气查询部分***************************************************************
    Weather weather;
    String weather_info="";

    Runnable net=new Runnable() {
        @Override
        public void run() {
            try {
                Socket socket;
                //socket=new Socket("192.168.1.102", 12345);//注意这里
                socket = new Socket();
                SocketAddress socAddress = new InetSocketAddress("47.115.230.59", 9999);
                socket.connect(socAddress, 3000);//超时3秒

                try {
                    //获取输出流并实例化
                    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
                    while(true)
                    {
                        sleep(3000);
                        msg=str2+' '+str1+' '+Help;//经度+纬度+是否求助
                        out.write(msg+"\n");//防止粘包
                        out.flush();//不加这个flush会怎样？
                        Help="";//重置为空
                    }

                } catch (Exception e) {
                    e.printStackTrace();
                } finally {
                    //关闭Socket
                    socket.close();
                    System.out.println("客户端关闭");
                }
            }
            catch (Exception e) {
                System.out.println("链接错误");
                e.printStackTrace();
            }
        }
    };
    Runnable get_weather=new Runnable() {
        @Override
        public void run() {
            while(true){
                Weather weather = new Weather();
                weather_info=weather.weather_info();
                try {
                    sleep(5000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    };

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.activity_home_fragment, container, false);
        new Thread(net).start();//与服务端通信子线程
        new Thread(get_weather).start();//获取天气信息子线程

//**************************************语音导航部分**************************************
        initPermission();//权限请求

        bundle = new Bundle();
        // 使用SpeechRecognizer对象，可根据回调消息自定义界面；
        mIat = SpeechRecognizer.createRecognizer(getActivity(), mInitListener);
        // 使用UI听写功能，请根据sdk文件目录下的notice.txt,放置布局文件和图片资源
        mIatDialog = new RecognizerDialog(getActivity(), mInitListener);
        mSharedPreferences = getActivity().getSharedPreferences("ASR", Activity.MODE_PRIVATE);

//**************************************语音唤醒部分**************************************

        initRecognizer();
//**************************************地图导航部分**************************************
        etStartAddress = root.findViewById(R.id.et_start_address);  //当前所在地
        etEndAddress = root.findViewById(R.id.et_end_address);      //终点所在地
        etEndAddress.setOnKeyListener((View.OnKeyListener) this);   //键盘按键监听
        //构造 GeocodeSearch 对象
        try {
            ServiceSettings.updatePrivacyShow(getContext(), true, true);
            ServiceSettings.updatePrivacyAgree(getContext(), true);
            geocodeSearch = new GeocodeSearch(getContext());
        } catch (AMapException e) {
            throw new RuntimeException(e);
        }
        //设置监听
        geocodeSearch.setOnGeocodeSearchListener((GeocodeSearch.OnGeocodeSearchListener) this);
        initview(savedInstanceState, root);
        initLocation();
        mLocationClient.startLocation();
        initRoute();
        initTravelMode();

        return root;
    }

    //******************************地图导航部分******************************
    private void initview(Bundle savedInstanceState, View view) {
        mapView = (TextureMapView) view.findViewById(R.id.map_view);
        mapView.onCreate(savedInstanceState);
        //初始化地图控制器对象
        aMap = mapView.getMap();

        // 设置定位监听
        aMap.setLocationSource(this);
        aMap.setMinZoomLevel(14);
        // 设置为true表示显示定位层并可触发定位，false表示隐藏定位层并不可触发定位，默认是false
        aMap.setMyLocationEnabled(true);
        //地图点击监听
        aMap.setOnMapClickListener(this);

        //tvTime=(TextView) view.findViewById(R.id.tv_time);
//        etStartAddress=(EditText) view.findViewById(R.id.et_address);
//        etEndAddress=(EditText) view.findViewById(R.id.et_end_address);
        //etEndAddress.setOnKeyListener((View.OnKeyListener) view.getContext());
    }

    /**
     * 初始化定位
     */
    private void initLocation() {
        //初始化定位
        try {
            mLocationClient = new AMapLocationClient(getActivity());
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (mLocationClient != null) {
            //设置定位回调监听
            mLocationClient.setLocationListener(this);
            //初始化AMapLocationClientOption对象
            mLocationOption = new AMapLocationClientOption();
            //设置定位模式为AMapLocationMode.Hight_Accuracy，高精度模式。
            mLocationOption.setLocationMode(AMapLocationClientOption.AMapLocationMode.Hight_Accuracy);
            //获取最近3s内精度最高的一次定位结果：
            //设置setOnceLocationLatest(boolean b)接口为true，启动定位时SDK会返回最近3s内精度最高的一次定位结果。如果设置其为true，setOnceLocation(boolean b)接口也会被设置为true，反之不会，默认为false。
            mLocationOption.setOnceLocationLatest(true);
            //设置是否返回地址信息（默认返回地址信息）
            mLocationOption.setNeedAddress(true);
            //设置定位请求超时时间，单位是毫秒，默认30000毫秒，建议超时时间不要低于8000毫秒。
            mLocationOption.setHttpTimeOut(40000);
            //关闭缓存机制，高精度定位会产生缓存。
            mLocationOption.setLocationCacheEnable(false);
            //给定位客户端对象设置定位参数
            mLocationClient.setLocationOption(mLocationOption);


        }
    }

    /**
     * 初始化路线
     */
    private void initRoute() {
        try {
            routeSearch = new RouteSearch(getActivity().getApplicationContext());
        } catch (AMapException e) {
            e.printStackTrace();
        }
        routeSearch.setRouteSearchListener(this);
    }

    /**
     * 初始化出行方式
     */
    private void initTravelMode() {

        //bottomLayout= bottomLayout.findViewById(R.id.bottom_layout);
        //tvTime=tvTime.findViewById(R.id.tv_time);

    }

    /**
     * 开始路线搜索
     */
    private void startRouteSearch() {
        //在地图上添加起点Marker
        aMap.addMarker(new MarkerOptions()
                .position(convertToLatLng(mStartPoint))
                .icon(BitmapDescriptorFactory.fromResource(R.drawable.start)));
        //在地图上添加终点Marker
        aMap.addMarker(new MarkerOptions()
                .position(convertToLatLng(mEndPoint))
                .icon(BitmapDescriptorFactory.fromResource(R.drawable.end)));

        //搜索路线 构建路径的起终点
        final RouteSearch.FromAndTo fromAndTo = new RouteSearch.FromAndTo(
                mStartPoint, mEndPoint);
        //构建步行路线搜索对象
        RouteSearch.WalkRouteQuery query = new RouteSearch.WalkRouteQuery(fromAndTo, RouteSearch.WalkDefault);
        // 异步路径规划步行模式查询
        routeSearch.calculateWalkRouteAsyn(query);
    }

    /**
     * 接收异步返回的定位结果
     *
     * @param aMapLocation
     */
    @Override
    public void onLocationChanged(AMapLocation aMapLocation) {
        if (aMapLocation != null) {
            if (aMapLocation.getErrorCode() == 0) {
                //地址
                address = aMapLocation.getAddress();
                //设置当前所在地
                etStartAddress.setText(address);
                etStartAddress.setEnabled(false);//禁用输入

                start_lat = aMapLocation.getLatitude();
                start_lng = aMapLocation.getLongitude();

                System.out.println(address);

                double latitude = aMapLocation.getLatitude();//获取纬度
                double longitude = aMapLocation.getLongitude();//获取经度

                System.out.println("经度：" + longitude);
                System.out.println("纬度：" + latitude);

                str1 = String.valueOf(latitude);
                str2 = String.valueOf(longitude);



                //设置起点
                mStartPoint = convertToLatLonPoint(new LatLng(latitude, longitude));
                //设置终点
                mEndPoint = convertToLatLonPoint(new LatLng(32.371487, 120.573996));
                if (mListener != null) {
                    mListener.onLocationChanged(aMapLocation);
                }
                //tvContent.setText(	address == null ? "无地址" : address);
            } else {
                //定位失败时，可通过ErrCode（错误码）信息来确定失败的原因，errInfo是错误信息，详见错误码表。
                Log.e("AmapError", "location Error, ErrCode:"
                        + aMapLocation.getErrorCode() + ", errInfo:"
                        + aMapLocation.getErrorInfo());
            }
        }
    }

    /**
     * 点击地图
     */
    public void onMapClick(LatLng latLng) {
        //终点
        mEndPoint = convertToLatLonPoint(latLng);
        startRouteSearch();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        //销毁定位客户端，同时销毁本地定位服务。
        mLocationClient.onDestroy();
        if (null != mIat) {
            // 退出时释放连接
            mIat.cancel();
            mIat.destroy();
        }
//        mapView.onDestroy();
    }

    @Override
    public void onResume() {
        super.onResume();

        mapView.onResume();
    }

    @Override
    public void onPause() {
        super.onPause();
        //在activity执行onPause时执行mMapView.onPause ()，暂停地图的绘制
        mapView.onPause();
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        //在activity执行onSaveInstanceState时执行mMapView.onSaveInstanceState (outState)，保存地图当前的状态
        mapView.onSaveInstanceState(outState);
    }

    @Override
    public void activate(OnLocationChangedListener onLocationChangedListener) {
        mListener = onLocationChangedListener;
        if (mLocationClient == null) {
            try {
                mLocationClient = new AMapLocationClient(getActivity());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            mLocationClient.startLocation();//启动定位
        }
    }

    @Override
    public void deactivate() {
        mListener = null;
        if (mLocationClient != null) {
            mLocationClient.stopLocation();
            mLocationClient.onDestroy();
        }
        mLocationClient = null;
    }


    @Override
    public void onBusRouteSearched(BusRouteResult busRouteResult, int i) {

    }

    @Override
    public void onDriveRouteSearched(DriveRouteResult driveRouteResult, int i) {

    }

    /**
     * 步行规划路径结果
     *
     * @param walkRouteResult 结果
     * @param code            结果码
     */
    @Override
    public void onWalkRouteSearched(WalkRouteResult walkRouteResult, int code) {
        aMap.clear();// 清理地图上的所有覆盖物
        if (code == AMapException.CODE_AMAP_SUCCESS) {
            if (walkRouteResult != null && walkRouteResult.getPaths() != null) {
                if (walkRouteResult.getPaths().size() > 0) {
                    final WalkPath walkPath = walkRouteResult.getPaths().get(0);
                    if (walkPath == null) {
                        return;
                    }

                    System.out.println("walkPath:" + walkPath);
                    //绘制路线
                    WalkRouteOverlay walkRouteOverlay = new WalkRouteOverlay(
                            getActivity().getApplicationContext(), aMap, walkPath,
                            walkRouteResult.getStartPos(),
                            walkRouteResult.getTargetPos());
                    walkRouteOverlay.removeFromMap();
                    walkRouteOverlay.addToMap();
                    walkRouteOverlay.zoomToSpan();

                    int dis = (int) walkPath.getDistance();
                    int dur = (int) walkPath.getDuration();
                    String des = MapUtil.getFriendlyTime(dur) + "(" + MapUtil.getFriendlyLength(dis) + ")";

                    Log.d(TAG, des);

                } else if (walkRouteResult.getPaths() == null) {
                    showMsg("对不起，没有搜索到相关数据！");
                }
            } else {
                showMsg("对不起，没有搜索到相关数据！");
            }
        } else {
            showMsg("错误码；" + code);
        }
    }

    @Override
    public void onRideRouteSearched(RideRouteResult rideRouteResult, int i) {

    }

    /**
     * 消息提示
     *
     * @param msg 内容
     */
    private void showMsg(String msg) {
        Toast.makeText(getActivity().getApplicationContext(), msg, Toast.LENGTH_SHORT).show();
    }

    @NonNull
    @Override
    public CreationExtras getDefaultViewModelCreationExtras() {
        return super.getDefaultViewModelCreationExtras();
    }

    @Override
    public boolean onKey(View v, int keyCode, KeyEvent event) //手动输入目的地
    {
        if (keyCode == KeyEvent.KEYCODE_ENTER && event.getAction() == KeyEvent.ACTION_UP) {
            //获取输入框的值
            String endAddress = etEndAddress.getText().toString().trim();
            if (endAddress.isEmpty()) {
                showMsg("请输入要前往的目的地");
            } else {
                InputMethodManager imm = (InputMethodManager) getContext().getSystemService(getContext().INPUT_METHOD_SERVICE);
                //隐藏软键盘
                imm.hideSoftInputFromWindow(getActivity().getWindow().getDecorView().getWindowToken(), 0);
                //通过输入的目的地转为经纬度，然后进行地图上添加标点，最后计算出行路线规划

                // name表示地址，第二个参数表示查询城市，中文或者中文全拼，citycode、adcode
                GeocodeQuery query = new GeocodeQuery(endAddress, "");
                geocodeSearch.getFromLocationNameAsyn(query);
            }
            return true;
        }
        return false;
    }

    @Override
    public void onRegeocodeSearched(RegeocodeResult regeocodeResult, int i) {

    }

    @Override
    public void onGeocodeSearched(GeocodeResult geocodeResult, int i) {
        if (i == PARSE_SUCCESS_CODE) {
            List<GeocodeAddress> geocodeAddressList = geocodeResult.getGeocodeAddressList();
            if (geocodeAddressList != null && ((List<?>) geocodeAddressList).size() > 0) {
                //终点
                mEndPoint = geocodeAddressList.get(0).getLatLonPoint();
                try {
                    sleep(1500);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.println("mEndPoint:" + mEndPoint);
                endLng = mEndPoint.getLongitude();
                endLat = mEndPoint.getLatitude();
                bundle.putDouble("end_lng", endLng);
                bundle.putDouble("end_lat", endLat);

                Intent intent = new Intent();
                intent.setClass(getContext(), NaviActivity.class);
                intent.putExtras(bundle);
                startActivity(new Intent(intent));

                //开始路线搜索
                //startRouteSearch();
            }

        } else {
            showMsg("获取坐标失败");
        }
    }

    //******************************语音唤醒部分******************************
    public void initRecognizer() {
        mytts=new MyTTS(getContext());

        // 初始化唤醒对象
        mIvw = VoiceWakeuper.createWakeuper(getContext(), null);
        //非空判断，防止因空指针使程序崩溃
        mIvw = VoiceWakeuper.getWakeuper();
        if (mIvw != null) {
            resultString = "";
            // 清空参数
            mIvw.setParameter(SpeechConstant.PARAMS, null);
            // 唤醒门限值，根据资源携带的唤醒词个数按照“id:门限;id:门限”的格式传入
            mIvw.setParameter(SpeechConstant.IVW_THRESHOLD, "0:" + curThresh);
            // 设置唤醒模式
            mIvw.setParameter(SpeechConstant.IVW_SST, "wakeup");
            // 设置持续进行唤醒
            mIvw.setParameter(SpeechConstant.KEEP_ALIVE, keep_alive);
            // 设置闭环优化网络模式
            mIvw.setParameter(SpeechConstant.IVW_NET_MODE, ivwNetMode);
            // 设置唤醒资源路径
            mIvw.setParameter(SpeechConstant.IVW_RES_PATH, getResource());
            // 设置唤醒录音保存路径，保存最近一分钟的音频
            mIvw.setParameter(SpeechConstant.IVW_AUDIO_PATH, Environment.getExternalStorageDirectory().getPath() + "/msc/ivw.wav");
            mIvw.setParameter(SpeechConstant.AUDIO_FORMAT, "wav");
            // 如有需要，设置 NOTIFY_RECORD_DATA 以实时通过 onEvent 返回录音音频流字节
            //mIvw.setParameter( SpeechConstant.NOTIFY_RECORD_DATA, "1" );

            // 启动唤醒
            mIvw.startListening(new MyWakeuperListener());
        } else {
            showMsg("唤醒未初始化");
        }
    }

    private String getResource() {
        final String resPath = ResourceUtil.generateResourcePath(getContext(), ResourceUtil.RESOURCE_TYPE.assets, "ivw/" + getString(R.string.app_id) + ".jet");
        return resPath;
    }

    /**
     * 唤醒词监听类
     * @author Administrator
     *
     */
    private class MyWakeuperListener implements WakeuperListener {
        //开始说话
        @Override
        public void onBeginOfSpeech() {

        }

        //错误码返回
        @Override
        public void onError(SpeechError arg0) {

        }

        @Override
        public void onEvent(int arg0, int arg1, int arg2, Bundle arg3) {

        }

        @Override
        public void onVolumeChanged(int i) {

        }

        @Override
        public void onResult(WakeuperResult result)//唤醒后的逻辑处理
        {
            mytts.mySpeak("我在");///语音唤醒后的回应

            if (null == mIat) {
                // 创建单例失败，与 21001 错误为同样原因，参考 http://bbs.xfyun.cn/forum.php?mod=viewthread&tid=9688
                showMsg("创建对象失败，请确认 libmsc.so 放置正确，且有调用 createUtility 进行初始化");
                return;
            }
            mIatResults.clear();//清除数据
            setParam(); // 设置参数
            mIatDialog.setListener(mRecognizerDialogListener);//设置监听
            mIatDialog.show();// 显示对话框

        }
    }

    //******************************语音识别部分******************************
    public void initPermission() {
        String permissions[] = {Manifest.permission.RECORD_AUDIO,
                Manifest.permission.ACCESS_NETWORK_STATE,
                Manifest.permission.INTERNET,
                Manifest.permission.WRITE_EXTERNAL_STORAGE
        };

        ArrayList<String> toApplyList = new ArrayList<String>();

        for (String perm : permissions) {
            if (PackageManager.PERMISSION_GRANTED != ContextCompat.checkSelfPermission(getActivity(), perm)) {
                toApplyList.add(perm);
            }
        }
        String tmpList[] = new String[toApplyList.size()];
        if (!toApplyList.isEmpty()) {
            ActivityCompat.requestPermissions(getActivity(), toApplyList.toArray(tmpList), 123);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        // 此处为android 6.0以上动态授权的回调，用户自行实现。
    }

    /**
     * 初始化监听器。
     */
    private InitListener mInitListener = new InitListener() {

        @Override
        public void onInit(int code) {
            Log.d(TAG, "SpeechRecognizer init() code = " + code);
            if (code != ErrorCode.SUCCESS) {
                showMsg("初始化失败，错误码：" + code + ",请点击网址https://www.xfyun.cn/document/error-code查询解决方案");
            }
        }
    };

    /**
     * 听写UI监听器
     */
    private RecognizerDialogListener mRecognizerDialogListener = new RecognizerDialogListener() {
        public void onResult(RecognizerResult results, boolean isLast) {

            printResult(results);//结果数据解析

        }

        /**
         * 识别回调错误.
         */
        public void onError(SpeechError error) {
            showMsg(error.getPlainDescription(true));
        }

    };

    private void printResult(RecognizerResult results) {
        Bundle bundle = new Bundle();
        String text = JsonParser.parseIatResult(results.getResultString());

        String sn = null;
        // 读取json结果中的sn字段
        try {
            JSONObject resultJson = new JSONObject(results.getResultString());
            sn = resultJson.optString("sn");
        } catch (JSONException e) {
            e.printStackTrace();
        }

        mIatResults.put(sn, text);

        StringBuffer resultBuffer = new StringBuffer();
        for (String key : mIatResults.keySet()) {
            resultBuffer.append(mIatResults.get(key));
        }

        //获取听写结果
        if (resultBuffer.toString().equals("退出。"))
        {
            getActivity().finish();
        }
        else if(resultBuffer.toString().equals("发送求助信息。"))
        {
            System.out.println("求助信息");
            Help=address;
        }
        else if(resultBuffer.toString().equals("瓶子在何处")||resultBuffer.toString().equals("椅子在何处"))
        {
            String msg22=BlueTooth_Recv.getwhere();
            if(msg22 == null || msg22 == "")
            {
                mytts.mySpeak("周围没有发现");
            }
            else {
                mytts.mySpeak(msg22);
            }
        }
        else if(resultBuffer.toString().equals("天气情况。"))
        {
            if(weather_info == null || weather_info == "")
            {
                mytts.mySpeak("未查询到相关天气信息");///语音唤醒后的回应
            }
            else {
                mytts.mySpeak(weather_info);///语音唤醒后的回应
            }
        }
        else if(resultBuffer.toString().substring(0,1).equals("去"))
        {
            System.out.println("显示");
            etEndAddress.setText(resultBuffer.toString().substring(1));//去除前一位并显示
            task();//获取结果后自动进行导航
        }
    }

    public void task() {
        //获取输入框的值
        String endAddress = etEndAddress.getText().toString().trim();
        if (endAddress.isEmpty()) {
            showMsg("请输入要前往的目的地");
        } else {

            // name表示地址，第二个参数表示查询城市，中文或者中文全拼，citycode、adcode
            GeocodeQuery query = new GeocodeQuery(endAddress, "city");
            geocodeSearch.getFromLocationNameAsyn(query);
        }
    }

    /**
     * 参数设置
     *
     * @return
     */
    public void setParam() {
        // 清空参数
        mIat.setParameter(SpeechConstant.PARAMS, null);
        // 设置听写引擎
        mIat.setParameter(SpeechConstant.ENGINE_TYPE, mEngineType);
        // 设置返回结果格式
        mIat.setParameter(SpeechConstant.RESULT_TYPE, resultType);

        if (language.equals("zh_cn")) {
            String lag = mSharedPreferences.getString("iat_language_preference",
                    "mandarin");
            Log.e(TAG, "language:" + language);// 设置语言
            mIat.setParameter(SpeechConstant.LANGUAGE, "zh_cn");
            // 设置语言区域
            mIat.setParameter(SpeechConstant.ACCENT, lag);
        } else {

            mIat.setParameter(SpeechConstant.LANGUAGE, language);
        }
        Log.e(TAG, "last language:" + mIat.getParameter(SpeechConstant.LANGUAGE));

        //此处用于设置dialog中不显示错误码信息
        //mIat.setParameter("view_tips_plain","false");

        // 设置语音前端点:静音超时时间，即用户多长时间不说话则当做超时处理
        mIat.setParameter(SpeechConstant.VAD_BOS, mSharedPreferences.getString("iat_vadbos_preference", "4000"));

        // 设置语音后端点:后端点静音检测时间，即用户停止说话多长时间内即认为不再输入， 自动停止录音
        mIat.setParameter(SpeechConstant.VAD_EOS, mSharedPreferences.getString("iat_vadeos_preference", "1000"));

        // 设置标点符号,设置为"0"返回结果无标点,设置为"1"返回结果有标点
        mIat.setParameter(SpeechConstant.ASR_PTT, mSharedPreferences.getString("iat_punc_preference", "1"));

        // 设置音频保存路径，保存音频格式支持pcm、wav，设置路径为sd卡请注意WRITE_EXTERNAL_STORAGE权限
        mIat.setParameter(SpeechConstant.AUDIO_FORMAT, "wav");
        mIat.setParameter(SpeechConstant.ASR_AUDIO_PATH, Environment.getExternalStorageDirectory() + "/msc/iat.wav");
    }


}