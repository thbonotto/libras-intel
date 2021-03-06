#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>



String caminho = "../database_img/";
String caminho_salvar_externo = "../Tratada/Externo/";
String caminho_salvar_interno = "../Tratada/Interno/";
String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                       ,"Q","R","S","T","U","V","W","X","Y","Z"};

int main(int argc, char** argv) {
	Mat image,image_aux;
	int i=0;
	//Montar biblioteca de contorno externo
	if(atoi(argv[1])==0){
		for(i;i<26;i++){
			image=imread(caminho+alfabeto[i]+".jpg",1);
			image=(Tratamento_imagem::filtro_cinza(image)*1.5) < cv::mean( image ).val[0];
			imwrite(caminho_salvar_externo+alfabeto[i]+".jpg",image);
		}
	}
	//Montar biblioteca de contorno interno
	if(atoi(argv[1])==1){
		for(i;i<26;i++){
			image=imread(caminho+alfabeto[i]+".jpg",1);
			image=(Tratamento_imagem::filtro_cinza(image))<128;
			imwrite(caminho_salvar_interno+alfabeto[i]+".jpg",image);
		}
	}
	
}
