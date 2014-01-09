#include "MyTrafficSignDetector.h"

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
