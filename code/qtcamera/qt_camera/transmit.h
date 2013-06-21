#ifndef TRANSMIT_H
#define TRANSMIT_H
#include <QThread>
#include <QMutex>
#include <QtNetwork/QTcpSocket>
#include <QtGui>
#include "ui_qt_camera.h"
#include <QtNetwork/QHostAddress>

#define PICTRUE			0001
#define MOTOR			0002
#define HOLDER			0003
#define ULTRASONIC_L	0004			//³¬Éù²¨×ó
#define ULTRASONIC_M	0005			//³¬Éù²¨ÖÐ
#define ULTRASONIC_R	0006			//³¬Éù²¨ÓÒ
class qt_camera;
class transmit: public QThread
{
	Q_OBJECT
public:
	
	QTcpSocket tcpSocket;
	char buffer[320*240];
	QMutex mutex;
	QPixmap pixmap;
	QHostAddress address;
	uint port;
	qt_camera* camera_window;
	transmit();
	~transmit();
	void run();
	int runing;
public slots:
	void setAddress(QHostAddress*,uint*);



signals:
	void recived(QPixmap*);
	void tcpConnect();
    void tcpConnectFailed();
	//void connected();
protected:

private:

private slots:

};









#endif
