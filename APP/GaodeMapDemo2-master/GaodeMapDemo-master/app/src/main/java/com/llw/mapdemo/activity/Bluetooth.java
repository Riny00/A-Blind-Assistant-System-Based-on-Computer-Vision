package com.llw.mapdemo.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import com.llw.mapdemo.R;
import com.llw.mapdemo.util.DevicesList;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

public class Bluetooth extends AppCompatActivity {

    private final static String MY_UUID = "00001101-0000-1000-8000-00805F9B34FB";   //SPP服务UUID号
    private BluetoothAdapter mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter(); //获取蓝牙实例

    private EditText sendEditText; //创建发送 句柄
    private TextView tv_in; //接收显示句柄
    private ScrollView scrollView; //翻页句柄
    private String smsg = ""; //显示用数据缓存

    BluetoothDevice mBluetoothDevice = null; //蓝牙设备
    BluetoothSocket mBluetoothSocket = null; //蓝牙通信Socket

    boolean bRun = true; //运行状态
    boolean bThread = false; //读取线程状态
    private InputStream is;    //输入流，用来接收蓝牙数据

    @SuppressLint("MissingPermission")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bluetooth);

        System.out.println("*******************执行到这1*******************");

        //获取控件ID
        sendEditText = findViewById(R.id.sendEditText);
        scrollView = findViewById(R.id.receiveScrolView);
        tv_in = findViewById(R.id.in);

        //如果打不开蓝牙提示信息，结束程序
        if (mBluetoothAdapter == null){
            Toast.makeText(getApplicationContext(),"无法打开手机蓝牙，请确认手机是否有蓝牙功能！",Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        //连接按钮响应
        final Button connectButton = findViewById(R.id.connectButton);

        if (mBluetoothAdapter.isEnabled() == false) {
            Toast.makeText(getApplicationContext(), " 请先打开蓝牙", Toast.LENGTH_LONG).show();
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
                Toast.makeText(this, "连接失败！", Toast.LENGTH_SHORT).show();
            }

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


        } else {
            //关闭连接socket
            try {
                bRun = false;
                Thread.sleep(2000);

                is.close();
                mBluetoothSocket.close();
                mBluetoothSocket = null;

                connectButton.setText("连接");
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
        System.out.println("*******************执行到这2*******************");

        //发送按钮响应
        Button sendButton = (Button) findViewById(R.id.sendButton);
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                System.out.println("*******************执行到这3*******************");

                int n = 0;
                if (mBluetoothSocket == null) {
                    Toast.makeText(getApplicationContext(), "请先连接设备", Toast.LENGTH_SHORT).show();
                    return;
                }
                if (sendEditText.getText().length() == 0) {
                    Toast.makeText(getApplicationContext(), "请先输入数据", Toast.LENGTH_SHORT).show();
                    return;
                }
                try {

                    OutputStream os = mBluetoothSocket.getOutputStream();   //蓝牙连接输出流
                    byte[] bos = sendEditText.getText().toString().getBytes();
                    for (int i = 0; i < bos.length; i++) {
                        if (bos[i] == 0x0a) n++;
                    }
                    byte[] bos_new = new byte[bos.length + n];
                    n = 0;
                    for (int i = 0; i < bos.length; i++) { //手机中换行为0a,将其改为0d 0a后再发送
                        if (bos[i] == 0x0a) {
                            bos_new[n] = 0x0d;
                            n++;
                            bos_new[n] = 0x0a;
                        } else {
                            bos_new[n] = bos[i];
                        }
                        n++;
                    }

                    os.write(bos_new);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });


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
                if (resultCode == Activity.RESULT_OK) {   //连接成功，由DeviceListActivity设置返回
                    // MAC地址，由DeviceListActivity设置返回
                    String address = data.getExtras().getString(DevicesList.EXTRA_DEVICE_ADDRESS);
                    System.out.println("address:"+address);
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
            byte[] buffer = new byte[1024];
            byte[] buffer_new = new byte[1024];
            int i = 0;
            int n = 0;
            bRun = true;
            //接收线程
            while(true){
                try{
                    while(is.available()==0){
                        while(bRun == false){}
                    }
                    while(true){
                        if(!bThread)//跳出循环
                            return;

                        num = is.read(buffer);         //读入数据
                        n=0;

                        String s0 = new String(buffer,0,num);
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
                }
            }
        }
    };

    //消息处理队列
    Handler handler= new Handler(){
        public void handleMessage(Message msg){
            super.handleMessage(msg);
            tv_in.setText(smsg);   //显示数据
            scrollView.scrollTo(0,tv_in.getMeasuredHeight()); //跳至数据最后一页
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
}
