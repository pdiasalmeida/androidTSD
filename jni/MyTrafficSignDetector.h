#ifndef MYTRAFFICSIGNDETECTOR_H_
#define MYTRAFFICSIGNDETECTOR_H_

#include "TrafficSignDetectorInterface.h"

#include <opencv2/core/core.hpp>

#include <vector>

class MyTrafficSignDetector : public TrafficSignDetectorInterface
{
public:
	MyTrafficSignDetector();
	~MyTrafficSignDetector();

	virtual void process( cv::Mat image, std::vector< cv::Rect >& RectSigns  );
};

#endif
