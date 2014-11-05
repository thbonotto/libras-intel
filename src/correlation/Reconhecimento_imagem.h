#ifndef CORRELATION_H
#define CORRELATION_H
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

using namespace std;
using namespace cv;



class Reconhecimento_imagem{

    public:

   static char reconhecer_imagem(Mat realMap);
   static vector<String> * reconhecer_imagem_vector(Mat realMap);



};


#endif // CORRELATION_H
