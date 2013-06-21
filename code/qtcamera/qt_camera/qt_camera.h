#ifndef QT_CAMERA_H
#define QT_CAMERA_H

#include <QtGui/QMainWindow>
#include "ui_qt_camera.h"
#include "transmit.h"
#include <QtGui/QPixmap>
#include <QtCore/QVariant>
#include <QtGui/QDialog>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include "http_client.h"
#include <string>
#include "http_response.h"

class qt_camera : public QMainWindow
{
	Q_OBJECT

public:
	QHostAddress hostAddress;
	uint hostPort;
	transmit* myTransmit;

	qt_camera(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qt_camera();

signals:
	void gotAddress(QHostAddress*,uint*);
    void recv_response();

public slots:
	void showImage(QPixmap*);
	void connected_action();
    void connect_failed();
	void quit();
	void error(QAbstractSocket::SocketError);
	void connectToHost();
    void cheek_response();


	void goForwardBeg();
	void goForwardEnd();
	void goLeftBeg();
	void goLeftEnd();
	void goRightBeg();
	void goRightEnd();
	void goBackwardBeg();
	void goBackwardEnd();
	void speedChange(int);

	void HoldForwardBeg();
	void HoldForwardEnd();
	void HoldLeftBeg();
	void HoldLeftEnd();
	void HoldRightBeg();
	void HoldRightEnd();
	void HoldBackwardBeg();
	void HoldBackwardEnd();
	void HoldChange(int);

private:
	Ui::qt_cameraClass uiCamera;
	QImage image;
    HttpClient* hc;
    string address;
    string content_type;
   HttpResponse  response;

	bool getPort(QString);	
	bool get_tcp();
	void closeCamera();
};

#endif // QT_CAMERA_H
