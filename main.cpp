/****************************************************************************
**
**   Vlad Estivill_Catsro trivial Qt GUI for PackMa			n
**
****************************************************************************/

#include <QApplication>
#include "Controller.h"

 int main(int argc, char *argv[])
 {
        QApplication app(argc, argv);

        Controller *controller = new Controller;

	controller->show();

        int return_value = app.exec();

	delete controller;

	return return_value;
 }
