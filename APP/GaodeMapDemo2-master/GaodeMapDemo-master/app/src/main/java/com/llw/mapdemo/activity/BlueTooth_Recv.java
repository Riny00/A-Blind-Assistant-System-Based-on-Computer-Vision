package com.llw.mapdemo.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.widget.Button;
import android.widget.Toast;

import com.llw.mapdemo.MainActivity;
import com.llw.mapdemo.R;
import com.llw.mapdemo.util.DevicesList;
import com.llw.mapdemo.util.MyTTS;

import java.io.IOException;
import java.io.InputStream;
import java.util.UUID;

public class BlueTooth_Recv extends AppCompatActivity {
    MyTTS mytts;
    String last="";
    private final static String MY_UUID = "00001101-0000-1000-8000-00805F9B34FB";   //SPP服务UUID号
    private BluetoothAdapter mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter(); //获取蓝牙实例

    private String smsg = ""; //显示用数据缓存

    BluetoothDevice mBluetoothDevice = null; //蓝牙设备
    BluetoothSocket mBluetoothSocket = null; //蓝牙通信Socket

    boolean bRun = true; //运行状态
    boolean bThread = false; //读取线程状态
    private InputStream is;    //输入流，用来接收蓝牙数据

    public static String objwhere="";
    private int cnt_int=1;

    @SuppressLint("MissingPermission")

    public void init(Context mContext) {

        mytts=new MyTTS(mContext);

        //如果打不开蓝牙提示信息，结束程序
        if (mBluetoothAdapter == null){

            finish();
            return;
        }

        if (mBluetoothAdapter.isEnabled() == false) {

            return;
        }

        //如果未连接设备则打开DevicesListActivity搜索设备
        if (mBluetoothSocket == null) {

            // 得到蓝牙设备句柄
            mBluetoothDevice = mBluetoothAdapter.getRemoteDevice("A1:E4:2B:11:7B:B6");

            // 用服务号得到socket
            try {
                mBluetoothSocket = mBluetoothDevice.createRfcommSocketToServiceRecord(UUID.fromString(MY_UUID));
            } catch (IOException e) {

            }

            try {
                mBluetoothSocket.connect();

            } catch (IOException e) {
                try {

                    mBluetoothSocket.close();
                    mBluetoothSocket = null;
                } catch (IOException ee) {

                }
                return;
            }

            //打开接收线程
            try {
                is = mBluetoothSocket.getInputStream();   //得到蓝牙数据输入流
            } catch (IOException e) {

                return;
            }
            if (bThread == false) {
                readThread.start();
                bThread = true;
            } else {
                bRun = true;
            }

        } else {
            //关闭连接socket
            try {
                bRun = false;
                Thread.sleep(2000);

                is.close();
                mBluetoothSocket.close();
                mBluetoothSocket = null;


            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }

        // 设置设备可以被搜索
        new Thread(){
            public void run(){
                if(mBluetoothAdapter.isEnabled()==false){
                    mBluetoothAdapter.enable();
                }
            }
        }.start();
    }


    //接收活动结果，响应startActivityForResult()
    @SuppressLint("MissingPermission")
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (requestCode) {
            case 1:     //连接结果，由DeviceListActivity设置返回
                // 响应返回结果
                if (resultCode == Activity.RESULT_OK)
                {   //连接成功，由DeviceListActivity设置返回
                    // MAC地址，由DeviceListActivity设置返回
                    String address = data.getExtras().getString(DevicesList.EXTRA_DEVICE_ADDRESS);
                    System.out.println("连接蓝牙成功");
                    // 得到蓝牙设备句柄
                    mBluetoothDevice = mBluetoothAdapter.getRemoteDevice("A1:E4:2B:11:7B:B6");

                    // 用服务号得到socket
                    try {
                        mBluetoothSocket = mBluetoothDevice.createRfcommSocketToServiceRecord(UUID.fromString(MY_UUID));
                    } catch (IOException e) {
                        Toast.makeText(this, "连接失败！", Toast.LENGTH_SHORT).show();
                    }
                    //连接socket
                    Button connectButton = findViewById(R.id.connectButton);
                    try {
                        mBluetoothSocket.connect();
                        Toast.makeText(this, "连接" + mBluetoothDevice.getName() + "成功！", Toast.LENGTH_SHORT).show();
                        connectButton.setText("断开");
                    } catch (IOException e) {
                        try {
                            Toast.makeText(this, "连接失败！", Toast.LENGTH_SHORT).show();
                            mBluetoothSocket.close();
                            mBluetoothSocket = null;
                        } catch (IOException ee) {
                            Toast.makeText(this, "连接失败！", Toast.LENGTH_SHORT).show();
                        }

                        return;
                    }

                    //打开接收线程
                    try {
                        is = mBluetoothSocket.getInputStream();   //得到蓝牙数据输入流
                    } catch (IOException e) {
                        Toast.makeText(this, "接收数据失败！", Toast.LENGTH_SHORT).show();
                        return;
                    }
                    if (bThread == false) {
                        readThread.start();
                        bThread = true;
                    } else {
                        bRun = true;
                    }
                }
                break;
            default:
                break;
        }
    }

    //接收数据线程
    Thread readThread=new Thread(){

        public void run(){
            int num = 0;
            byte[] buffer = new byte[320];
            byte[] buffer_new = new byte[1024];
            int i = 0;
            int n = 0;
            bRun = true;
            //接收线程
            while(true){
                try{
                    sleep(1000);
                    while(is.available()==0){
                        while(bRun == false){}
                    }
                    while(true){
                        if(!bThread)//跳出循环
                            return;
                        num = is.read(buffer);         //读入数据
                        n=0;
                        String s0 = new String(buffer,0,num);
                        if(s0.equals(last))//如果和上一次相同，则不播报
                        {
                        }
                        else                //和上一次不同，播报
                        {
                            if(cnt_int==1)
                            {
                                mytts.mySpeak(s0);
                                cnt_int=2;
                            }
                            else{
                                String Object=s0.substring(10,12);
                                String weizhi=s0.substring(0,2);
                                if(Object.equals("椅子")||Object.equals("瓶子"))
                                {
                                    objwhere=Object+"在您的"+weizhi+"方";
                                } else if (Object.equals("绿灯"))
                                {
                                    String sspeak="前方"+Object+",请快速通过";
                                    mytts.mySpeak(sspeak);
                                } else if(Object.equals("红灯"))
                                {
                                    String sspeak="前方"+Object+",请等待";
                                    mytts.mySpeak(sspeak);
                                }
                                else
                                {
                                    mytts.mySpeak(s0);
                                }
                                last=s0;
                            }

                        }
                        System.out.println(s0);
                        for(i=0;i<num;i++){
                            if((buffer[i] == 0x0d)&&(buffer[i+1]==0x0a)){
                                buffer_new[n] = 0x0a;
                                i++;
                            }else{
                                buffer_new[n] = buffer[i];
                            }
                            n++;
                        }
                        String s = new String(buffer_new,0,n);
                        smsg+=s;   //写入接收缓存
                        if(is.available()==0)break;  //短时间没有数据才跳出进行显示
                    }
                    //发送显示消息，进行显示刷新
                    handler.sendMessage(handler.obtainMessage());
                }catch(IOException e){
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    };

    //消息处理队列
    Handler handler= new Handler(){
        public void handleMessage(Message msg){
            super.handleMessage(msg);


        }
    };

    //关闭程序掉用处理部分
    public void onDestroy(){
        super.onDestroy();
        if(mBluetoothSocket!=null)  //关闭连接socket
            try{
                mBluetoothSocket.close();
            }catch(IOException e){}
        //	_bluetooth.disable();  //关闭蓝牙服务
    }

    public static String getwhere()
    {
        return objwhere;
    }
}
