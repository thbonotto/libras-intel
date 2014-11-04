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

using namespace cv;
using namespace std;
void  *showImage(void *fodasse);
Mat dest;
MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent),  ui(new Ui::MainWindow)
{
//    pthread_t threads[1];
//    int rc;
//    rc = pthread_create(&threads[0], NULL,showImage, (void *)ui);
//    if (rc){
//        cout << "Error:unable to create thread," << rc << endl;
//        exit(-1);
//    }

    ui->setupUi(this);

    connect(ui->actionSair, SIGNAL(triggered()), this, SLOT(clickMenuButton()));
    connect(ui->start, SIGNAL(triggered()), this, SLOT(clickMenuButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  *showImage(void *p){
    while(1){
    Mat frame;
    // open the default camera
    VideoCapture cap(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 960);
    if(!cap.isOpened())  // check if we succeeded
        return (void*)-1;

    cap >> frame;
    Ui::MainWindow *hue = (Ui::MainWindow*)p;
//    cvtColor(frame, dest, CV_BGR2GRAY);
//    GaussianBlur(dest, dest, Size(7,7), 1.5, 1.5);
//    Canny(dest, dest, 0, 30, 3);
    QPixmap mypix = QPixmap::fromImage(QImage((unsigned char*) frame.data, frame.cols, frame.rows, QImage::Format_RGB888));
    hue->pixmapPreview->setPixmap(mypix);
    }
}

void MainWindow::on_start_clicked()
{

   // static char a = '';
  //  String caminho = "../../img/" + string(1, a) + ".jpg";
    Mat source;
    char letra;
     source = imread("../S.jpg");
   dest = Tratamento_imagem::tratar_imagem(source);
   cout << "Teste" << endl;
   imwrite("../_tratada.jpg",dest);
   try {
       letra = Reconhecimento_imagem::reconhecer_imagem(dest);
       this->letra_reconhecida(letra);
   } catch (...) {
       this->letra_reconhecida('Z');
   }
//   a=(++a!='[') ? a :'a';


        //       imwrite("../../img/database_img/ant_tratada.jpg",frame);
        //       dest =  Tratamento_imagem::tratar_imagem(frame);
        //       imwrite("../../img/database_img/ant_tratada.jpg",dest);
//        Mat frame;
//        // open the default camera
  //      VideoCapture cap(0);
    //    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
      //  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 960);
        //if(!cap.isOpened())  // check if we succeeded
          //  return ;

        //cap >> frame;
//        cvtColor(frame, dest, CV_BGR2GRAY);
//        GaussianBlur(dest, dest, Size(7,7), 1.5, 1.5);
//        Canny(dest, dest, 0, 30, 3);
    //    dest = Tratamento_imagem::tratar_imagem_contorno_interno(frame);
      //  imwrite("../../img/Tratada/dest.jpg",dest);
        QPixmap mypix = QPixmap::fromImage(QImage((unsigned char*) dest.data, dest.cols, dest.rows, QImage::Format_RGB888));
        ui->pixmapPreview->setPixmap(mypix);
     //   this->letra_reconhecida(Reconhecimento_imagem::reconhecer_imagem(dest));




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

