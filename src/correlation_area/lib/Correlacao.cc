/*
 * Correlacao.cc
 *
 *  Created on: 19 Oct 2014
 *      Author: heisenberg
 */

#include "Correlacao.h"
#include <iostream>

using namespace cv;
using namespace std;

int Correlacao::__size = 100;
size_t Correlacao::__stride = 1;

// Correlacao constructor: must initialize Tratamento_imagem's attributes
Correlacao::Correlacao() {

	this->_corr = 0;
	return;
}
//Correlacao destructor: must finalize Tratamento_imagem's attributes
Correlacao::~Correlacao() { return; }

// count the number of white's pixels on parts of binary image
double Correlacao::count_white(Mat square){

	double white = 0;	

	for(int i=0;i<square.rows;i++){
		for(int j=0;j<square.cols;j++){
			//cerr << "in1" << endl;
			if(square.at<uchar>(i,j)==0){
				white += 1;			
			}
		}
	}
	//cerr << white << endl;
	return (white/100);
}
// divide a binary image
void Correlacao::divide_image(Mat image){
	int num_r = 0;

	cout << image.rows << "::" << image.cols << endl;
    for(int y = 0; y < image.rows; y+=10){
		for(int x = 0; x < image.cols && num_r < this->__size; x+=10){
			try {
                if(x == 90 && y == 90) this->rec[num_r] =Tratamento_imagem::cortar_imagem(image, x,y,image.rows-x-1,image.cols-y-1);
                else this->rec[num_r] =Tratamento_imagem::cortar_imagem(image, x,y,10,10);
				num_r++;	
			} catch(const ios_base::failure& e) {
    				cout << "Exception" << endl;
    				return;
			}
		}
	}

	return;
}
//mount the feature vector of binary image
void Correlacao::mount_vector(Mat image){

	this->divide_image(image);

	for(int x = 0; x < __size; x++){
		this->_feature.push_back(this->count_white(this->rec[x]));
	}
	return;

}
double Correlacao::pearson_correlation(vector<double> y){

	gsl_vector_const_view gsl_x = gsl_vector_const_view_array( &this->_feature[0], this->_feature.size());
	gsl_vector_const_view gsl_y = gsl_vector_const_view_array( &y[0], y.size());

	this->_corr = gsl_stats_correlation((double*) gsl_x.vector.data, this->__stride,(double*) gsl_y.vector.data, this->__stride, this->__size);

	cout << this->_corr << endl;

	return this->_corr;
}







