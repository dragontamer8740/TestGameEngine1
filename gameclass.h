#ifndef GAMECLASS_H
#define GAMECLASS_H
#include "gameclass.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>



/*class GameClass */
class GameClass : public QObject
{
    Q_OBJECT

public:
    GameClass();
    /*void newGame(QTextBrowser *textField);*/
    void newGame();
    void setupGameUI(QTextBrowser *textField,Ui::MainWindow *ui);
    void setupButtons();
    /*void setupGameButtons(QButtonGroup *btnGroup);*/
    const std::string gameNameShort="textGame1";

    void btnPress(int btnNum);
    void addButton(int button, QString str, void *func);
    void clearButton(int button);
    void clearAllButtons();
    /* simplifies things a great deal from their older implementation */
    QPushButton *btn(int btnNum);

    void doNothing();

public slots:
    void selectRace(int race);
    void checkMail();
    void takeLetter();
    void createChar();


signals:
    void buttonClicked();

private:
    void disp(QString str);
    void append(QString str);

    /*void checkMail();*/


};



#endif // GAMECLASS_H
