/*
 * Correlacao.h
 *
 *  Created on: 19 Oct 2014
 *      Author: heisenberg
 */

#ifndef CORRELACAO_H_
#define CORRELACAO_H_

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include "../tratamento_imagem/Tratamento_imagem.h"
#include <gsl/gsl_vector.h>
#include <gsl/gsl_statistics.h>



namespace cv{

class Correlacao{
public:

	Correlacao();
	~Correlacao();
	double count_white(Mat square);
	void divide_image(Mat image);
	void mount_vector(Mat image);
	double pearson_correlation(std::vector<double> y);

	static size_t __stride;
	static int __size;

protected:

	std::vector <double> _feature;
	double _corr;
	Mat *rec = new Mat[__size];

};

}/*namespace OpenCV*/


#endif /* CORRELACAO_H_ */
