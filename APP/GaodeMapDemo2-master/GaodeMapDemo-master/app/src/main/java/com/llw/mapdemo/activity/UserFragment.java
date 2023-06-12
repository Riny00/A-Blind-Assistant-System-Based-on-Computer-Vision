package com.llw.mapdemo.activity;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.llw.mapdemo.R;

public class UserFragment extends Fragment {

    private Button btnSet;//跳转到蓝牙界面


    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState)
    {
        View root=inflater.inflate(R.layout.activity_user_fragment,container,false);


        return root;
    }
}