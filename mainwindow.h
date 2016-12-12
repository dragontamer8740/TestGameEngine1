#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gameclass.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    void textWrite(QString str);
    void textClear();
    void displayText(QString str);

private slots:
    void on_comboSaveSlotSelect_currentIndexChanged(int index);

    void on_btnSave_clicked();

    void on_btnNewGame_clicked();

    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btn10_clicked();

    void on_btn11_clicked();

    void on_btn12_clicked();

    void on_btn13_clicked();

    void on_btn14_clicked();

private:

};

#endif // MAINWINDOW_H
