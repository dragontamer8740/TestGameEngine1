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

    /*void on_btnGroup_clicked();*/
private:

};

#endif // MAINWINDOW_H
