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

void GameClass::setupButtons(){
    btn0=&GameClass::doNothing;
    btn1=&GameClass::doNothing;
    btn2=&GameClass::doNothing;
    btn3=&GameClass::doNothing;
    btn4=&GameClass::doNothing;
    btn5=&GameClass::doNothing;
    btn6=&GameClass::doNothing;
    btn7=&GameClass::doNothing;
    btn8=&GameClass::doNothing;
    btn9=&GameClass::doNothing;
    btn10=&GameClass::doNothing;
    btn11=&GameClass::doNothing;
    btn12=&GameClass::doNothing;
    btn13=&GameClass::doNothing;
    btn14=&GameClass::doNothing;

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

/* button handling. This is horrific. */
void GameClass::btnPress(int btnNum){
    /* this is horrifying and could probably be done better with an array. */
    switch(btnNum)
    {
    case 0:  (*this.*btn0)();  break;
    case 1:  (*this.*btn1)();  break;
    case 2:  (*this.*btn2)();  break;
    case 3:  (*this.*btn3)();  break;
    case 4:  (*this.*btn4)();  break;
    case 5:  (*this.*btn5)();  break;
    case 6:  (*this.*btn6)();  break;
    case 7:  (*this.*btn7)();  break;
    case 8:  (*this.*btn8)();  break;
    case 9:  (*this.*btn9)();  break;
    case 10: (*this.*btn10)(); break;
    case 11: (*this.*btn11)(); break;
    case 12: (*this.*btn12)(); break;
    case 13: (*this.*btn13)(); break;
    case 14: (*this.*btn14)(); break;
    }
}

void GameClass::doNothing(){
    /* and look good doing it. This function exists to prevent crashing when no button action is defined.*/
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
    btn0=&GameClass::checkMail;






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
    btn0=&GameClass::takeLetter;
}

void GameClass::takeLetter(){
    append("<br/>You take the letter from the strange bird, and it bellows: <i>\"BE SURE TO MAKE SUGGESTIONS! I'LL GIVE "
           "YOUR MESSAGES TO THE DEVELOPER IF YOU REPORT ISSUES AT THE SITE ON THE NOTE!\"</i><br/>--And with that, the "
           "strange bird flies off. Odd.<br/><br/>"
           "You see that the bird's note contains nothing save a URL:<br/>"
           "<a href=\"https://github.com/dragontamer8740/TestGameEngine1\">https://github.com/dragontamer8740/TestGameEngine1</a>");
    btn[0].setText("(end)");
    btn0=&GameClass::doNothing;
}
