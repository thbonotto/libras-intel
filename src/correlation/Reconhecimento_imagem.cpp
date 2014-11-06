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
static double correlation_result[26];
static Mat images_db[26];
static String caminho = "../../img/Tratada/Externo/";
static String caminho_salvar = "../../img/Tratada/";
static String alfabeto[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                              ,"Q","R","S","T","U","V","W","X","Y","Z"};
sem_t sem;

void Reconhecimento_imagem::load_images(){
    int i;
    static String alfabeto[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                                  ,"Q","R","S","T","U","V","W","X","Y","Z"};
    for(i=0;i<26;i++){
        images_db[i] = imread("../../img/Tratada/Interno/"+alfabeto[i]+".jpg",-1);
    }
}

void* Reconhecimento_imagem::matching(void* arg){
    Arg args = *(Arg*)arg;
    int method, resultColumns, resultRows;
    double maxVal;
    Point minLoc, maxLoc;
    Mat result;
    Mat realMap = args.realMap;
        cout << "comparation thread id:" << args.id << endl;
    String comparisonMethods[] = {"CV_TM_SQDIFF", "CV_TM_SQDIFF_NORMED", "CV_TM_CCORR",
                                  "CV_TM_CCORR_NORMED", "CV_TM_CCOEFF", "CV_TM_CCOEFF_NORMED"}; //List of comparison methods.
    method = CV_TM_CCORR_NORMED; //"Cross coefficient normed" by default.
        Mat slamMap = images_db[args.id];
        //Create the result image.
        resultColumns = realMap.cols - slamMap.cols + 1; //# columns of result.
        resultRows = realMap.rows - slamMap.rows + 1; //# rows of result.
        result.create(resultColumns, resultRows, CV_32FC1); //Allocate space for the result.
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
        minMaxLoc(result, NULL, &maxVal, &minLoc, &maxLoc, Mat()); //Computation.
     correlation_result[args.id] = maxVal;
     return  (void*)&correlation_result[args.id];
    }

vector<int> * Reconhecimento_imagem::reconhecer_imagem_vector(Mat realMap){
    vector<int> * elements = new vector<int>();
    int i;
    pthread_t threads[26];
    for(i=0;i<26;i++){
        Arg *arg_img = new Arg;
        arg_img->corr=0;
        arg_img->id=i;
        arg_img->realMap = realMap;
        pthread_create(&threads[i], 0, Reconhecimento_imagem::matching, (void *)arg_img);
    }
    for(i=0;i<26;i++)
        pthread_join(threads[i],NULL);
    for(i=0;i<26;i++){
        if(abs(correlation_result[i]) > 0.01){
            elements->push_back(i);
        }
    }
    return elements;
}


vector<int> * Reconhecimento_imagem::reconhecer_imagem_area_vector(Mat realMap){
    realMap.convertTo(realMap,CV_8UC1);

    int i;
    double maxVal;
    vector<int> * elements = new vector<int>();
    Correlacao *im1 = new Correlacao();
    im1->mount_vector(realMap);
    Correlacao *im2 = new Correlacao();



    for(i=0;i<26;i++){

              Mat slamMap = imread("../../img/Tratada/Externo/"+alfabeto[i]+".jpg");
           slamMap.convertTo(slamMap,CV_8UC1);
        im2->mount_vector(slamMap);

        maxVal = im2->pearson_correlation(im1->_feature);

        if(abs(maxVal) > abs(0.35)){
            elements->push_back(i);

        }

    }
    return elements;
}

char Reconhecimento_imagem::reconhecer_imagem_area_withvector(Mat realMap, vector<int>* letters){
   Mat slamMap;
    realMap.convertTo(realMap,CV_8UC1);
    Correlacao *im1 = new Correlacao();
    im1->mount_vector(realMap);
    int i;
    double maxVal,corr = 0.0;
    char *c = new char;
cout << "reconhecer_imagem_area_with vector before for with size"<< letters->size() << endl;
    for(i=0;i<26;i++){
            Correlacao *im2 = new Correlacao();
    cout << "Letra"<< alfabeto[letters->at(i)].c_str() << endl;
        slamMap = imread("../../img/Tratada/Externo/"+alfabeto[letters->at(i)]+".jpg");
        slamMap.convertTo(slamMap,CV_8UC1);
        im2->mount_vector(slamMap);
        maxVal = im1->pearson_correlation(im2->_feature);

        if(abs(maxVal) > abs(corr)){
            corr = maxVal;
            c = const_cast<char*>(alfabeto[letters->at(i)].c_str());
        }

    }
     return *c;
}


char Reconhecimento_imagem::reconhecer_imagem_withvector(Mat realMap,vector<int>* letters){
    char c;
    int i;
    double maxVal, corr;
     pthread_t threads[letters->size()];
    sem_init(&sem,0,1);
    for(i=0;i<letters->size();i++){
        Arg *arg_img = new Arg;
        arg_img->corr=0;
        arg_img->id=letters->at(i);
        arg_img->realMap = realMap;
     threads[i]= pthread_create(&threads[i], 0, Reconhecimento_imagem::matching, (void *)arg_img);
    }
  sem_post(&sem);
    for(i=0;i<letters->size();i++){
        if(abs(correlation_result[letters->at(i)]) > abs(corr)){
            corr = maxVal;
            char *a=new char[letters->size()+1];
            a[letters->size()]=0;
            memcpy(a,alfabeto[letters->at(i)].c_str(),letters->size());
            c = a[0];
        }
    }
    cout << "letra" << c << endl;
    return c;
}
