/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <Qt3Support/Q3ButtonGroup>
#include <Qt3Support/Q3Frame>
#include <Qt3Support/Q3GroupBox>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <phonon/videowidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionIniciar;
    QAction *actionSair;
    QAction *actionFiltros;
    QAction *actionC_mera;
    QWidget *centralWidget;
    Q3Frame *frame3;
    Q3GroupBox *groupBox2;
    QLabel *pixmapN;
    QLabel *pixmapK;
    QLabel *pixmapM;
    QLabel *pixmapH;
    QLabel *pixmapB;
    QLabel *pixmapE;
    QLabel *pixmapF;
    QLabel *pixmapL;
    QLabel *pixmapG;
    QLabel *pixmapD;
    QLabel *pixmapA;
    QLabel *pixmapJ;
    QLabel *pixmapC;
    QLabel *pixmapP;
    QLabel *pixmapO;
    QLabel *pixmapQ;
    QLabel *pixmapI;
    QLabel *pixmapR;
    QLabel *pixmapS;
    QLabel *pixmapT;
    QLabel *pixmapU;
    QLabel *pixmapV;
    QLabel *pixmapW;
    QLabel *pixmapX;
    QLabel *pixmapY;
    QLabel *pixmapZ;
    QLabel *pixmapIFSC;
    Q3ButtonGroup *LanguageGroup;
    QCheckBox *CB_Vocalize;
    QComboBox *ListLanguage;
    QCheckBox *CB_Translate;
    QLabel *TLLanguage;
    Q3GroupBox *recognizedWord;
    QLineEdit *TL_recWord;
    QPushButton *start;
    Phonon::VideoWidget *VideoWidget;
    QMenuBar *menuBar;
    QMenu *menuIALIBRAS;
    QMenu *menuOp_es;
    QMenu *menuSObre;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(861, 734);
        actionIniciar = new QAction(MainWindow);
        actionIniciar->setObjectName(QString::fromUtf8("actionIniciar"));
        actionIniciar->setCheckable(false);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionSair->setCheckable(true);
        actionFiltros = new QAction(MainWindow);
        actionFiltros->setObjectName(QString::fromUtf8("actionFiltros"));
        actionC_mera = new QAction(MainWindow);
        actionC_mera->setObjectName(QString::fromUtf8("actionC_mera"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame3 = new Q3Frame(centralWidget);
        frame3->setObjectName(QString::fromUtf8("frame3"));
        frame3->setGeometry(QRect(20, 0, 810, 650));
        frame3->setFrameShape(QFrame::StyledPanel);
        frame3->setFrameShadow(QFrame::Raised);
        groupBox2 = new Q3GroupBox(frame3);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        groupBox2->setGeometry(QRect(30, 320, 740, 320));
        pixmapN = new QLabel(groupBox2);
        pixmapN->setObjectName(QString::fromUtf8("pixmapN"));
        pixmapN->setGeometry(QRect(330, 120, 80, 90));
        pixmapN->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/N.png")));
        pixmapN->setScaledContents(true);
        pixmapN->setWordWrap(false);
        pixmapK = new QLabel(groupBox2);
        pixmapK->setObjectName(QString::fromUtf8("pixmapK"));
        pixmapK->setGeometry(QRect(90, 120, 80, 90));
        pixmapK->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/K.png")));
        pixmapK->setScaledContents(true);
        pixmapK->setWordWrap(false);
        pixmapM = new QLabel(groupBox2);
        pixmapM->setObjectName(QString::fromUtf8("pixmapM"));
        pixmapM->setGeometry(QRect(250, 120, 80, 90));
        pixmapM->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/M.png")));
        pixmapM->setScaledContents(true);
        pixmapM->setWordWrap(false);
        pixmapH = new QLabel(groupBox2);
        pixmapH->setObjectName(QString::fromUtf8("pixmapH"));
        pixmapH->setGeometry(QRect(570, 30, 80, 90));
        pixmapH->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/H.png")));
        pixmapH->setScaledContents(true);
        pixmapH->setWordWrap(false);
        pixmapB = new QLabel(groupBox2);
        pixmapB->setObjectName(QString::fromUtf8("pixmapB"));
        pixmapB->setGeometry(QRect(90, 30, 80, 90));
        pixmapB->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/B.png")));
        pixmapB->setScaledContents(true);
        pixmapB->setWordWrap(false);
        pixmapE = new QLabel(groupBox2);
        pixmapE->setObjectName(QString::fromUtf8("pixmapE"));
        pixmapE->setGeometry(QRect(330, 30, 80, 90));
        pixmapE->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/E.png")));
        pixmapE->setScaledContents(true);
        pixmapE->setWordWrap(false);
        pixmapF = new QLabel(groupBox2);
        pixmapF->setObjectName(QString::fromUtf8("pixmapF"));
        pixmapF->setGeometry(QRect(410, 30, 80, 90));
        pixmapF->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/F.png")));
        pixmapF->setScaledContents(true);
        pixmapF->setWordWrap(false);
        pixmapL = new QLabel(groupBox2);
        pixmapL->setObjectName(QString::fromUtf8("pixmapL"));
        pixmapL->setGeometry(QRect(170, 120, 80, 90));
        pixmapL->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/L.png")));
        pixmapL->setScaledContents(true);
        pixmapL->setWordWrap(false);
        pixmapG = new QLabel(groupBox2);
        pixmapG->setObjectName(QString::fromUtf8("pixmapG"));
        pixmapG->setGeometry(QRect(490, 30, 80, 90));
        pixmapG->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/G.png")));
        pixmapG->setScaledContents(true);
        pixmapG->setWordWrap(false);
        pixmapD = new QLabel(groupBox2);
        pixmapD->setObjectName(QString::fromUtf8("pixmapD"));
        pixmapD->setGeometry(QRect(250, 30, 80, 90));
        pixmapD->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/D.png")));
        pixmapD->setScaledContents(true);
        pixmapD->setWordWrap(false);
        pixmapA = new QLabel(groupBox2);
        pixmapA->setObjectName(QString::fromUtf8("pixmapA"));
        pixmapA->setGeometry(QRect(10, 30, 80, 90));
        pixmapA->setAutoFillBackground(true);
        pixmapA->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/A.png")));
        pixmapA->setScaledContents(true);
        pixmapA->setWordWrap(false);
        pixmapJ = new QLabel(groupBox2);
        pixmapJ->setObjectName(QString::fromUtf8("pixmapJ"));
        pixmapJ->setGeometry(QRect(10, 120, 80, 90));
        pixmapJ->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/J.png")));
        pixmapJ->setScaledContents(true);
        pixmapJ->setWordWrap(false);
        pixmapC = new QLabel(groupBox2);
        pixmapC->setObjectName(QString::fromUtf8("pixmapC"));
        pixmapC->setGeometry(QRect(170, 30, 80, 90));
        pixmapC->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/C.png")));
        pixmapC->setScaledContents(true);
        pixmapC->setWordWrap(false);
        pixmapP = new QLabel(groupBox2);
        pixmapP->setObjectName(QString::fromUtf8("pixmapP"));
        pixmapP->setGeometry(QRect(490, 120, 80, 90));
        pixmapP->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/P.png")));
        pixmapP->setScaledContents(true);
        pixmapP->setWordWrap(false);
        pixmapO = new QLabel(groupBox2);
        pixmapO->setObjectName(QString::fromUtf8("pixmapO"));
        pixmapO->setGeometry(QRect(410, 120, 80, 90));
        pixmapO->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/O.png")));
        pixmapO->setScaledContents(true);
        pixmapO->setWordWrap(false);
        pixmapQ = new QLabel(groupBox2);
        pixmapQ->setObjectName(QString::fromUtf8("pixmapQ"));
        pixmapQ->setGeometry(QRect(570, 120, 80, 90));
        pixmapQ->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/Q.png")));
        pixmapQ->setScaledContents(true);
        pixmapQ->setWordWrap(false);
        pixmapI = new QLabel(groupBox2);
        pixmapI->setObjectName(QString::fromUtf8("pixmapI"));
        pixmapI->setGeometry(QRect(650, 30, 80, 90));
        pixmapI->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/I.png")));
        pixmapI->setScaledContents(true);
        pixmapI->setWordWrap(false);
        pixmapR = new QLabel(groupBox2);
        pixmapR->setObjectName(QString::fromUtf8("pixmapR"));
        pixmapR->setGeometry(QRect(650, 120, 80, 90));
        pixmapR->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/R.png")));
        pixmapR->setScaledContents(true);
        pixmapR->setWordWrap(false);
        pixmapS = new QLabel(groupBox2);
        pixmapS->setObjectName(QString::fromUtf8("pixmapS"));
        pixmapS->setGeometry(QRect(10, 210, 80, 90));
        pixmapS->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/S.png")));
        pixmapS->setScaledContents(true);
        pixmapS->setWordWrap(false);
        pixmapT = new QLabel(groupBox2);
        pixmapT->setObjectName(QString::fromUtf8("pixmapT"));
        pixmapT->setGeometry(QRect(90, 210, 80, 90));
        pixmapT->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/T.png")));
        pixmapT->setScaledContents(true);
        pixmapT->setWordWrap(false);
        pixmapU = new QLabel(groupBox2);
        pixmapU->setObjectName(QString::fromUtf8("pixmapU"));
        pixmapU->setGeometry(QRect(170, 210, 80, 90));
        pixmapU->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/U.png")));
        pixmapU->setScaledContents(true);
        pixmapU->setWordWrap(false);
        pixmapV = new QLabel(groupBox2);
        pixmapV->setObjectName(QString::fromUtf8("pixmapV"));
        pixmapV->setGeometry(QRect(250, 210, 80, 90));
        pixmapV->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/V.png")));
        pixmapV->setScaledContents(true);
        pixmapV->setWordWrap(false);
        pixmapW = new QLabel(groupBox2);
        pixmapW->setObjectName(QString::fromUtf8("pixmapW"));
        pixmapW->setGeometry(QRect(330, 210, 80, 90));
        pixmapW->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/W.png")));
        pixmapW->setScaledContents(true);
        pixmapW->setWordWrap(false);
        pixmapX = new QLabel(groupBox2);
        pixmapX->setObjectName(QString::fromUtf8("pixmapX"));
        pixmapX->setGeometry(QRect(410, 210, 80, 90));
        pixmapX->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/X.png")));
        pixmapX->setScaledContents(true);
        pixmapX->setWordWrap(false);
        pixmapY = new QLabel(groupBox2);
        pixmapY->setObjectName(QString::fromUtf8("pixmapY"));
        pixmapY->setGeometry(QRect(490, 210, 80, 90));
        pixmapY->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/Y.png")));
        pixmapY->setScaledContents(true);
        pixmapY->setWordWrap(false);
        pixmapZ = new QLabel(groupBox2);
        pixmapZ->setObjectName(QString::fromUtf8("pixmapZ"));
        pixmapZ->setGeometry(QRect(570, 210, 80, 90));
        pixmapZ->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/Z.png")));
        pixmapZ->setScaledContents(true);
        pixmapZ->setWordWrap(false);
        pixmapIFSC = new QLabel(groupBox2);
        pixmapIFSC->setObjectName(QString::fromUtf8("pixmapIFSC"));
        pixmapIFSC->setGeometry(QRect(650, 210, 80, 90));
        pixmapIFSC->setPixmap(QPixmap(QString::fromUtf8("../../img/alpha_img/ifsc.png")));
        pixmapIFSC->setScaledContents(true);
        pixmapIFSC->setWordWrap(false);
        LanguageGroup = new Q3ButtonGroup(frame3);
        LanguageGroup->setObjectName(QString::fromUtf8("LanguageGroup"));
        LanguageGroup->setGeometry(QRect(500, 120, 270, 100));
        CB_Vocalize = new QCheckBox(LanguageGroup);
        CB_Vocalize->setObjectName(QString::fromUtf8("CB_Vocalize"));
        CB_Vocalize->setGeometry(QRect(170, 20, 93, 20));
        ListLanguage = new QComboBox(LanguageGroup);
        ListLanguage->setObjectName(QString::fromUtf8("ListLanguage"));
        ListLanguage->setGeometry(QRect(170, 50, 80, 30));
        CB_Translate = new QCheckBox(LanguageGroup);
        CB_Translate->setObjectName(QString::fromUtf8("CB_Translate"));
        CB_Translate->setGeometry(QRect(20, 20, 93, 20));
        TLLanguage = new QLabel(LanguageGroup);
        TLLanguage->setObjectName(QString::fromUtf8("TLLanguage"));
        TLLanguage->setGeometry(QRect(30, 50, 81, 21));
        TLLanguage->setWordWrap(false);
        recognizedWord = new Q3GroupBox(frame3);
        recognizedWord->setObjectName(QString::fromUtf8("recognizedWord"));
        recognizedWord->setGeometry(QRect(501, 240, 270, 70));
        TL_recWord = new QLineEdit(recognizedWord);
        TL_recWord->setObjectName(QString::fromUtf8("TL_recWord"));
        TL_recWord->setGeometry(QRect(10, 30, 200, 22));
        start = new QPushButton(frame3);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(670, 70, 100, 30));
        VideoWidget = new Phonon::VideoWidget(frame3);
        VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->setGeometry(QRect(30, 20, 411, 281));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 861, 27));
        menuIALIBRAS = new QMenu(menuBar);
        menuIALIBRAS->setObjectName(QString::fromUtf8("menuIALIBRAS"));
        menuOp_es = new QMenu(menuBar);
        menuOp_es->setObjectName(QString::fromUtf8("menuOp_es"));
        menuSObre = new QMenu(menuBar);
        menuSObre->setObjectName(QString::fromUtf8("menuSObre"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuIALIBRAS->menuAction());
        menuBar->addAction(menuOp_es->menuAction());
        menuBar->addAction(menuSObre->menuAction());
        menuIALIBRAS->addAction(actionIniciar);
        menuIALIBRAS->addAction(actionSair);
        menuOp_es->addAction(actionFiltros);
        menuOp_es->addAction(actionC_mera);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Int\303\251rprete Autom\303\241tico de Libras", 0, QApplication::UnicodeUTF8));
        actionIniciar->setText(QApplication::translate("MainWindow", "&Iniciar", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("MainWindow", "&Sair", 0, QApplication::UnicodeUTF8));
        actionFiltros->setText(QApplication::translate("MainWindow", "&Filtros", 0, QApplication::UnicodeUTF8));
        actionC_mera->setText(QApplication::translate("MainWindow", "&C\303\242mera", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QApplication::translate("MainWindow", "\303\232ltilma letra reconhecida:", 0, QApplication::UnicodeUTF8));
        LanguageGroup->setTitle(QString());
        CB_Vocalize->setText(QApplication::translate("MainWindow", "Vocalizar", 0, QApplication::UnicodeUTF8));
        ListLanguage->clear();
        ListLanguage->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "English", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Spanish", 0, QApplication::UnicodeUTF8)
        );
        CB_Translate->setText(QApplication::translate("MainWindow", "Traduzir", 0, QApplication::UnicodeUTF8));
        TLLanguage->setText(QApplication::translate("MainWindow", "Idioma:", 0, QApplication::UnicodeUTF8));
        recognizedWord->setTitle(QApplication::translate("MainWindow", "Palavra reconhecida", 0, QApplication::UnicodeUTF8));
        TL_recWord->setText(QApplication::translate("MainWindow", "Libras", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("MainWindow", "Iniciar", 0, QApplication::UnicodeUTF8));
        menuIALIBRAS->setTitle(QApplication::translate("MainWindow", "&IALIBRAS", 0, QApplication::UnicodeUTF8));
        menuOp_es->setTitle(QApplication::translate("MainWindow", "&Op\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        menuSObre->setTitle(QApplication::translate("MainWindow", "&Sobre", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
