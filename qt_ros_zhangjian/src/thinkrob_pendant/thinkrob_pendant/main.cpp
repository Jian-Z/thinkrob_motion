/**
 * @file /qlistener/main.cpp
 *
 * @brief Qt based gui.
 *
 * @date November 2010
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QApplication>
#include "../common/main_window.hpp"
#include "listener.hpp"
#include "../common/res.hpp"

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    /*********************
    ** Qt
    **********************/
    QApplication app(argc, argv);
    Listener listener(argc,argv);
    listener.on_init("http://192.168.3.188:11311/", "192.168.3.195");
    MainWindow w(&listener);
    w.move(WINDOW_ORIGIN_X, WINDOW_ORIGIN_Y);
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

	return result;
}
