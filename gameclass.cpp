#include "gameclass.h"
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <string>
#include <stdio.h>
#include <QString>

/*make these global, they will be assigned during initialization via setupGameUI().*/
QTextBrowser *txtField;
QPushButton *btn; /* we know we have 15 buttons */


/* jesus christ how horrifying.
 * If anyone wants to make this less horrible, I'm open to fixes.
 * these are function pointers that can be reassigned at will to make the buttons
 * do different things in different circumstances. */
/*
 * void (GameClass::*btn0)();
void (GameClass::*btn1)();
void (GameClass::*btn2)();
void (GameClass::*btn3)();
void (GameClass::*btn4)();
void (GameClass::*btn5)();
void (GameClass::*btn6)();
void (GameClass::*btn7)();
void (GameClass::*btn8)();
void (GameClass::*btn9)();
void (GameClass::*btn10)();
void (GameClass::*btn11)();
void (GameClass::*btn12)();
void (GameClass::*btn13)();
void (GameClass::*btn14)();*/
/*void (*btn0)();*/
void (GameClass::*btn0)();
void (GameClass::*btn1)();
void (GameClass::*btn2)();
void (GameClass::*btn3)();
void (GameClass::*btn4)();
void (GameClass::*btn5)();
void (GameClass::*btn6)();
void (GameClass::*btn7)();
void (GameClass::*btn8)();
void (GameClass::*btn9)();
void (GameClass::*btn10)();
void (GameClass::*btn11)();
void (GameClass::*btn12)();
void (GameClass::*btn13)();
void (GameClass::*btn14)();
/* set these to point to doNothing() until made to point otherwise */

/* easy access */
/*void (GameClass::*btnPtr[])() = {*/
void (GameClass::*btnPtr[])() = {
        btn0,btn1,btn2,btn3,btn4,
        btn5,btn6,btn7,btn8,btn9,
        btn10,btn11,btn12,btn13,btn14
        };

/* TODO: this could probably just be replaced with a call to clearAllButtons(). */
void GameClass::setupButtons(){
    for(int i = 0; i < 15; i++)
    {
        btnPtr[i]=&GameClass::doNothing;
        /*btnPtr[i]=&doNothing;*/

        /*btn[i].setEnabled(false);*/
    }
}


/* turns out implementing this is next to impossible due to the stupid class system.
   (I can't get the function 'func' to exist in the GameClass namespace apparently)
   Just set btnPtr[x] directly, I guess.*/

/*void GameClass::addButton(int button, QString str, void *func  ){
        btn[button].setText(str);
        btnPtr[button]=func;
}*/

void GameClass::clearButton(int button){
    btnPtr[button]=&GameClass::doNothing;
    btn[button].setText("");
    btn[button].setEnabled(false);
}

/* blank all buttons. */
void GameClass::clearAllButtons(){
    for(int i = 0; i < 15; i++)
    {
        btnPtr[i]=&GameClass::doNothing;
        /*btnPtr[i]=&doNothing;*/
        btn[i].setText("");
        btn[i].setEnabled(false);
    }
}

GameClass::GameClass()
{
    const std::string gameNameShort="textGame1";
}

/* this is called when initializing the program. Without it we can't write to the text field easily.*/

void GameClass::setupGameUI(QTextBrowser *textField,QPushButton buttons[]){
    /* first let the game know where to write text to. The pointer is passed from the MainWindow.*/
    txtField=textField;
    btn=buttons;
    GameClass::setupButtons();
    /* allow opening links externally */
    textField->setOpenExternalLinks(true);

    /* next, write the intro text. */
    disp("<b>Text Game Engine V1</b><br/>"
         "\"<i>Filmed in Technicolor!</i>\"<br/>"
         "no rights reserved.");
}


void GameClass::disp(QString str)
{
    txtField->setText(str);
}

void GameClass::append(QString str)
{
    txtField->append(str);
}

/* button handling. This is probably a little overcomplicated. */
void GameClass::btnPress(int btnNum){
    (*this.*btnPtr[btnNum])();
    /*(*btnPtr[btnNum])();*/
}

/*void GameClass::doNothing(){*/
void GameClass::doNothing(){
    /* and look good doing it. This function exists to prevent crashing when no button action is defined.*/
    /* in the future I should disable the buttons instead. */
}

/* ---------------------- IMPLEMENTATION DETAILS END HERE ---------------------- */

/* ======================== GAME EVENT CODE STARTS HERE ======================== */

/* this is likely to get split off further into another file at some point in time
   (via '#include gameEvents.cpp' or something like that.) */

void GameClass::newGame()
{
    disp("You are standing in an open field west of a white house, with a boarded front door.<br/>"
                       "There is a small mailbox here.");

    /* set text on button 0 (top left).*/
    btn[0].setText("Open mailbox");

    /* set function that button 0 should call. */
    btnPtr[0]=&GameClass::checkMail;






    /* create a player */
    Player player=Player();

    /* player.setClassType();*/
}

void GameClass::checkMail(){
    append("<br/>"
           "You open the mailbox. A songbird flies out and yells:<br/>"
           "<i>WELCOME TO TEXT GAME ENGINE 1!<br/>"
           "THIS ENGINE SUCKS RIGHT NOW, BUT WE CAN MAKE IT BETTER TOGETHER. FEEL FREE TO HELP!</i><br/>"
           "<br/>"
           "You're pretty bewildered by the spontaneous appearance of a yelling bird speaking "
           "fluent english, but when the bird comes down to rest on top of the mailbox, you see it has "
           "an envelope clipped to its left leg. It looks at you intently and tilts its head, clearly "
           "waiting for you to take its message.");
    btn[0].setText("Take letter");
    btnPtr[0]=&GameClass::takeLetter;
}

void GameClass::takeLetter(){
    append("<br/>You take the letter from the strange bird, and it bellows: <i>\"BE SURE TO MAKE SUGGESTIONS! I'LL GIVE "
           "YOUR MESSAGES TO THE DEVELOPER IF YOU REPORT ISSUES AT THE SITE ON THE NOTE!\"</i><br/>--And with that, the "
           "strange bird flies off. Odd.<br/><br/>"
           "You see that the bird's note contains nothing save a URL:<br/>"
           "<a href=\"https://github.com/dragontamer8740/TestGameEngine1\">https://github.com/dragontamer8740/TestGameEngine1</a>");
    btn[0].setText("(end)");
    btnPtr[0]=&GameClass::doNothing;
    /*btnPtr[0]=&doNothing;*/
}
