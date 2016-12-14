#ifndef GAMECLASS_H
#define GAMECLASS_H
#include "gameclass.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>



class GameClass
{
public:
    GameClass();
    /*void newGame(QTextBrowser *textField);*/
    void newGame();
    void setupGameUI(QTextBrowser *textField,QPushButton buttons[]);
    void setupButtons();
    /*void setupGameButtons(QButtonGroup *btnGroup);*/
    const std::string gameNameShort="textGame1";

    void btnPress(int btnNum);
    void addButton(int button, QString str, void *func);
    void clearButton(int button);
    void clearAllButtons();

    /* hopefully this simplifies stuff */
    /*void (GameClass::*btnPtr[15])();*/


    void (GameClass::*btn0)()=NULL;
    void (GameClass::*btn1)()=NULL;
    void (GameClass::*btn2)()=NULL;
    void (GameClass::*btn3)()=NULL;
    void (GameClass::*btn4)()=NULL;
    void (GameClass::*btn5)()=NULL;
    void (GameClass::*btn6)()=NULL;
    void (GameClass::*btn7)()=NULL;
    void (GameClass::*btn8)()=NULL;
    void (GameClass::*btn9)()=NULL;
    void (GameClass::*btn10)()=NULL;
    void (GameClass::*btn11)()=NULL;
    void (GameClass::*btn12)()=NULL;
    void (GameClass::*btn13)()=NULL;
    void (GameClass::*btn14)()=NULL;
    void doNothing();

private:
    void disp(QString str);
    void append(QString str);

    void checkMail();
    void takeLetter();
};



#endif // GAMECLASS_H
