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
    /*void setupGameButtons(QButtonGroup *btnGroup);*/
    const std::string gameNameShort="textGame1";
private:
    void disp(QString str);
    void append(QString str);

};

#endif // GAMECLASS_H
