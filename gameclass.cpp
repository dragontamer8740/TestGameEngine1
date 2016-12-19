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
Ui::MainWindow *win;

/* easy function to access game buttons by number, e.g. btn(0) */
QPushButton *GameClass::btn(int btnNum){
   switch(btnNum){
   case 0:
       return win->btn0; break;
   case 1:
       return win->btn1; break;
   case 2:
       return win->btn2; break;
   case 3:
       return win->btn3; break;
   case 4:
       return win->btn4; break;
   case 5:
       return win->btn5; break;
   case 6:
       return win->btn6; break;
   case 7:
       return win->btn7; break;
   case 8:
       return win->btn8; break;
   case 9:
       return win->btn9; break;
   case 10:
       return win->btn10; break;
   case 11:
       return win->btn11; break;
   case 12:
       return win->btn12; break;
   case 13:
       return win->btn13; break;
   case 14:
       return win->btn14; break;
   }

}

/* TODO: this could probably just be replaced with a call to clearAllButtons(). */
void GameClass::setupButtons(){
    for(int i = 0; i < 15; i++)
    {
         /*QObject::disconnect(win->btn0,SIGNAL(clicked()),0,0);*/
        QObject::disconnect(btn(i),SIGNAL(clicked()),0,0);
         /*QObject::disconnect()*/
        /*btnPtr[i]=&GameClass::doNothing;*/

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
    /*btnPtr[button]=&GameClass::doNothing;*/
    QObject::disconnect(btn(button),SIGNAL(clicked()),0,0);
    btn(button)->setText("");
    btn(button)->setEnabled(false);
}

/* blank all buttons. */
void GameClass::clearAllButtons(){
    for(int i = 0; i < 15; i++)
    {
        QObject::disconnect(btn(i),SIGNAL(clicked()),0,0);
        /*btnPtr[i]=&GameClass::doNothing;*/
        /*btnPtr[i]=&doNothing;*/
        btn(i)->setText("");
        btn(i)->setEnabled(false);
    }
}

GameClass::GameClass()
{
    const std::string gameNameShort="textGame1";
}

/* this is called when initializing the program. Without it we can't write to the text field easily.*/

void GameClass::setupGameUI(QTextBrowser *textField,QPushButton buttons[],Ui::MainWindow *window){
    /* first let the game know where to write text to. The pointer is passed from the MainWindow.*/
    txtField=textField;
    /*btn=buttons;*/
    /* actually let's just pass the entire mainwindow in */
    win=window;

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
/*void GameClass::btnPress(int btnNum){
//    (*this.*btnPtr[btnNum])();

}*/

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
    btn(0)->setText("Open mailbox");

    /* set function that button 0 should call. */
    QObject::connect(btn(0),SIGNAL(clicked()),this,SLOT(checkMail()));

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
    btn(0)->setText("Take letter");
    QObject::disconnect(btn(0),SIGNAL(clicked()),0,0);
    /* win->btn0 is the same as btn(0)*/
    QObject::connect(btn(0),SIGNAL(clicked()),this,SLOT(takeLetter()));
    /*btnPtr[0]=&GameClass::takeLetter;*/
}

void GameClass::takeLetter(){
    append("<br/>You take the letter from the strange bird, and it bellows: <i>\"BE SURE TO MAKE SUGGESTIONS! I'LL GIVE "
           "YOUR MESSAGES TO THE DEVELOPER IF YOU REPORT ISSUES AT THE SITE ON THE NOTE!\"</i><br/>--And with that, the "
           "strange bird flies off. Odd.<br/><br/>"
           "You see that the bird's note contains nothing save a URL:<br/>"
           "<a href=\"https://github.com/dragontamer8740/TestGameEngine1\">https://github.com/dragontamer8740/TestGameEngine1</a>");
    btn(0)->setText("CreateChar");
    QObject::disconnect(btn(0),SIGNAL(clicked()),0,0);
    QObject::connect(btn(0),SIGNAL(clicked()),this,SLOT(createChar()));
}

/* 'race' is an integer value internally. */
#define HUMAN 0
#define ELF 1
#define DEMON 2
#define ANGEL 3
#define DWARF 4
#define ATTACK_HELICOPTER 5

void GameClass::createChar(){
    disp("Okay, let's get a little serious now.<br/>"
         "What best describes your race?<br/>");
    btn(0)->setText("Human");
    btn(0)->setToolTip("You're a human, with relatively average base stats in all fields.");
    GameClass::selectRace(HUMAN);
/*QObject::connect()*/
    QObject::connect(btn(0),SIGNAL(clicked()),this,SLOT(selectRace(HUMAN)));

    btn(1)->setText("Elf");
    QObject::connect(btn(1),SIGNAL(clicked()),this,SLOT(selectRace(ELF)));

    btn(2)->setText("Demon");
    QObject::connect(btn(2),SIGNAL(clicked()),this,SLOT(selectRace(DEMON)));

    btn(3)->setText("Angel");
    QObject::connect(btn(3),SIGNAL(clicked()),this,SLOT(selectRace(ANGEL)));

    btn(4)->setText("Dwarf");
    QObject::connect(btn(4),SIGNAL(clicked()),this,SLOT(selectRace(DWARF)));

    btn(5)->setText("Apache Helicopter");
    QObject::connect(btn(5),SIGNAL(clicked()),this,SLOT(selectRace(ATTACK_HELICOPTER)));
}

void GameClass::selectRace(int race){
    printf("you chose %d\n");
}

/*btnPtr[0]=&GameClass:createChar();*/

/*win->ui->btn0->connect();*/
/*QObject::connect(win->ui->btn0,SIGNAL(clicked()),this,SIGNAL(buttonClicked()));*/
