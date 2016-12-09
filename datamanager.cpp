/* A Data manager class that contains ALL THE DATA. */
/* (because screw encapsulation!) */

/* Handles serializing and de-serializing data into a JSON string. Save data is stored in JSON for easy editing. */

#include "datamanager.h"
#include "gameclass.h"
#include "mainwindow.h"
#include <string>
#include <iostream>
#include <stdio.h>

#include <QMainWindow>
#include <QStandardPaths>
#include <QDir> /* for mkdir */
#include <QMessageBox>

/* JSON */
#include <QJsonArray>
#include <QJsonDocument>

QDir dir;


int slotNumber; /* set with setSaveSlot(), retrieved with getSaveSlot(). */

extern GameClass gameClass;

DataManager::DataManager()
{
    printf("constructor called\n");

}

int DataManager::getSaveSlot(){ /* get index of currently selected save slot */
    return slotNumber;
}

void DataManager::setSaveSlot(int index){ /* set index of currently selected save slot */
    slotNumber = index + 1; /* dropdown index starts at 0 */
}

int DataManager::quickSave(int slot){
    /* quicksaves go in ~/.{gameNameShort} */
    std::string savePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation).toStdString()
            + "/." + gameClass.gameNameShort;

    /* make sure directory exists */
    printf("trying to make save directory %s\n",savePath.c_str());
    bool ok = dir.mkpath(QString::fromStdString(savePath));     //this function creates the path, with all its necessary parents;
    if(!ok)
    {
        //error message, could not create the required directory structure!
         /*QMessageBox::critical(this, "Error!", "Error creating directory structure");*/
        QMessageBox Msgbox;
        Msgbox.setText("Error creating save directory " +
                       QString::fromStdString(savePath) +
                       ". Do you have permissions in your home directory?");
        Msgbox.exec();
        return 1;
    }
    return 0;


}

/* overload << and >> for reading and writing formatted text */

/* DataManager::& operator<<(std::ostream& os, const Movie& movie) {
  // Insert everything you want into `os`
  return os;
}*/
