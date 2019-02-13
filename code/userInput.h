#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
// C++ std library dependencies
#include <chrono> // `std::chrono::` functions and classes, e.g. std::chrono::milliseconds
#include <thread> // std::this_thread
// Other 3rdparty dependencies
// GFlags: DEFINE_bool, _int32, _int64, _uint64, _double, _string
#include <gflags/gflags.h>
// Allow Google Flags in Ubuntu 14
#ifndef GFLAGS_GFLAGS_H_
namespace gflags = google;
#endif

#include "Eigen/Dense"
// OpenPose dependencies
#include <openpose/headers.hpp>
//#include <opencv/highgui.h>

struct UserDatum : public op::Datum
{
	bool boolThatUserNeedsForSomeReason;

	UserDatum(const bool boolThatUserNeedsForSomeReason_ = false) :
		boolThatUserNeedsForSomeReason{ boolThatUserNeedsForSomeReason_ }
	{}
};

class userInput
{
public:
	userInput();
	~userInput();
	bool display(const std::shared_ptr<std::vector<UserDatum>>& datumsPtr);
	void printKeypoints(const std::shared_ptr<std::vector<UserDatum>>& datumsPtr);
};

