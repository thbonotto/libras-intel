#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>


String caminho = "../src_image/";
String caminho_salvar_externo = "../Tratada/Externo/";
String caminho_salvar_interno = "../Tratada/Interno/";
String alfabeto[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

int main(int argc, char** argv) {
    Mat image,image_aux;
    int i=0;
    int y=0;

    Mat image1;
    std::ofstream myfile(caminho_salvar_externo + "vector.txt");
    string line;

    //Montar biblioteca de contorno externo
    if(atoi(argv[1])==0){
        for(i;i<26;i++){
            image=imread(caminho+alfabeto[i]+".jpg",1);
            image= Tratamento_imagem::tratar_imagem(image);
            imwrite(caminho_salvar_externo+alfabeto[i]+".jpg",image);
        }
    }
    //Montar biblioteca de contorno interno
    if(atoi(argv[1])==1){
        for(i;i<26;i++){
            image=imread(caminho+alfabeto[i]+".jpg",1);
            image = Tratamento_imagem::tratar_imagem_contorno_interno(image);
            imwrite(caminho_salvar_interno+alfabeto[i]+".jpg",image);
        }
    }
    //Montar biblioteca de vetores
    if(atoi(argv[1]==2)){
        if (myfile.is_open()) {
            for(int i = 0; i < 26 ; i++){

                Correlacao *im1 = new Correlacao();
                image1 = imread(caminho_salvar_externo+alfabeto[i]+".jpg");
                image1.convertTo(image1,CV_8UC1);
                im1->mount_vector(image1);

                for(int j = 0; j < im1->_feature.size(); j++ ){
                    myfile <<  im1->_feature.at(j) << "-";

                }
                myfile << "\n";
                delete im1;
            }
            myfile.close();
        }
        else cerr << "Unable to open file" << endl;
        return -1;
    }

}
