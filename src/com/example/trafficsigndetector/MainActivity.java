package com.example.trafficsigndetector;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfRect;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.WindowManager;

public class MainActivity extends Activity implements CvCameraViewListener2
{
    private static final String TAG = "TrafficSignDetector::MainActivity";
    private static final Scalar SIGN_RECT_COLOR = new Scalar(255, 0, 0, 255);

    private Mat mRgba;
    private Mat mGray;
    
    private NativeTrafficSignDetector mNativeDetector;    
	private CameraBridgeViewBase mOpenCvCameraView;

    private BaseLoaderCallback  mLoaderCallback = new BaseLoaderCallback(this) {
    	@Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    Log.i(TAG, "OpenCV loaded successfully");

                    // Load native library after(!) OpenCV initialization
                    System.loadLibrary("traffic_sign_detector");

                    mNativeDetector = new NativeTrafficSignDetector();
                    
                    mOpenCvCameraView.enableView();
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        Log.i(TAG, "called onCreate");
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        setContentView(R.layout.activity_main);

        mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.main_activity_surface_view);
        mOpenCvCameraView.setCvCameraViewListener(this);
    }

    @Override
    public void onPause()
    {
        super.onPause();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }

    @Override
    public void onResume()
    {
        super.onResume();
        OpenCVLoader.initAsync( OpenCVLoader.OPENCV_VERSION_2_4_6, this, mLoaderCallback );
    }

    public void onDestroy()
    {
        super.onDestroy();
        mOpenCvCameraView.disableView();
    }

    public void onCameraViewStarted( int width, int height )
    {
        mGray = new Mat();
        mRgba = new Mat();
    }

    public void onCameraViewStopped()
    {
        mGray.release();
        mRgba.release();
    }

    public Mat onCameraFrame( CvCameraViewFrame inputFrame )
    {
        mRgba = inputFrame.rgba();
        //mGray = inputFrame.gray();

        MatOfRect signs = new MatOfRect();
        if( mNativeDetector != null )
        {
        	mNativeDetector.detect( mRgba, signs );
        }
        
        Rect[] signsArray = signs.toArray();
        for( int i = 0; i < signsArray.length; i++ )
        {
            Core.rectangle( mRgba, signsArray[i].tl(), signsArray[i].br(), SIGN_RECT_COLOR, 3 );
        }

        return mRgba;
    }

    @Override
    public boolean onCreateOptionsMenu( Menu menu )
    {
        return true;
    }

    @Override
    public boolean onOptionsItemSelected( MenuItem item )
    {
        return true;
    }

}
