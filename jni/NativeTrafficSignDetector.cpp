#include <NativeTrafficSignDetector_jni.h>
#include <TrafficSignDetectorInterface.h>
#include <MyTrafficSignDetector.h>

#include <android/log.h>

#define LOG_TAG "NativeTrafficSignDetector"
#define LOGD(...) ( (void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__) )

inline void vector_Rect_to_Mat( std::vector< cv::Rect >& v_rect, cv::Mat& mat )
{
    mat = cv::Mat( v_rect, true );
}

JNIEXPORT jlong JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeCreateObject
( JNIEnv * jenv, jclass )
{
	LOGD("Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeCreateObject enter");

	jlong result = 0;
	try
	{
		result = (jlong) new MyTrafficSignDetector();
	}
	catch(cv::Exception& e)
	{
		LOGD( "nativeCreateObject caught cv::Exception: %s", e.what() );
		jclass je = jenv->FindClass("org/opencv/core/CvException");
		if(!je)
			je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew( je, e.what() );
	}
	catch (...)
	{
		LOGD( "nativeCreateObject caught unknown exception" );
		jclass je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew( je, "Unknown exception in JNI code {NativeTrafficSignDetector::nativeCreateObject()}" );
		return 0;
	}

	LOGD( "Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeCreateObject exit" );

	return result;
}

JNIEXPORT void JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDestroyObject
( JNIEnv * jenv, jclass, jlong thiz )
{
	LOGD( "Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDestroyObject enter" );
	try
	{
		if( thiz != 0 )
		{
			delete (TrafficSignDetectorInterface*)thiz;
		}
	}
	catch(cv::Exception& e)
	{
		LOGD( "nativeestroyObject caught cv::Exception: %s", e.what() );
		jclass je = jenv->FindClass("org/opencv/core/CvException");
		if(!je)
			je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew(je, e.what());
	}
	catch (...)
	{
		LOGD( "nativeDestroyObject caught unknown exception" );
		jclass je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew(je, "Unknown exception in JNI code {{NativeTrafficSignDetector::nativeCreateObject()}");
	}

	LOGD( "Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDestroyObject exit" );
}

JNIEXPORT void JNICALL Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDetect
( JNIEnv * jenv, jclass, jlong thiz, jlong image, jlong signs )
{
	LOGD( "Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDetect enter" );
	try
	{
		std::vector< cv::Rect > RectSigns;
		((TrafficSignDetectorInterface*)thiz)->process( *((cv::Mat*)image), RectSigns );
		vector_Rect_to_Mat( RectSigns, *((cv::Mat*)signs) );
	}
	catch(cv::Exception& e)
	{
		LOGD("nativeCreateObject caught cv::Exception: %s", e.what());
		jclass je = jenv->FindClass("org/opencv/core/CvException");
		if(!je)
			je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew(je, e.what());
	}
	catch (...)
	{
		LOGD("nativeDetect caught unknown exception");
		jclass je = jenv->FindClass("java/lang/Exception");
		jenv->ThrowNew(je, "Unknown exception in JNI code {NativeTrafficSignDetector::nativeCreateObject()}");
	}
	LOGD("Java_com_example_trafficsigndetector_NativeTrafficSignDetector_nativeDetect exit");
}
