#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datamanager.h"
#include "gameclass.h"
#include <QButtonGroup>
#include <stdio.h>

/* include data manager basically everywhere */
#include "datamanager.h"
extern DataManager dataManager;
extern GameClass gameClass;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 1; i <= 10; i++)
    {
        ui -> comboSaveSlotSelect -> addItem("Slot "+QString::number(i), i);
    }
    /* notify gameClass where some pointers are. It needs to know.*/

    /* there has to be a nicer way to do game buttons. */
    QPushButton* btns[]={this->ui->btn0,this->ui->btn1,this->ui->btn2,
                        this->ui->btn3,this->ui->btn4,this->ui->btn5,
                        this->ui->btn6,this->ui->btn7,this->ui->btn8,
                        this->ui->btn9,this->ui->btn10,this->ui->btn11,
                        this->ui->btn12,this->ui->btn13,this->ui->btn14};


    gameClass.setupGameUI(this->ui->textField,*btns);
/*gameClass.setup*/
    /*this->ui->btn*/

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboSaveSlotSelect_currentIndexChanged(int index)
{
    /*printf("%d\n",index);*/

    dataManager.setSaveSlot(index);
    printf("%d\n",dataManager.getSaveSlot());
}


void MainWindow::on_btnSave_clicked()
{
    dataManager.quickSave(dataManager.getSaveSlot());
}


void MainWindow::on_btnNewGame_clicked()
{
    /*gameClass.newGame(this->ui->textField);*/
    gameClass.newGame();
}

/*void MainWindow::setTextField(){
    gameClass.newGame(this->ui->textField);
}*/

/*static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked);*/
/*QButtonGroup::buttonClicked(int)*/
