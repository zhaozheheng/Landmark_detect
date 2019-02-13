#include "LMdetect.h"

int main(int argc, char *argv[])
{
	LMdetector lm;
	// Parsing command line flags
	// gflags::ParseCommandLineFlags(&argc, &argv, true);

	std::vector<std::vector<Eigen::Vector2f>> landmarks;

	// Running openPoseTutorialWrapper1
	lm.openPoseTutorialWrapper1(landmarks);
	//std::cout << landmarks.size() << std::endl;
	for (int i = 0; i < landmarks.size(); ++i)
	{
		for (int j = 0; j < landmarks[i].size(); ++j)
		{
			std::cout << landmarks[i][j](0) << "\t" << landmarks[i][j](1) << std::endl;
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
