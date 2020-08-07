#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
Mat mat2gray(const Mat& src)
{
    Mat dst;
    normalize(src, dst, 0.0, 1, NORM_MINMAX, CV_32FC1);
    return dst;
}
int main()
{

    Mat image;
    Mat img;

    img= imread("path to test image", 0);
    img.convertTo(image, CV_32FC1);
    imshow("original image", img);


    Point anchor;
    anchor = Point(-1, -1);


    double delta = 0;
    Mat img0;
    Mat temp1;
    Mat out;
    Mat temp_thresh;

    int lmin=7;

    Mat mask_i=Mat::ones(lmin,lmin, CV_8UC1);

    Mat mask_krl_dilate=Mat::zeros(2*lmin+1,2*lmin+1, CV_8UC1);
   mask_krl_dilate(Rect(0,0,1,1))=1;
   mask_krl_dilate(Rect(0,lmin,1,1))=1;
   mask_krl_dilate(Rect(0,2*lmin,1,1))=1;
   mask_krl_dilate(Rect(2*lmin,0,1,1))=1;
   mask_krl_dilate(Rect(2*lmin,lmin,1,1))=1;
   mask_krl_dilate(Rect(2*lmin,2*lmin,1,1))=1;
   mask_krl_dilate(Rect(lmin,0,1,1))=1;
   mask_krl_dilate(Rect(lmin,2*lmin,1,1))=1;




    filter2D(image, img0, -1, mask_i, anchor,delta, BORDER_REPLICATE);
    dilate( img0, temp1, mask_krl_dilate, Point(-1,-1), 1, BORDER_REPLICATE,  morphologyDefaultBorderValue());
    out=img0-temp1;
    threshold(out, temp_thresh , 0,1, THRESH_TOZERO );
    pow(temp_thresh,2,out);


    imshow("output image", mat2gray(out));




    cv::waitKey(0);
    return EXIT_SUCCESS;
}
