#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat input = imread("filename.png", IMREAD_UNCHANGED);
	Mat output;

	int row = input.rows;
	int col = input.cols;

	output = Mat::zeros(row, col, input.type());

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Vec4b v = input.at<Vec4b>(i, j);

			output.at<Vec4b>(i, j)[0] = v[0];
			output.at<Vec4b>(i, j)[1] = v[1];
			output.at<Vec4b>(i, j)[2] = v[2];
			if (v[3] != 0) {
				output.at<Vec4b>(i, j)[3] = 255;
			} else {
				output.at<Vec4b>(i, j)[3] = 0;
			}
		}
	}
	imwrite("filename.png", output);
	waitKey(0);

	return 0;
}
