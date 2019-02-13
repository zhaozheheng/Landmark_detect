#include "userInput.h"



userInput::userInput()
{
}


userInput::~userInput()
{
}

bool userInput::display(const std::shared_ptr<std::vector<UserDatum>>& datumsPtr)
{
	// User's displaying/saving/other processing here
	// datum.cvOutputData: rendered frame with pose or heatmaps
	// datum.poseKeypoints: Array<float> with the estimated pose
	char key = ' ';
	if (datumsPtr != nullptr && !datumsPtr->empty())
	{
		cv::imshow("User worker GUI", datumsPtr->at(0).cvOutputData);
		// Display image and sleeps at least 1 ms (it usually sleeps ~5-10 msec to display the image)
		key = (char)cv::waitKey(1);
	}
	else
		op::log("Nullptr or empty datumsPtr found.", op::Priority::High, __LINE__, __FUNCTION__, __FILE__);
	return (key == 27);
}

void userInput::printKeypoints(const std::shared_ptr<std::vector<UserDatum>>& datumsPtr)
{
	// Example: How to use the pose keypoints
	if (datumsPtr != nullptr && !datumsPtr->empty())
	{
		op::log("\nKeypoints:");
		// Accesing each element of the keypoints
		const auto& poseKeypoints = datumsPtr->at(0).poseKeypoints;
		op::log("Person pose keypoints:");
		for (auto person = 0; person < poseKeypoints.getSize(0); person++)
		{
			op::log("Person " + std::to_string(person) + " (x, y, score):");
			for (auto bodyPart = 0; bodyPart < poseKeypoints.getSize(1); bodyPart++)
			{
				std::string valueToPrint;
				for (auto xyscore = 0; xyscore < poseKeypoints.getSize(2); xyscore++)
				{
					valueToPrint += std::to_string(poseKeypoints[{person, bodyPart, xyscore}]) + " ";
				}
				op::log(valueToPrint);
			}
		}
		op::log(" ");
		// Alternative: just getting std::string equivalent
		op::log("Face keypoints: " + datumsPtr->at(0).faceKeypoints.toString());
		op::log("Left hand keypoints: " + datumsPtr->at(0).handKeypoints[0].toString());
		op::log("Right hand keypoints: " + datumsPtr->at(0).handKeypoints[1].toString());
		// Heatmaps
		const auto& poseHeatMaps = datumsPtr->at(0).poseHeatMaps;
		if (!poseHeatMaps.empty())
		{
			op::log("Pose heatmaps size: [" + std::to_string(poseHeatMaps.getSize(0)) + ", "
				+ std::to_string(poseHeatMaps.getSize(1)) + ", "
				+ std::to_string(poseHeatMaps.getSize(2)) + "]");
			const auto& faceHeatMaps = datumsPtr->at(0).faceHeatMaps;
			op::log("Face heatmaps size: [" + std::to_string(faceHeatMaps.getSize(0)) + ", "
				+ std::to_string(faceHeatMaps.getSize(1)) + ", "
				+ std::to_string(faceHeatMaps.getSize(2)) + ", "
				+ std::to_string(faceHeatMaps.getSize(3)) + "]");
			const auto& handHeatMaps = datumsPtr->at(0).handHeatMaps;
			op::log("Left hand heatmaps size: [" + std::to_string(handHeatMaps[0].getSize(0)) + ", "
				+ std::to_string(handHeatMaps[0].getSize(1)) + ", "
				+ std::to_string(handHeatMaps[0].getSize(2)) + ", "
				+ std::to_string(handHeatMaps[0].getSize(3)) + "]");
			op::log("Right hand heatmaps size: [" + std::to_string(handHeatMaps[1].getSize(0)) + ", "
				+ std::to_string(handHeatMaps[1].getSize(1)) + ", "
				+ std::to_string(handHeatMaps[1].getSize(2)) + ", "
				+ std::to_string(handHeatMaps[1].getSize(3)) + "]");
		}
	}
	else
		op::log("Nullptr or empty datumsPtr found.", op::Priority::High, __LINE__, __FUNCTION__, __FILE__);
}
