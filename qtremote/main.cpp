#include <QApplication>
// #include <QWidget>
// #include <QtWidgets>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
	
	QApplication app(argc, argv);
	MainWindow w;
	w.show();

	qDebug("Application started");

	return app.exec();
}
