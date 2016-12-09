#include "gameclass.h"
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <string>
#include <stdio.h>
#include <QString>

/*extern MainWindow::ui *ui;*/

/*extern MainWindow *mainWindow;*/

/*make these global, they will be assigned during initialization via setupGameUI().*/
QTextBrowser *txtField;
QPushButton *btns; /* we know we have 15 buttons */

GameClass::GameClass()
{
    const std::string gameNameShort="textGame1";
}

/* this is called when initializing the program. Without it we can't write to the text field easily.*/

void GameClass::setupGameUI(QTextBrowser *textField,QPushButton buttons[]){
    /* first let the game know where to write text to. The pointer is passed from the MainWindow.*/
    txtField=textField;
    btns=buttons;
/*    for(int i=0;i<14;i=i+1){
        btns[i].setText(" ");
    }*/

    /* next, write the intro text. */
    disp("<b>Text Game Engine V1</b><br/>"
         "\"<i>Filmed in </i>\"<br/>"
         "no rights reserved.");
}

/*void GameClass::setupGameButtons(QButtonGroup *btnGroup){
    buttonGroup=btnGroup;

}*/

void GameClass::disp(QString str)
{
    txtField->setText(str);
}

void GameClass::append(QString str)
{
    txtField->append(str);
}

void GameClass::newGame()
{
    disp("You are standing in an open field west of a white house, with a boarded front door.<br/>"
                       "There is a small mailbox here.");
    btns[0].setText("Check for Mail");
    Player player=Player();
    /* player.setClassType();*/
}
