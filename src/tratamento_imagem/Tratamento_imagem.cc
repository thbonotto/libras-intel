#include "Tratamento_imagem.h"

/*Função que deixa a imagem em tons de cinza
 param
 Mat image -> Imagem que vai ser trabalhado e deixada em tons de cinza;

 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::filtro_cinza(Mat image) {
	Mat gray_image;
	cvtColor(image, gray_image, CV_RGB2GRAY);
	return gray_image;
}
/*Função que deixa a imagem em HSV
 param
 Mat image -> Imagem que vai ser trabalhado e deixada em tons de cinza;

 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::filtro_hsv(Mat image) {
	Mat hsv_image;
	cvtColor(image, hsv_image, CV_BGR2HSV);
	return hsv_image;
}
/*Função que faz um blur na imagem, da uma embaçada na imagem;
 param
 Mat image -> Imagem que vai ser trabalhado e deixada embaçada;
 int modo -> mode de operação, se mode de operação.
 
 1 -> Bilateral Filter
 2 -> Gaussina Bluer

 return -> retorna a imagem trabalhada;
 */
Mat Tratamento_imagem::blur_imagem(Mat image, int modo, int MAX_KERNEL_LENGTH) {
	Mat aux_image;
	switch (modo) {
	case 1:
		for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2) {
			bilateralFilter(image, aux_image, i, i * 2, i / 2);
		}
		return aux_image;
	case 2:
		for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2) {
			GaussianBlur(image, aux_image, Size(i, i), 0, 0);
		}
		return aux_image;
	default:
		cout << "Modo de operação não existe" << endl;
		return aux_image;
		break;
	}

}
/*Função que satura a imagem
 param
 Mat image -> Imagem que vai ser saturada;

 return -> retorna a imagem trabalhada;
 */
Mat Tratamento_imagem::contraste_imagem(Mat image) {

	double alpha = 1; /**< Simple contrast control */
	int beta = 90; /**< Simple brightness control */
		
	Mat new_image = Mat::zeros(image.size(), image.type());
	/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				new_image.at < Vec3b > (y, x)[c] = saturate_cast < uchar
						> (alpha * (image.at < Vec3b > (y, x)[c]) + beta);
			}
		}
	}

	return new_image;

}

/*Função cria uma jenela com imagem
 param
 Mat image -> Imagem que vai ser visualizada;
 nome_janela -> Nome que irá aparecer na janela;
 */
void Tratamento_imagem::mostra_imagem(Mat image, String nome_janela) {

	namedWindow(nome_janela, CV_WINDOW_AUTOSIZE);
	imshow(nome_janela, image);

}

/*Função que aplica metodo canny para destacar contornos na imagem
 param
 Mat image -> Imagem que vai ser saturada;
 int tresh -> grau do filtro Canny

 return -> retorna a imagem trabalhada;
 */
Mat Tratamento_imagem::canny(Mat image, int thresh) {

	Mat aux_image;

	/// Detect edges using canny
	Canny(image, aux_image, thresh, thresh * 2, 3);

	return aux_image;
}

/*Função que detecta os contornos a partir de uma imagem
 param
 Mat image -> Imagem que vai ser identificado o contorno.

 return -> retorna classe Contorno com os dados do contorno(contours,hierarchy,size)
 
 Note

 Source image is modified by this function. Also, the function does not take into account 1-pixel border of the image (it’s filled with 0’s and used for neighbor analysis in the algorithm), therefore the contours touching the image border will be clipped.
 
 */
Tratamento_imagem::Contorno Tratamento_imagem::find_contour(Mat image) {

	vector < vector<Point> > contours_aux;
	vector < Vec4i > hierarchy_aux;

	Contorno aux_contorno;
	findContours(image, contours_aux, hierarchy_aux, CV_RETR_TREE,
			CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	aux_contorno.contours(contours_aux);
	aux_contorno.hierarchy(hierarchy_aux);
	aux_contorno.size(image.size());
	return aux_contorno;
}
/*Função que cria uma imagem a partir dos contornos
 param
 Contorno -> Classe Contorno com os dados do contorno

 return -> retorna imagem desenhada a partir do contorno
 */
Mat Tratamento_imagem::draw_contour(Tratamento_imagem::Contorno contornos) {
	Mat drawing = Mat::zeros(contornos.size(), CV_8UC3);
	for (int i = 0; i < contornos.contours().size(); i++) {
		Scalar color = Scalar(255, 255, 255);
		drawContours(drawing, contornos.contours(), i, color, 2, 8,
				contornos.hierarchy(), 0, Point());
	}
	return drawing;
}

/*Função que cria uma imagem a partir dos contornos
 param
 Mat image -> Imagem que quer achar o contorno

 return -> retorna imagem desenhada a partir do contorno
 */
Mat Tratamento_imagem::draw_contour_image(Mat image) {
	Mat aux_image = image.clone();
	Tratamento_imagem::Contorno contornos = find_contour(canny(aux_image, 50));
	Mat drawing = Mat::zeros(contornos.size(), CV_8UC3);
	for (int i = 0; i < contornos.contours().size(); i++) {
		Scalar color = Scalar(255, 255, 255);
		drawContours(drawing, contornos.contours(), i, color, 2, 8,
				contornos.hierarchy(), 0, Point());
	}
	return drawing;
}
/*Função que deixa a imagem em HUE
 param
 Mat image -> Imagem que vai ser trabalhado e deixada em HUE

 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::hue_image(Mat image) {
	Mat hue;

	Mat hsv = filtro_hsv(image);
/// Use only the Hue value
	hue.create(hsv.size(), hsv.depth());
	int ch[] = { 0, 0 };
	mixChannels(&hsv, 1, &hue, 1, ch, 1);
	return hue;
}

/*Função que aplica um alto contraste na foto
 param
 Mat image -> Imagem que vai ser trabalhada
 int bins -> grau de BackProject (quando proxima de 0 imagem fica em PB. >20 imagem fica em tons de cinza).

 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::Hist_and_Backproj(Mat image, int bins) {
	Mat aux_image = hue_image(image);
	MatND hist;
	int histSize = MAX(bins, 2);
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };
	calcHist(&aux_image, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());
	MatND backproj;
	calcBackProject(&aux_image, 1, 0, hist, backproj, &ranges, 1, true);
	return backproj;

}

/*Função que aplica threshold
 param
 Mat image -> Imagem que vai ser trabalhada
 int intensity -> intensidade do operador
 int mode -> modo de operação do threshold
 0: Binary
 1: Binary Inverted
 2: Threshold Truncated
 3: Threshold to Zero
 4: Threshold to Zero Inverted
 
 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::threshold_image(Mat image, int mode, int intensity) {
	Mat aux_image;
	threshold(image, aux_image, intensity, max_BINARY_value, mode);
	return aux_image;
}

/*Função que modifica o tamanho da imagem
 param
 Mat image -> Imagem que vai ser trabalhada
 int proporcao -> razao de proporcionalidade
 
 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::image_scale(Mat image, int mode, int proporcao) {
	if (mode <= 0 or proporcao <= 0) {
		cerr << "informação incorreta" << endl;
	}
	Mat aux_image;
	switch (mode) {
	case 1:
		pyrUp(image, aux_image,
				Size(image.cols * proporcao, image.rows * proporcao));
		return aux_image;
	case 2:
		pyrDown(image, aux_image,
				Size(image.cols / proporcao, image.rows / proporcao));
		return aux_image;
	}

}

/*Função que compara duas imagens
 param
	Mat I1 -> Imagem1 que vai ser comparada
	Mat I2 -> Imagem2 que vai ser comparada
 
 return -> double com o valor de correlação das duas imagens

 */
double Tratamento_imagem::getPSNR(const Mat& I1, const Mat& I2) {
	Mat s1;
	absdiff(I1, I2, s1);       // |I1 - I2|
	s1.convertTo(s1, CV_32F);  // cannot make a square on 8 bits
	s1 = s1.mul(s1);           // |I1 - I2|^2

	Scalar s = sum(s1);         // sum elements per channel

	double sse = s.val[0] + s.val[1] + s.val[2]; // sum channels

	if (sse <= 1e-10) // for small values return zero
		return 0;
	else {
		double mse = sse / (double) (I1.channels() * I1.total());
		double psnr = 10.0 * log10((255 * 255) / mse);
		return psnr;
	}
}

// Tratamento_imagem constructor: must initialize Tratamento_imagem's attributes
Tratamento_imagem::Tratamento_imagem() {
}

/*Função que recorta a imagem
 param
 	Mat image -> Imagem que vai ser trabalhada
 	int p_inicial_x -> Ponto de origem do recorte no eixo X
 	int p_inicial_y -> Ponto de origem do recorte no eixo Y
	int tam_x -> Tamanho em pixels do recorte no eixo X
	int tam_y -> Tamanho em pixels do recorte no eixo Y
 
 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::cortar_imagem(Mat image,int p_inicial_x,int p_inicial_y,int tam_x,int tam_y){
	Rect r(p_inicial_x, p_inicial_y, tam_x, tam_y);
	return image(r);
}

/*Função que centraliza uma imagem matendo uma relação de distância padrão
Obs: A imagem deve estar em escalas de cinza e binarizada já
 param
 	Mat image -> Imagem que vai ser centralizada
 	
 return -> retorna a imagem trabalhada;

 */
Mat Tratamento_imagem::centroide_contorno(Mat image){

	int i,j,aux_esq,aux_dir,aux_sup,cent_x,cent_y;
     	int *ret = (int*)malloc(100*sizeof(int));
	Mat aux = Mat::zeros( image.rows*2,image.cols*2, CV_8UC1 );
	for(i=0;i<image.rows;i++){
		for(j=0;j<image.cols;j++){
			aux.at<uchar>(i+(image.rows/2),j+(image.cols/2))=image.at<uchar>(i,j);
		}
	
	}
	imwrite("./teste_aux.jpg",aux);		

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
	ret[0] = (aux_esq-(aux_dir-aux_esq)/2);
	ret[1] = aux_sup*0.5;
	ret[2] = ((aux_dir - aux_esq)*1.5);
	if(aux_sup==0){
		ret[3] = image.rows/2;


	}else{
		if((image.rows/aux_sup)>10){
			ret[3] = aux_sup*10;

		}else{
		if((image.rows/aux_sup)>5){
			ret[3] = aux_sup*5;

		}
		else{	

			ret[3] = aux_sup*2;
		}
		}
	}
//	cout << ret[0] << endl << ret[1] << endl << ret[2] << endl << ret[3] << endl;
	image = Tratamento_imagem::cortar_imagem(aux,ret[0]+aux.rows/4,ret[1]+aux.cols/4,ret[2],ret[3]+aux.cols/4);
	return image;

}

//Retorna imagem tratada 
Mat Tratamento_imagem::tratar_imagem(Mat image) {

	int i;
	
	image=image*1.25;
	image = Tratamento_imagem::contraste_imagem(image);
	image = (Tratamento_imagem::filtro_cinza(image)) < cv::mean(image).val[0];
	image = Tratamento_imagem::centroide_contorno(image);

	return image;

}

// Tratamento_imagem destructor: must finalize Tratamento_imagem's attributes
Tratamento_imagem::~Tratamento_imagem() {
	return;
}

