#ifndef TRAFFICSIGNDETECTORINTERFACE_H_
#define TRAFFICSIGNDETECTORINTERFACE_H_

#include <opencv2/core/core.hpp>

#include <vector>

class TrafficSignDetectorInterface
{
public:
	virtual ~TrafficSignDetectorInterface() {};

	virtual void process( cv::Mat image, std::vector< cv::Rect >& RectSigns  ) = 0;
};

#endif
