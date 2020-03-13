#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{VideoCapture cap(0);
	double scale = 1.5;
	//设定皮肤的颜色
	double i_minh = 0;
	double i_maxh = 20;
	//设定饱和度
	double i_mins = 43;
	double i_maxs = 255;
	//设定亮度
	double i_minv = 100;
	double i_maxv = 255;

	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;
		Size resimgsize = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(resimgsize, frame.type());
		resize(frame, rFrame, resimgsize, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		rFrame.copyTo(detectMat);
		inRange(hsvMat, Scalar(i_minh, i_mins, i_minv), Scalar(i_maxh, i_maxs, i_maxv), detectMat);
		imshow("while :in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(30);
	}

	return 0;

}


