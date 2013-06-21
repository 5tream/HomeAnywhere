#include "qt_camera.h"
#include <QtGui/QApplication>


int main(int argc, char *argv[])
{
	QApplication::addLibraryPath("./plugins");
	QApplication a(argc, argv);
	qt_camera w;
	return a.exec();
}
