#include "qt_camera.h"

qt_camera::qt_camera(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{	
	myTransmit = new transmit();
	uiCamera.setupUi(this);
    uiCamera.lineEdit_6->setText("192.168.1.22");
    uiCamera.lineEdit_7->setText("80");
    content_type = "text/html";
	this->show();
	
	connect(myTransmit,SIGNAL(recived(QPixmap*)),this,SLOT(showImage(QPixmap*)));
	connect(myTransmit,SIGNAL(tcpConnect()),this,SLOT(connected_action()));
	connect(uiCamera.pushButton,SIGNAL(clicked()),this,SLOT(connectToHost()));
	connect(uiCamera.pushButton_2,SIGNAL(clicked()),this,SLOT(quit()));
//	connect(this,SIGNAL(gotAddress((QHostAddress,uint))),myTransmit,SLOT(setAddress(QHostAddress,uint)));
    connect(&(myTransmit->tcpSocket), SIGNAL(connected()),this, SLOT(connected_action()));
	connect(&(myTransmit->tcpSocket), SIGNAL(error(QAbstractSocket::SocketError)),
			this, SLOT(error(QAbstractSocket::SocketError)));
    connect(myTransmit,SIGNAL(tcpConnectFailed()),this,SLOT(connect_failed()));
    connect(this,SIGNAL(recv_response()),this,SLOT(cheek_response()));

	//button control
	connect(uiCamera.pushButton_3,SIGNAL(pressed()),this,SLOT(goForwardBeg()));
	connect(uiCamera.pushButton_3,SIGNAL(released()),this,SLOT(goForwardEnd()));
	connect(uiCamera.pushButton_4,SIGNAL(pressed()),this,SLOT(goLeftBeg()));
	connect(uiCamera.pushButton_4,SIGNAL(released()),this,SLOT(goLeftEnd()));
	connect(uiCamera.pushButton_5,SIGNAL(pressed()),this,SLOT(goRightBeg()));
	connect(uiCamera.pushButton_5,SIGNAL(released()),this,SLOT(goRightEnd()));
	connect(uiCamera.pushButton_6,SIGNAL(pressed()),this,SLOT(goBackwardBeg()));
	connect(uiCamera.pushButton_6,SIGNAL(released()),this,SLOT(goBackwardEnd()));
	connect(uiCamera.spinBox,SIGNAL(valueChanged(int)),this,SLOT(speedChange(int)));

	connect(uiCamera.pushButton_10,SIGNAL(pressed()),this,SLOT(HoldForwardBeg()));
	connect(uiCamera.pushButton_10,SIGNAL(released()),this,SLOT(HoldForwardEnd()));
	connect(uiCamera.pushButton_9,SIGNAL(pressed()),this,SLOT(HoldLeftBeg()));
	connect(uiCamera.pushButton_9,SIGNAL(released()),this,SLOT(HoldLeftEnd()));
	connect(uiCamera.pushButton_7,SIGNAL(pressed()),this,SLOT(HoldRightBeg()));
	connect(uiCamera.pushButton_7,SIGNAL(released()),this,SLOT(HoldRightEnd()));
	connect(uiCamera.pushButton_8,SIGNAL(pressed()),this,SLOT(HoldBackwardBeg()));
	connect(uiCamera.pushButton_8,SIGNAL(released()),this,SLOT(HoldBackwardEnd()));
	connect(uiCamera.spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(HoldChange(int)));

}

qt_camera::~qt_camera()
{
	delete(myTransmit);
}


void qt_camera::quit()
{
	//
	myTransmit->runing = 0;
	myTransmit->wait();
	this->close();
}


void qt_camera::showImage(QPixmap *pixmap)
{	//myTransmit->mutex.lock();
	uiCamera.screan->setPixmap(*pixmap);
//ui.camera->setPixmap(myTransmit->pixmap);
	//myTransmit->mutex.unlock();
}


bool qt_camera::getPort(QString str)
{
	bool ok;
	int port = str.toInt(&ok,10);
	if (!ok) return false;
	if(port > 0)
		hostPort = port;
	else 
		return false;
	return true;
}


bool qt_camera::get_tcp()
{
	QString addr = uiCamera.lineEdit_6->text();
	if(!(hostAddress.setAddress(addr)))
	{
		uiCamera.label_11->setText("IPAddress is wrong");
		return false;
	}

    address = uiCamera.lineEdit_6->text().toUtf8().constData();
	QString port = uiCamera.lineEdit_7->text();
	if(!getPort(port))
	{
		uiCamera.label_11->setText("Please check the port you typed in");
		return false;
	}
	return true;
}


void qt_camera::connectToHost()
{
	if(!get_tcp())
		return;
    //myTransmit->address = hostAddress;
    //myTransmit->port = hostPort;
    hc = new HttpClient(address,(int)hostPort);
	uiCamera.label_11->setText("Connecting!!!");
    myTransmit->start();
}

void qt_camera::connect_failed()
{
    uiCamera.label_11->setText(("Connection Timeout"));
}


void qt_camera::cheek_response()
{

}

void  qt_camera::error(QAbstractSocket::SocketError err)
{
	uiCamera.label_11->setText( "Error occurred: " + myTransmit->tcpSocket.errorString());
}

void  qt_camera::connected_action()
{
	uiCamera.label_11->setText( "Success!!!");
}


void qt_camera::goForwardBeg()
{
    response = hc->Put("/users/1/devices/1/command/1",content_type,"[mf]");
    emit recv_response();
}

void qt_camera::goForwardEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[mt]");
    emit recv_response();
}

void qt_camera::goLeftBeg()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[ml]");
    emit recv_response();
}

void qt_camera::goLeftEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[mt]");
    emit recv_response();
}

void qt_camera::goRightBeg()
{
    response =  hc->Put("/users/1/devices/1/command/1",content_type,"[mr]");
    emit recv_response();
}

void qt_camera::goRightEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[mt]");
    emit recv_response();
}

void qt_camera::goBackwardBeg()
{
    response =  hc->Put("/users/1/devices/1/command/1",content_type,"[mb]");
    emit recv_response();
}

void qt_camera::goBackwardEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[mt]");
    emit recv_response();
}

void qt_camera::speedChange(int num)
{
	switch (num)
	{
    case 0:
        response =  hc->Put("/users/1/devices/1/command/1",content_type,"[ms0]");
		break;
    case 1:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[ms1]");
		break;
    case 2:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[ms2]");
		break;
    case 3:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[ms3]");
		break;
	default:
		break;

    }
        emit recv_response();
}


///////////////////////////////////////////////////////////

void qt_camera::HoldForwardBeg()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[hu]");
    emit recv_response();
}

void qt_camera::HoldForwardEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[ht]");
    emit recv_response();
}

void qt_camera::HoldLeftBeg()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[hl]");
    emit recv_response();
}

void qt_camera::HoldLeftEnd()
{
     response =   hc->Put("/users/1/devices/1/command/1",content_type,"[ht]");
    emit recv_response();
}

void qt_camera::HoldRightBeg()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[hr]");
    emit recv_response();
}

void qt_camera::HoldRightEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[ht]");
    emit recv_response();
}

void qt_camera::HoldBackwardBeg()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[hd]");
    emit recv_response();
}

void qt_camera::HoldBackwardEnd()
{
     response = hc->Put("/users/1/devices/1/command/1",content_type,"[ht]");
    emit recv_response();
}

void qt_camera::HoldChange(int num)
{
	switch (num)
	{
    case 0:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[hs0]");
		break;
    case 1:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[hs1]");
		break;
    case 2:
         response = hc->Put("/users/1/devices/1/command/1",content_type,"[hs2]");
		break;
	default:
		break;
	}
        emit recv_response();
}
