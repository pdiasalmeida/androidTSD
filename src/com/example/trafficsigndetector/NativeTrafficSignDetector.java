package com.example.trafficsigndetector;

import org.opencv.core.Mat;
import org.opencv.core.MatOfRect;

public class NativeTrafficSignDetector
{
	private long mNativeObj = 0;

	public NativeTrafficSignDetector()
	{
		mNativeObj = nativeCreateObject();
	}

	public void detect(Mat image, MatOfRect signs)
	{
        nativeDetect( mNativeObj, image.getNativeObjAddr(), signs.getNativeObjAddr() );
    }
	
	public void release()
	{
        nativeDestroyObject( mNativeObj );
        mNativeObj = 0;
    }

    private static native long nativeCreateObject();
    private static native long nativeDestroyObject( long thiz );
    
    private static native void nativeDetect( long thiz, long inputImage, long signs );

}
