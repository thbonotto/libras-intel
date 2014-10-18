#include <unistd.h>
#include "Tratamento_imagem.h"
#include <iostream>



String caminho = "../img/";
String caminho_salvar = "../img/Tratada/";

String alfabeto[27] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"
                       ,"Q","R","S","T","U","V","W","X","Y","Z"};


Mat image_resize(Mat image,int lin,int col){

	Size size(lin,col);
	resize(image,image,size);//resize image
	return image;

}


int main(int argc, char** argv) {
	Mat image,image_aux;


	image=imread(argv[1],1);
	image= Tratamento_imagem::tratar_imagem(image);
	imwrite("./teste.jpg",image);

	
	


}
