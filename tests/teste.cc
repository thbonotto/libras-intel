#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>



String caminho = "../img/";
String caminho_salvar = "../img/Tratada/";
String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                       ,"Q","R","S","T","U","V","W","X","Y","Z"};

int main(int argc, char** argv) {
	Mat image,image_aux;
	int i=0;
/*	for(i;i<26;i++){
	image=imread(caminho+alfabeto[i]+".jpg",1);
	image=(Tratamento_imagem::filtro_cinza(image))<128;
	imwrite(caminho_salvar+alfabeto[i]+".jpg",image);
	}
	*/
	image=imread(argv[1],1);
	image= Tratamento_imagem::tratar_imagem(image);
	imwrite("./teste.jpg",image);
}
