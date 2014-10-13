#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>



String caminho = "../img/";
String caminho_salvar = "../img/Tratada/";

String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                       ,"Q","R","S","T","U","V","W","X","Y","Z"};


int * centroide_contorno(Mat image){

	int i,j,aux_esq,aux_dir,aux_sup,cent_x,cent_y;
     	int *ret = (int*)malloc(100*sizeof(int));
	aux_esq=image.cols;
	for(i=0; i<image.rows; i++){
	    for(j=0; j<image.cols; j++){
			if(aux_esq>j and image.at<uchar>(i,j)!=0){
				aux_esq=j;
			}
		}
	}
	aux_dir=0;
	for(i=0; i<image.rows; i++){
	    for(j=image.cols; j>=0 ; j--){
			if(aux_dir<j and image.at<uchar>(i,j)!=0){
				aux_dir=j;
			}
		}
	}
	aux_sup=image.rows;
	for(j=0; j<image.cols; j++){
		for(i=0; i<=image.rows; i++){
			if(aux_sup>i and image.at<uchar>(i,j)!=0){
				aux_sup=i;
			}
		}
	}
//	cout << aux_esq << endl << aux_dir << endl << aux_sup << endl;
	ret[0] = aux_esq - ( aux_dir - aux_esq )/2;
	ret[1] = aux_sup*0.5;	
	ret[2] = ( aux_dir + ( aux_dir - aux_esq )/2 ) - aux_esq;
	ret[3] = aux_sup*2;

	return ret;
	

}

int main(int argc, char** argv) {
	Mat image,image_aux;


	image=imread(argv[1],1);
	image= Tratamento_imagem::tratar_imagem(image);
	int * ret = centroide_contorno(image);
	cout << ret[0] << endl << ret[1] << endl << ret[2] << endl << ret[3] << endl;
	image = Tratamento_imagem::cortar_image(image,ret[0],ret[1],ret[2],ret[3]);
	imwrite("./teste.jpg",image);	
	


}
