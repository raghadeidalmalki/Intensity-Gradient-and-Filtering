#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void magnitudeSobel()
{
    // load image from file
    cv::Mat img;
    img = cv::imread("./images/img1gray.png");

    // convert image to grayscale
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    // apply smoothing using the GaussianBlur() function from the OpenCV
    // ToDo : Add your code here

    // create filter kernels using the cv::Mat datatype both for x and y
    // ToDo : Add your code here

    // apply filter using the OpenCv function filter2D()
    // ToDo : Add your code here
    

    // compute magnitude image based on the equation presented in the lesson 
    // ToDo : Add your code here
    
  
      // Apply Gaussian smoothing using GaussianBlur()
    cv::Mat imgBlurred;
    cv::GaussianBlur(imgGray, imgBlurred, cv::Size(5, 5), 2.0, 2.0);

    // Define Sobel filter kernels for x and y gradients
    cv::Mat sobelX = (cv::Mat_<float>(3, 3) <<
        -1, 0, 1,
        -2, 0, 2,
        -1, 0, 1);

    cv::Mat sobelY = (cv::Mat_<float>(3, 3) <<
        -1, -2, -1,
        0,  0,  0,
        1,  2,  1);

    // Apply the Sobel filters using filter2D()
    cv::Mat gradX, gradY;
    cv::filter2D(imgBlurred, gradX, CV_32F, sobelX);
    cv::filter2D(imgBlurred, gradY, CV_32F, sobelY);

    // Compute the magnitude image using the gradient magnitude formula
    cv::Mat magnitude;
    cv::magnitude(gradX, gradY, magnitude);

    // Normalize the magnitude image to the range [0, 255] and convert to 8-bit
    cv::Mat magnitudeDisplay;
    magnitude.convertTo(magnitudeDisplay, CV_8U, 255.0 / 	cv::norm(magnitude, cv::NORM_INF));
  
  
  

    // show result
    string windowName = "Gaussian Blurring";
    cv::namedWindow(windowName, 1); // create window
    cv::imshow(windowName, magnitude);
    cv::waitKey(0); // wait for keyboard input before continuing
}

int main()
{
    magnitudeSobel();
}
