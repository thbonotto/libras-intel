#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../tratamento_imagem/Tratamento_imagem.h"
#include "../correlation/Reconhecimento_imagem.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <ostream>
#include <pthread.h>
#include "../asmOpenCV.h"
#include <ctime>

using namespace cv;
using namespace std;
void  *showImage(void *fodasse);
MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),  ui(new Ui::MainWindow)
{
    //    pthread_t threads[1];
    //    int rc;
    //    rc = pthread_create(&threads[0], NULL,showImage, (void *)ui);
    //    if (rc){
    //        cout << "Error:unable to create thread," << rc << endl;
    //        exit(-1);
    //    }
    Reconhecimento_imagem::load_images();
    ui->setupUi(this);

    connect(ui->actionSair, SIGNAL(triggered()), this, SLOT(clickMenuButton()));
    connect(ui->start, SIGNAL(triggered()), this, SLOT(clickMenuButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    clock_t start;
    start = clock();
    vector<int>* imageVector = new vector<int>();
    Mat source;
    Mat dest, dest_int;
    char letra;
    VideoCapture cap(0);
    cap >> source;
    // source = imread("../../img/src_image/S.jpg");
    QPixmap mypix = cvMatToQPixmap(source);
    ui->pixmapPreview->setPixmap(mypix);

    try {
        dest = Tratamento_imagem::tratar_imagem(source);

        imwrite("../../e_binarizado.jpg",dest);
    } catch (...) {
        this->letra_reconhecida(' ');
        return;
        cerr << "error tratamento externo" << endl;
    }
    cout << "Metodo area Somente" << endl;
    start = clock();
    cout << "Resultado: " << Reconhecimento_imagem::reconhecer_imagem_ext(dest) << endl;
    cout << "Duração: " << ((clock() - start)/(double)CLOCKS_PER_SEC) << endl;
    try {
        dest_int = Tratamento_imagem::tratar_imagem_contorno_interno(source);
    } catch (...) {
        cerr << "error tratamento externo" << endl;
    }
    cout << "Metodo Correlacao cruzada Somente" << endl;
    start = clock();
    cout << "Resultado: " << Reconhecimento_imagem::reconhecer_imagem_int(dest_int) << endl;
    cout << "Duração: " << ((clock() - start)/(double)CLOCKS_PER_SEC) << endl;


    cout << "Metodo 1 entao 2 " << endl;
    start = clock();

    try {
        imageVector = Reconhecimento_imagem::reconhecer_imagem_area_vector(dest);
    } catch (...) {
        cerr << "error reconhecimento 1" << endl;
    }
    try {
        letra = Reconhecimento_imagem::reconhecer_imagem_withvector(dest_int,imageVector);
        this->letra_reconhecida(letra);
    } catch (...) {
        cerr << "error reconhecimento 2" << endl;
    }
    cout << "Resultado: " << letra << endl;
    cout << "Duração: " << ((clock() - start)/(double)CLOCKS_PER_SEC) << endl;
    cout << "Metodo 2 entao 1 " << endl;
    start = clock();

    try {
        imageVector = Reconhecimento_imagem::reconhecer_imagem_vector(dest_int);
    } catch (...) {
        cerr << "error reconhecimento 1" << endl;
    }
    try {
        letra = Reconhecimento_imagem::reconhecer_imagem_area_withvector(dest,imageVector);
        this->letra_reconhecida(letra);
    } catch (...) {
        cerr << "error reconhecimento 2" << endl;
    }
    cout << "Resultado: " << letra << endl;
    cout << "Duração: " << ((clock() - start)/(double)CLOCKS_PER_SEC) << endl;

}

void MainWindow::clickMenuButton(){
    exit(0);

}
void MainWindow::letra_reconhecida(char l)
{
    int i;
    char a;
    ui->TL_recWord->setText(ui->TL_recWord->text() + l);
    for(i = 0, a = 'A'; i < 27; i++,a++){
        String caminho = "../../img/alpha_img/" + string(1, a) + ".png";
        QPixmap mypix (caminho.c_str());
        switch (a) {
        case 'A':
            ui->pixmapA->setPixmap(mypix);
            break;
        case 'B':
            ui->pixmapB->setPixmap(mypix);
            break;
        case 'C':
            ui->pixmapC->setPixmap(mypix);
            break;
        case 'D':
            ui->pixmapD->setPixmap(mypix);
            break;
        case 'E':
            ui->pixmapE->setPixmap(mypix);
            break;
        case 'F':
            ui->pixmapF->setPixmap(mypix);
            break;
        case 'G':
            ui->pixmapG->setPixmap(mypix);
            break;
        case 'H':
            ui->pixmapH->setPixmap(mypix);
            break;
        case 'I':
            ui->pixmapI->setPixmap(mypix);
            break;
        case 'J':
            ui->pixmapJ->setPixmap(mypix);
            break;
        case 'K':
            ui->pixmapK->setPixmap(mypix);
            break;
        case 'L':
            ui->pixmapL->setPixmap(mypix);
            break;
        case 'M':
            ui->pixmapM->setPixmap(mypix);
            break;
        case 'N':
            ui->pixmapN->setPixmap(mypix);
            break;
        case 'O':
            ui->pixmapO->setPixmap(mypix);
            break;
        case 'P':
            ui->pixmapP->setPixmap(mypix);
            break;
        case 'Q':
            ui->pixmapQ->setPixmap(mypix);
            break;
        case 'R':
            ui->pixmapR->setPixmap(mypix);
            break;
        case 'S':
            ui->pixmapS->setPixmap(mypix);
            break;
        case 'T':
            ui->pixmapT->setPixmap(mypix);
            break;
        case 'U':
            ui->pixmapU->setPixmap(mypix);
            break;
        case 'V':
            ui->pixmapV->setPixmap(mypix);
            break;
        case 'W':
            ui->pixmapW->setPixmap(mypix);
            break;
        case 'X':
            ui->pixmapX->setPixmap(mypix);
            break;
        case 'Y':
            ui->pixmapY->setPixmap(mypix);
            break;
        case 'Z':
            ui->pixmapZ->setPixmap(mypix);
            break;
        default:
            break;
        }

    }
    String caminho = "../../img/alpha_img/" + string(1, l) + "_active.png";
    QPixmap mypix (caminho.c_str());
    switch (l) {
    case 'A':
        ui->pixmapA->setPixmap(mypix);
        break;
    case 'B':
        ui->pixmapB->setPixmap(mypix);
        break;
    case 'C':
        ui->pixmapC->setPixmap(mypix);
        break;
    case 'D':
        ui->pixmapD->setPixmap(mypix);
        break;
    case 'E':
        ui->pixmapE->setPixmap(mypix);
        break;
    case 'F':
        ui->pixmapF->setPixmap(mypix);
        break;
    case 'G':
        ui->pixmapG->setPixmap(mypix);
        break;
    case 'H':
        ui->pixmapH->setPixmap(mypix);
        break;
    case 'I':
        ui->pixmapI->setPixmap(mypix);
        break;
    case 'J':
        ui->pixmapJ->setPixmap(mypix);
        break;
    case 'K':
        ui->pixmapK->setPixmap(mypix);
        break;
    case 'L':
        ui->pixmapL->setPixmap(mypix);
        break;
    case 'M':
        ui->pixmapM->setPixmap(mypix);
        break;
    case 'N':
        ui->pixmapN->setPixmap(mypix);
        break;
    case 'O':
        ui->pixmapO->setPixmap(mypix);
        break;
    case 'P':
        ui->pixmapP->setPixmap(mypix);
        break;
    case 'Q':
        ui->pixmapQ->setPixmap(mypix);
        break;
    case 'R':
        ui->pixmapR->setPixmap(mypix);
        break;
    case 'S':
        ui->pixmapS->setPixmap(mypix);
        break;
    case 'T':
        ui->pixmapT->setPixmap(mypix);
        break;
    case 'U':
        ui->pixmapU->setPixmap(mypix);
        break;
    case 'V':
        ui->pixmapV->setPixmap(mypix);
        break;
    case 'W':
        ui->pixmapW->setPixmap(mypix);
        break;
    case 'X':
        ui->pixmapX->setPixmap(mypix);
        break;
    case 'Y':
        ui->pixmapY->setPixmap(mypix);
        break;
    case 'Z':
        ui->pixmapZ->setPixmap(mypix);
        break;
    default:
        break;
    }


}

