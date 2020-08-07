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
    Mat img3,img5,img7,img9;
    Mat temp3,temp5,temp7,temp9;
    Mat out,out3,out5,out7,out9;
    Mat temp_thresh3,temp_thresh5,temp_thresh7,temp_thresh9;
    Mat max1,max2;

    int lmin3=3;

    Mat mask3i=Mat::ones(lmin3,lmin3, CV_8UC1);

    Mat mask3=Mat::zeros(2*lmin3+1,2*lmin3+1, CV_8UC1);
   mask3(Rect(0,0,1,1))=1;
   mask3(Rect(0,lmin3,1,1))=1;
   mask3(Rect(0,2*lmin3,1,1))=1;
   mask3(Rect(2*lmin3,0,1,1))=1;
   mask3(Rect(2*lmin3,lmin3,1,1))=1;
   mask3(Rect(2*lmin3,2*lmin3,1,1))=1;
   mask3(Rect(lmin3,0,1,1))=1;
   mask3(Rect(lmin3,2*lmin3,1,1))=1;


   int lmin5=5;

   Mat mask5i=Mat::ones(lmin5,lmin5, CV_8UC1);

   Mat mask5=Mat::zeros(2*lmin5+1,2*lmin5+1, CV_8UC1);
  mask5(Rect(0,0,1,1))=1;
  mask5(Rect(0,lmin5,1,1))=1;
  mask5(Rect(0,2*lmin5,1,1))=1;
  mask5(Rect(2*lmin5,0,1,1))=1;
  mask5(Rect(2*lmin5,lmin5,1,1))=1;
  mask5(Rect(2*lmin5,2*lmin5,1,1))=1;
  mask5(Rect(lmin5,0,1,1))=1;
  mask5(Rect(lmin5,2*lmin5,1,1))=1;

  int lmin7=7;

  Mat mask7i=Mat::ones(lmin7,lmin7, CV_8UC1);

  Mat mask7=Mat::zeros(2*lmin7+1,2*lmin7+1, CV_8UC1);
 mask7(Rect(0,0,1,1))=1;
 mask7(Rect(0,lmin7,1,1))=1;
 mask7(Rect(0,2*lmin7,1,1))=1;
 mask7(Rect(2*lmin7,0,1,1))=1;
 mask7(Rect(2*lmin7,lmin7,1,1))=1;
 mask7(Rect(2*lmin7,2*lmin7,1,1))=1;
 mask7(Rect(lmin7,0,1,1))=1;
 mask7(Rect(lmin7,2*lmin7,1,1))=1;

 int lmin9=9;

 Mat mask9i=Mat::ones(lmin9,lmin9, CV_8UC1);

 Mat mask9=Mat::zeros(2*lmin9+1,2*lmin9+1, CV_8UC1);
mask9(Rect(0,0,1,1))=1;
mask9(Rect(0,lmin9,1,1))=1;
mask9(Rect(0,2*lmin9,1,1))=1;
mask9(Rect(2*lmin9,0,1,1))=1;
mask9(Rect(2*lmin9,lmin9,1,1))=1;
mask9(Rect(2*lmin9,2*lmin9,1,1))=1;
mask9(Rect(lmin9,0,1,1))=1;
mask9(Rect(lmin9,2*lmin9,1,1))=1;

    filter2D(image, img3, -1, mask3i, anchor,delta, BORDER_REPLICATE);
    filter2D(image, img5, -1, mask5i, anchor,delta, BORDER_REPLICATE);
    filter2D(image, img7, -1, mask7i, anchor,delta, BORDER_REPLICATE);
    filter2D(image, img9, -1, mask9i, anchor,delta, BORDER_REPLICATE);

    dilate( img3, temp3, mask3, Point(-1,-1), 1, BORDER_REPLICATE);
    dilate( img5, temp5, mask5, Point(-1,-1), 1, BORDER_REPLICATE);
    dilate( img7, temp7, mask7, Point(-1,-1), 1, BORDER_REPLICATE);
    dilate( img9, temp9, mask9, Point(-1,-1), 1, BORDER_REPLICATE);

    out3=img3-temp3;
    threshold(out3, temp_thresh3 , 0,1, THRESH_TOZERO );
    pow(temp_thresh3,2,out3);

    out5=img5-temp5;
    threshold(out5, temp_thresh5 , 0,1, THRESH_TOZERO );
    pow(temp_thresh5,2,out5);

    out7=img7-temp7;
    threshold(out7, temp_thresh7 , 0,1, THRESH_TOZERO );
    pow(temp_thresh7,2,out7);

    out9=img9-temp9;
    threshold(out9, temp_thresh9 , 0,1, THRESH_TOZERO );
    pow(temp_thresh9,2,out9);

    max(out3,out5,max1);
    max(max1,out7,max2);
    max(max2,out9,out);

    imshow("output image3", mat2gray(out3));
    imshow("output image5", mat2gray(out5));
    imshow("output image7", mat2gray(out7));
    imshow("output image9", mat2gray(out9));
    imshow("output image", mat2gray(out));





    cv::waitKey(0);
    return EXIT_SUCCESS;
}
