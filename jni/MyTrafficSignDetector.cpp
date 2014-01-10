#include "MyTrafficSignDetector.h"

#include <android/log.h>

#define LOG_TAG "NativeTrafficSignDetector"
#define LOGD(...) ( (void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__) )

MyTrafficSignDetector::MyTrafficSignDetector( )
{

}

void MyTrafficSignDetector::process( cv::Mat rgba_base_image, std::vector< cv::Rect >& RectSigns )
{
	RectSigns.push_back( cv::Rect(0,0,8,8) );
}

MyTrafficSignDetector::~MyTrafficSignDetector( )
{

}
