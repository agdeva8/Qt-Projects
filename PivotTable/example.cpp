/*
 * example.cpp
 *
 *  Created on: 2016. 6. 13.
 *      Author: pize
 */
#include <QtWidgets>
#include <QApplication>
#include "RbWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	RbWindow window;
	window.resize(600,300);
	window.show();
	return app.exec();
}
