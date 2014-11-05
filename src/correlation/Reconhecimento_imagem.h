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
    Reconhecimento_imagem(){
        int i =0;
        static String caminho = "../../img/Tratada/Interno/";
        static String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                ,"Q","R","S","T","U","V","W","X","Y","Z"};
        for(i=0;i<26;i++){
            this->letters[i] = imread(caminho+alfabeto[i]+".jpg",-1);
        }

    }

   static char reconhecer_imagem(Mat realMap);
   static vector<String> * reconhecer_imagem_vector(Mat realMap);
private:
   static Mat letters[27];



};


#endif // CORRELATION_H
