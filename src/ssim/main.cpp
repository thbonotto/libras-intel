#include <opencv2/opencv.hpp>
#include <iostream>
#include "ssim.h"

/*#pragma comment(lib, "opencv_imgproc211.lib")
#pragma comment(lib, "opencv_video211.lib")
#pragma comment(lib, "opencv_ts211.lib")
#pragma comment(lib, "opencv_objdetect211.lib")
#pragma comment(lib, "opencv_ml211.lib")
#pragma comment(lib, "opencv_legacy211.lib")
#pragma comment(lib, "opencv_imgproc211.lib")
#pragma comment(lib, "opencv_highgui211.lib")
#pragma comment(lib, "opencv_haartraining_engine.lib")
#pragma comment(lib, "opencv_ffmpeg211.lib")
#pragma comment(lib, "opencv_features2d211.lib")
#pragma comment(lib, "opencv_core211.lib")
#pragma comment(lib, "opencv_contrib211.lib")
#pragma comment(lib, "opencv_calib3d211.lib")
*/

void ssim_test()
{
	cv::Mat src = cv::imread("einstein.png",0);
	cv::Mat meanshift = cv::imread("meanshift.png",0);
	cv::Mat contrast = cv::imread("contrast.png",0);
	cv::Mat impluse = cv::imread("impluse.png",0);
	cv::Mat blur = cv::imread("blur.png",0);
	cv::Mat jpg = cv::imread("jpg.png",0);

	std::cout<<"src-src  "<<calcSSIM(src,src)<<std::endl;
	std::cout<<"meanshift"<<calcSSIM(src,meanshift)<<std::endl;
	std::cout<<"contrast "<<calcSSIM(src,contrast)<<std::endl;
	std::cout<<"impluse  "<<calcSSIM(src,impluse)<<std::endl;
	std::cout<<"blur     "<<calcSSIM(src,blur)<<std::endl;
	std::cout<<"jpg      "<<calcSSIM(src,jpg)<<std::endl;
}
void dssim_test()
{
	cv::Mat src = cv::imread("einstein.png",0);
	cv::Mat meanshift = cv::imread("meanshift.png",0);
	cv::Mat contrast = cv::imread("contrast.png",0);
	cv::Mat impluse = cv::imread("impluse.png",0);
	cv::Mat blur = cv::imread("blur.png",0);
	cv::Mat jpg = cv::imread("jpg.png",0);

	std::cout<<"src-src  "<<calcDSSIM(src,src)<<std::endl;
	std::cout<<"meanshift"<<calcDSSIM(src,meanshift)<<std::endl;
	std::cout<<"contrast "<<calcDSSIM(src,contrast)<<std::endl;
	std::cout<<"impluse  "<<calcDSSIM(src,impluse)<<std::endl;
	std::cout<<"blur     "<<calcDSSIM(src,blur)<<std::endl;
	std::cout<<"jpg      "<<calcDSSIM(src,jpg)<<std::endl;
}

void various_test()
{
	cv::Mat src = cv::imread("einstein.png",0);
	cv::Mat meanshift = cv::imread("meanshift.png",0);
	
	std::cout<<"mask test(all mask data = 1)"<<std::endl;
	cv::Mat mask(src.size(),CV_8U);
	mask=1;
	std::cout<<calcSSIM(src,meanshift,0,CV_BGR2YUV,mask)<<std::endl;

	std::cout<<"bounding box test(BB = 20x20)"<<std::endl;
	std::cout<<calcSSIMBB(src,meanshift,0,CV_BGR2YUV,20,20)<<std::endl;

	std::cout<<"RGB color space(R)"<<std::endl;
	std::cout<<calcSSIM(src,meanshift,0,CV_BGR2RGB)<<std::endl;
	std::cout<<"RGB color space(G)"<<std::endl;
	std::cout<<calcSSIM(src,meanshift,1L,CV_BGR2RGB)<<std::endl;
	std::cout<<"RGB color space(B)"<<std::endl;
	std::cout<<calcSSIM(src,meanshift,2,CV_BGR2RGB)<<std::endl;
	std::cout<<"RGB color space(aberage R,G and B)"<<std::endl;
	std::cout<<calcSSIM(src,meanshift,ALLCHANNEL,CV_BGR2RGB)<<std::endl;

}
int main(int argc, char** argv)
{
	std::cout<<"ssim test"<<std::endl;
	ssim_test();
	std::cout<<"dssim test"<<std::endl;
	dssim_test();

	/*std::cout<<"various test"<<std::endl;
	various_test();
	*/
		
	return 0;
}
