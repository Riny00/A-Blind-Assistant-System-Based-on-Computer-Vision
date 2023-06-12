package com.llw.mapdemo.util;

import android.speech.tts.TextToSpeech;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
public class Weather {

    public String weather_info() {
        String[] digit = new String[0];
        try {
            URL url = new URL("http://t.weather.itboy.net/api/weather/city/101190701");
            InputStreamReader isReader = new InputStreamReader(url.openStream(), "UTF-8");//“UTF- 8”万国码，可以显示中文，这是为了防止乱码
            BufferedReader br = new BufferedReader(isReader);//采用缓冲式读入
            String str;
            while ((str = br.readLine()) != null) {
                String regex = "\\p{Punct}+";
                digit = str.split(regex);
//                System.out.println('\n' + "城市:" + digit[22] + digit[18]);
//                System.out.println('\n' + "时间:" + digit[49] + "年" + digit[50] + "月" + digit[51] + "日" + digit[53]);
//                System.out.println('\n' + "温度:" + digit[47] + "~" + digit[45]);
//                System.out.println('\n' + "天气:" + digit[67] + " " + digit[63] + digit[65]);
//                System.out.println('\n' + "当前温度:" + digit[38]);
            }
            br.close();//网上资源使用结束后，数据流及时关闭
            isReader.close();
        } catch (Exception exp) {
            System.out.println(exp);
        }

        return "您好，查询到当前户外天气为" + digit[67]+",温度是"+digit[38]+"摄氏度,"+"阴晴之间，谨防紫外线侵扰";
    }

}
