 #include "mainwindow.h"
#include "datamanager.h"
#include "gameclass.h"
#include <QApplication>


/* global dataManager because this will contain all save data and needs to be kept together for simplicity. */
DataManager dataManager;
GameClass gameClass;
MainWindow *mainWindow;

#if !defined Q_OS_BLACKBERRY && !defined Q_OS_ANDROID && !defined Q_OS_IOS && !defined Q_OS_WP
#define Q_OS_DESKTOP /* some functionality is different on desktops and pretty reliable to set via QT.
                        QT standard paths to get the home directory, for instance. */
#endif

/*#else
#define Q_OS_MOBILE*/


/* { GLOBAL DEFINES */
/* change for your project. */


/* } END GLOBAL DEFINES */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
