/*********************************************************************
 *
 *
 * 
 * Compare two images using different methods, including
 * cross correlation.
 *
 *********************************************************************/
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Reconhecimento_imagem.h"


static String caminho = "../../img/Tratada/Externo/";
static String caminho_salvar = "../../img/Tratada/";
static String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
        ,"Q","R","S","T","U","V","W","X","Y","Z"};


 char Reconhecimento_imagem::reconhecer_imagem(Mat realMap){

    int method, resultColumns, resultRows;
    int i;
    double* maxVal,*corr;
	char c;	
    int aux=0;
	Point minLoc, maxLoc;
	Mat result;
	String comparisonMethods[] = {"CV_TM_SQDIFF", "CV_TM_SQDIFF_NORMED", "CV_TM_CCORR",
			"CV_TM_CCORR_NORMED", "CV_TM_CCOEFF", "CV_TM_CCOEFF_NORMED"}; //List of comparison methods.
	method = CV_TM_CCOEFF_NORMED; //"Cross coefficient normed" by default.
	//Bad parameters handling.
	/*realMapPath = argv[1];
	slamMapPath = argv[2];
	Mat realMap = imread(realMapPath, 0); //Get the real map image. 0 is grayscale. -1 is original image.
	Mat slamMap = imread(slamMapPath, 0); //Get the slam map image. 0 is grayscale. -1 is original image.
	//Bad parameters handling.
	 */

    for(i=0;i<26;i++){
        Mat slamMap = imread(caminho+alfabeto[i]+".jpg",-1);
        cout << slamMap.size() << endl;
        cout << alfabeto[i] << endl;
		//Create the result image.
		resultColumns = realMap.cols - slamMap.cols + 1; //# columns of result.
		resultRows = realMap.rows - slamMap.rows + 1; //# rows of result.
		result.create(resultColumns, resultRows, CV_32FC1); //Allocate space for the result.
		///http://answers.opencv.org/question/16535/alpha-dependent-template-matching/
		Mat templ, img;
		slamMap.copyTo(templ);
		realMap.copyTo(img);
		const double UCHARMAX = 255;
		const double UCHARMAXINV = 1./UCHARMAX;
		vector<Mat> layers;
		//RGB+Alpha layer containers.
		Mat templRed(templ.size(), CV_8UC1);
		Mat templGreen(templ.size(), CV_8UC1);
		Mat templBlue(templ.size(), CV_8UC1);
		Mat templAlpha(templ.size(), CV_8UC1);
		Mat imgRed(img.size(), CV_8UC1);
		Mat imgGreen(img.size(), CV_8UC1);
		Mat imgBlue(img.size(), CV_8UC1);
		Mat imgAlpha(img.size(), CV_8UC1);
		//Check if one the the images has an alpha channel.
		if(templ.depth() == CV_8U && img.depth() == CV_8U &&
				(img.type() == CV_8UC3 || img.type() == CV_8UC4) &&
				(templ.type() == CV_8UC3 || templ.type() == CV_8UC4)){
			//Divide image and template into RGB+alpha layers.
			if(templ.type() == CV_8UC3){ //Template doesn't have alpha.
				templAlpha = Scalar(UCHARMAX);
				split(templ, layers);
				layers[0].copyTo(templBlue);
				layers[1].copyTo(templGreen);
				layers[2].copyTo(templRed);
			}
			else if(templ.type() == CV_8UC4){ //Template has alpha.
				split(templ, layers);
				layers[0].copyTo(templBlue);
				layers[1].copyTo(templGreen);
				layers[2].copyTo(templRed);
				layers[3].copyTo(templAlpha);
			}
			if(img.type() == CV_8UC3){ //Image doesn't have alpha.
				imgAlpha = Scalar(UCHARMAX);
				split(img, layers);	
				layers[0].copyTo(imgBlue);
				layers[1].copyTo(imgGreen);
				layers[2].copyTo(imgRed);
			}
			else if(templ.type() == CV_8UC4){ //Image has alpha.
				split(img, layers);
				layers[0].copyTo(imgBlue);
				layers[1].copyTo(imgGreen);
				layers[2].copyTo(imgRed);
				layers[3].copyTo(imgAlpha);
			}
			Size resultSize(img.cols - templ.cols + 1, img.rows - templ.rows + 1);
			result.create(resultSize, CV_32F);
			//Multiply the RBG layers with the alpha channel to mask areas to be ignored.
			multiply(templRed, templAlpha, templRed, UCHARMAXINV);
			multiply(templGreen, templAlpha, templGreen, UCHARMAXINV);
			multiply(templBlue, templAlpha, templBlue, UCHARMAXINV);
			multiply(imgRed, imgAlpha, imgRed, UCHARMAXINV);
			multiply(imgGreen, imgAlpha, imgGreen, UCHARMAXINV);
			multiply(imgBlue, imgAlpha, imgBlue, UCHARMAXINV);
			//Merge the layers back together.
			Mat tempSlam(templ.size(), CV_8UC3);
			Mat tempReal(img.size(), CV_8UC3);
			Mat in[] = {templBlue, templGreen, templRed};
			Mat in2[] = {imgBlue, imgGreen, imgRed};	
			merge(in, 3, tempSlam);
			merge(in2, 3, tempReal);
			//Compare the slam map with the real map & evaluate result.
			matchTemplate(tempReal, tempSlam, result, method);	
		}
		else{	
			//Compare the slam map with the real map & evaluate result.
			matchTemplate(realMap, slamMap, result, method);	
		}
		//Compute the best matching score.
		maxVal = (double*)malloc(sizeof( double* )); //Will store best matching score.
		minMaxLoc(result, NULL, maxVal, &minLoc, &maxLoc, Mat()); //Computation.
		/*Display the result. If the images are not aligned at this point then
the correlation result is worthless. Code copied from OpenCV MatchTemplate
API.*/	
		cout << "The score for " << comparisonMethods[method] << " is " << *maxVal << "\n";	

        if(abs(*maxVal) > abs(*corr)){
          corr = maxVal;
          char *a=new char[alfabeto[i].size()+1];
          a[alfabeto[i].size()]=0;
          memcpy(a,alfabeto[i].c_str(),alfabeto[i].size());
          c = a[0];
          aux=i;
		}
		
	}
    cout << "letra" << c << endl;
	return c;	
}