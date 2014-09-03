#include "Tratamento_imagem.h"

int main(int argc, char** argv) {
	Mat src1 = imread(argv[1], 1);
	Mat src2 = imread(argv[2], 1);
	
	cout << Tratamento_imagem.avg_similarity(src1,src2)	<< endl;

}
