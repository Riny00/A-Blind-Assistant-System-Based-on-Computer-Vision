package com.llw.mapdemo.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.llw.mapdemo.R;

public class login extends AppCompatActivity {

    private EditText etAccount;
    private EditText etpwd;
    private Button btnlogin2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        etAccount=findViewById(R.id.et_account);
        etpwd=findViewById(R.id.et_pwd);
        btnlogin2=findViewById(R.id.btn_login2);

        btnlogin2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String account=etAccount.getText().toString().trim();//获取输入
                String pwd=etpwd.getText().toString().trim();//获取输入
                login(account,pwd);

            }
        });
    }

    private void login(String accout,String pwd)
    {
//        if((accout==null||accout.length()<=0)||(pwd==null||pwd.length()<=0))
//        {
//            Toast.makeText(this,"请输入账号或密码",Toast.LENGTH_SHORT).show();
//            return;
//        }

        //获取数据库

        //跳转
        Intent in =new Intent(login.this, Home.class);
        startActivity(in);
    }
}