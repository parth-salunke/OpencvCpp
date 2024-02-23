#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

    String  path ="E:/parth/OpencvCpp/resources/lena.png";
    Mat img = imread(path);
    if (img.empty()) {
        cout << "No image data" << endl;
        return -1;
    }

    Mat imgGray, imgBlur, imgCanny, imgDia, imgEro;

    /// image BGR to Gray
    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    /// Gaussian Blur 
    GaussianBlur(img, imgBlur, Size(7,7) , 5 , 0 );

    /// Cannny edge detector , in canny edge detector we use little bit of gaussian blur 
    Canny(imgBlur, imgCanny, 50,150 );

    /// dialate image - it will increase thickness of detected edges from canny
    Mat kernel =getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDia, kernel );

    //Erode will reduce thickness of edges
    erode(imgDia, imgEro,kernel);


    imshow("img" , img);
    imshow("imgBlur" , imgBlur);
    imshow("imgGray" , imgCanny);
    imshow("imgDia" , imgDia);
    imshow("imgEro" , imgEro);
    waitKey(0);

}
