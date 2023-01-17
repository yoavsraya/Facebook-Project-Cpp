#include "VideoStatus.h"

VideoStatus::VideoStatus(string content, string dataName)
{
	setIndex(VIDEO);
	setName(content);
	VideoFileName.erase();
	VideoFileName += dataName;
	setTime();
}

string VideoStatus::getDataFileName()
{
	return VideoFileName;
}

void VideoStatus::printContent() const
{
	cout <<"\033[1;31m";
	cout << getContent() << endl;
	cout << "upload time and date: " << getTime() << endl;
	system(VideoFileName.c_str());
	cout << "------------------------------" << endl;
	cout << "\033[0m";
}
