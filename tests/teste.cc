#include <unistd.h>
#include <time.h>
#include "Tratamento_imagem.h"

String caminho = "./Tratada/";
time_t timer;
struct tm * timeinfo;

int main(int argc, char** argv) {
	Mat image;
	image=imread(argv[1],1);		
	image = Tratamento_imagem::Hist_and_Backproj(image,atoi(argv[2]));
	imwrite( caminho+argv[1], image );		

}
