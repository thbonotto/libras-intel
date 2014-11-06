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
#include "../correlation_area/lib/Correlacao.h"
#include <pthread.h>
#include <semaphore.h>

using namespace std;
using namespace cv;



class Reconhecimento_imagem{

    public:
    Reconhecimento_imagem(){

    }
   static void* matching(void* arg);
   static char reconhecer_imagem(Mat realMap);
   static vector<int> * reconhecer_imagem_vector(Mat realMap);
   static vector<int> * reconhecer_imagem_area_vector(Mat realMap);
   static char reconhecer_imagem_withvector(Mat realMap, vector<int> *letters);
   static char reconhecer_imagem_area_withvector(Mat realMap, vector<int> *letters);
   static void load_images();

private:
   typedef struct argumentos{
       int id;
       Mat realMap;
       double corr;
   } Arg;



};


#endif // CORRELATION_H
