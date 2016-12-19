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
/*    QPushButton* btn[]={this->ui->btn0,this->ui->btn1,this->ui->btn2,
                        this->ui->btn3,this->ui->btn4,this->ui->btn5,
                        this->ui->btn6,this->ui->btn7,this->ui->btn8,
                        this->ui->btn9,this->ui->btn10,this->ui->btn11,
                        this->ui->btn12,this->ui->btn13,this->ui->btn14};*/


    gameClass.setupGameUI(this->ui->textField,this->ui);
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
/*
void MainWindow::on_btn0_clicked(){
    gameClass.btnPress(0);}

void MainWindow::on_btn1_clicked(){
    gameClass.btnPress(1);}

void MainWindow::on_btn2_clicked(){
    gameClass.btnPress(2);}

void MainWindow::on_btn3_clicked(){
    gameClass.btnPress(3);}

void MainWindow::on_btn4_clicked(){
    gameClass.btnPress(4);}

void MainWindow::on_btn5_clicked(){
    gameClass.btnPress(5);}

void MainWindow::on_btn6_clicked(){
    gameClass.btnPress(6);}

void MainWindow::on_btn7_clicked(){
    gameClass.btnPress(7);}

void MainWindow::on_btn8_clicked(){
    gameClass.btnPress(8);}

void MainWindow::on_btn9_clicked(){
    gameClass.btnPress(9);}

void MainWindow::on_btn10_clicked(){
    gameClass.btnPress(10);}

void MainWindow::on_btn11_clicked(){
    gameClass.btnPress(11);}

void MainWindow::on_btn12_clicked(){
    gameClass.btnPress(12);}

void MainWindow::on_btn13_clicked(){
    gameClass.btnPress(13);}

void MainWindow::on_btn14_clicked(){
    gameClass.btnPress(14);}



*/
