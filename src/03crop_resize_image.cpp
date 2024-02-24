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
    Mat imgResize,imgCrop;
    //read image
    String path = "E:/parth/OpencvCpp/resources/hp.jpg";
    Mat image = imread(path);

    //check if image is empty
    if (image.empty()) {
        cout << "No image data" << endl;
        return -1;
    }

    //resize image by width and height
    resize(image, imgResize, Size(200,200));

    //image resize by scaling
    resize(image, imgResize, Size(), 0.5 , 0.5);

    //croping image - ROI- region of interest
    //Rect roi(x, y, w, h);
    // x-coordinate of the top-left corner
    // y-coordinate of the top-left corner
    // Width: 300 units
    // Height: 250 units

    Rect roi(100,40,250,250);
    imgCrop = image(roi);

    //display image
    imshow("Display Image", image);
    // imshow("resize Image", imgResize);
    imshow("imgCrop", imgCrop);
    waitKey(0);
    return 0;
}


