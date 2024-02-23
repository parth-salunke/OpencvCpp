#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

// for Image ////
int main()
{
    String path = "E:/parth/opencvproject/Resources/lena.png";
    Mat image = imread(path);
    if (image.empty()) {
        cout << "No image data" << endl;
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}


// for video ////

int main()
{
    String path = "E:/parth/opencvproject/Resources/test_video.mp4";

    VideoCapture cap(path);
    Mat image;

    while(true){
        cap.read(image);
        imshow("Display Image", image);
        waitKey(1);
    }

}

// for web cam ////

int main()
{
    VideoCapture cap(0);
    Mat image;

    while(true){
        cap.read(image);
        imshow("Display Image", image);
        waitKey(1);
    }

}
