#ifndef Tratamento_imagem_h
#define Tratamento_imagem_h

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;


class Tratamento_imagem{
	
	public:

	static const double alpha = 1; /**< Simple contrast control */
	static const int beta = 90; /**< Simple brightness control */
	static int const max_BINARY_value = 255;


	
	/*Classe que armazena os dados de uma detecção de contorno
	 param
	 	 _contour ->
	 	 _hierarchy ->
	 	 _size ->
	 */

	class Contorno {
		public:
			void contours(vector<vector<Point> > vector) {
				_contours = vector;
			}
			void hierarchy(vector<Vec4i> vector) {
				_hierarchy = vector;
			}
			vector<vector<Point> > contours() {
				return _contours;
			}
			vector<Vec4i> hierarchy() {
				return _hierarchy;
			}
			void size(Size size) {
				_size = size;
			}
			Size size() {
				return _size;
			}

		private:
			vector<vector<Point> > _contours;
			vector<Vec4i> _hierarchy;
			Size _size;

		};
	
	static Mat filtro_cinza(Mat image);
	
	static Mat filtro_hsv(Mat image);
	
	static Mat blur_imagem(Mat image, int modo, int MAX_KERNEL_LENGTH);
	
//	Mat saturacao_imagem(Mat image);
	
	static void mostra_imagem(Mat image, String nome_janela);
	
	static Mat canny(Mat image, int thresh);
	
	static Contorno find_contour(Mat image);
	
	static Mat draw_contour(Contorno contornos);
	
	static Mat draw_contour_image(Mat image);
	
	static Mat hue_image(Mat image);
	
	static Mat Hist_and_Backproj(Mat image,int bins);
	
	static Mat threshold_image(Mat image, int mode,int intensity);
	
	static Mat image_scale(Mat image,int mode,int proporcao);
	
	static Scalar getMSSIM( const Mat& i1, const Mat& i2);
	
	static double getPSNR(const Mat& I1, const Mat& I2);
	
	static double avg_similarity(Mat img1,Mat img2);
			
	
	private:

	Tratamento_imagem();
	virtual ~Tratamento_imagem();
	
	
	
	
	
};


#endif /*Tratamento_imagem_h*/
