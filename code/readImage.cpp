//code copied from https://help.ubuntu.com/community/OpenCV
//testing to see if OpenCV library functions
//Libraries were pasted as instructed to from OpenCV tutorial
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/core/core_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
using namespace cv;

class Image{
 public:
 private:
	int width;
	int height;
//	int imageRGB[height][width][3];
};


int main(){
	int i, j;
	Mat image = imread("flower.jpg", CV_LOAD_IMAGE_COLOR); // reads in image into image object from the Matrix? class, not sure what CV_LO... is
	std::cout << "The height of flower.jpg is " << image.rows << std::endl;
	std::cout << "The width of flower.jpg is " << image.cols << std::endl;
	int imageRGB[image.rows][image.cols][3]; // 3-d matrix: stores the BGR values of the image
	//populate imageRGB matrix with rgb values of the image, now that i think about it, this is unnessesary since OpenCV already has the values stored which we can access at any time, I leave it for now just in case this is more intuitive
	for(i = 0; i < image.rows; i++){
		for(j = 0; j < image.cols; j++){
			// OpenCV stores the values in bgr order instead of rgb
			imageRGB[i][j][0] = image.at<Vec3b>(i, j)[0];
			imageRGB[i][j][1] = image.at<Vec3b>(i, j)[1];
			imageRGB[i][j][2] = image.at<Vec3b>(i, j)[2];
		}
	}
	imshow("opencvtest", image); // displays the image with title opencvtest
	waitKey(0); // not sure what this does
	return 0;
}

//Mat is matrix? i think img.rows and img.cols gives size.
