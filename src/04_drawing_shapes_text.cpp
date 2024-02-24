#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main(){

    //bank image  BGR  Blue =255 0 0 
    // white frame 255,255,255
    Mat img(512,512, CV_8UC3, Scalar(255,255,255));

    //circle with thickness 10
    circle(img, Point(255,255), 200, Scalar(0,0,0),10);
    //cicle with filled
    circle(img, Point(255,255), 200, Scalar(0,0,0), FILLED);

    //rectangle 
    // here we are using Point topleft(x, y) and bottom right(x,y)
    rectangle(img, Point(130,226),Point(382,286) , Scalar(255,255,255) , 10);
    //we can also use Rec
    Rect rect(130,226,100,100);
    rectangle(img, rect , Scalar(255,255,255) , 10);

    //drawing line  start (x,y) ad end(x,y)
    line(img,Point(130,226),Point(382,286) , Scalar(0,255,255) , 10);

    //display text
    putText(img, "hello parth" , Point(10,10), FONT_HERSHEY_DUPLEX, 0.5,Scalar(0,0,255),1);

    imshow("img" , img);
    waitKey(0);

}