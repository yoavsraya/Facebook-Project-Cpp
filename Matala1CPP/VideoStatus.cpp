#include "VideoStatus.h"

void VideoStatus::printVideoStatus() const
{
	printContent();
	const char* fileName = VideoFileName.c_str();
	system(fileName);
	cout << endl;
}

VideoStatus::VideoStatus(string content, string dataName)
{
	setIndex(VIDEO);
	setName(content);
	VideoFileName = dataName;
	setTime();
}

string VideoStatus::getDataFileName()
{
	return VideoFileName;
}


