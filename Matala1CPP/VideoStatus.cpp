#include "VideoStatus.h"

void VideoStatus::printVideoStatus() const
{
	printContent();
	const char* fileName = VideoFileName.c_str();
	system(fileName);
	cout << endl;
}
