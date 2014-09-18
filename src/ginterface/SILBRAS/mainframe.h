#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QDialog>

namespace Ui {
class MainFrame;
}

class MainFrame : public QDialog
{
    Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();

private:
    Ui::MainFrame *ui;
};

#endif // MAINFRAME_H
