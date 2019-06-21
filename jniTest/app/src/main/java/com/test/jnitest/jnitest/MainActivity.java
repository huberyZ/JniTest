package com.test.jnitest.jnitest;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

    public static final String LOG = "JNITEST";
    private native void encryption(byte[] srcByte, int srcLength, byte[] enByte);
    static {
        System.loadLibrary("power");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = findViewById(R.id.mButton);
        final String buf = "abcd";
        final byte[] srcByteArray = buf.getBytes();
        final byte[] enByteArray = new byte[buf.length()];
        String sBuf = new String(srcByteArray);
        Log.i(LOG, "buf:" + sBuf + " length: " + buf.length());

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.i(LOG, "begin test jni");
                encryption(srcByteArray, buf.length(), enByteArray);
                Log.i(LOG, "test jni end: byteArray:" + new String(enByteArray));
            }
        });
    }
}
