#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>


String caminho = "../img/";
String alfabeto[27] = ("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                       ,"Q","R","S","T","U","V","W","X","Y","Z");

int main(int argc, char** argv) {
	Mat image;
	image=imread(argv[1],1);		
	image = Tratamento_imagem::Hist_and_Backproj(image,atoi(argv[2]));
	int i=0;
	for(i;i<27;i++){
		cout << "Letra :"+alfabeto[i] + " =  " + Tratamento_imagem::getPSNR(image,imread(caminho+alfabeto[i]+".jpg")) << endl; 
	}
	
	
	

}
