package com.llw.mapdemo;

import static android.speech.tts.TextToSpeech.SUCCESS;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.speech.tts.UtteranceProgressListener;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.llw.mapdemo.activity.login;
import com.llw.mapdemo.activity.register;

import java.util.HashMap;
import java.util.Locale;
import java.util.Random;

import com.llw.mapdemo.activity.BlueTooth_Recv;

public class MainActivity extends AppCompatActivity{

    //****************文字转语音****************
    public TextToSpeech tts;
    private HashMap<String, String> params;
    private String mostRecentUtteranceID;
    //*****************************************

    public BlueTooth_Recv recv;

    private Button btnLogin;
    private Button btnRegister;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recv= new BlueTooth_Recv();                         //创建蓝牙接收对象
        recv.init(getApplicationContext());                //蓝牙连接初始化


        btnLogin=findViewById(R.id.btn_login);
        btnRegister=findViewById(R.id.btn_register);

        //send("A1:E4:2B:11:7B:B6","nh123456789".getBytes());

        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent in =new Intent(MainActivity.this, login.class);
                startActivity(in);
            }
        });

        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent in =new Intent(MainActivity.this, register.class);
                startActivity(in);
            }
        });
    }
}
