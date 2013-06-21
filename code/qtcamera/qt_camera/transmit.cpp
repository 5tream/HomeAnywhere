#include "transmit.h"
#include "qdebug.h"
#include "qt_camera.h"
#include <QtNetwork/QHostAddress>
transmit::transmit()// :QThread()
{
    address.setAddress("192.168.1.22");
    port =5555;
}

transmit::~transmit()
{

}

void transmit::setAddress(QHostAddress *add,uint* port_num)
{
	address = *add;
	port = *port_num;
}

void transmit::run()
{
	int size;
	int type=1;
	QImage image_recv;
	char* point;
	int sum,num,temp;
	bool state = false;
	tcpSocket.connectToHost(address,port);
    int times = 0;
    while((!state))//&&(times<5000))
    {
		state = tcpSocket.waitForConnected(50);
        times++;
    }
   // if(times = 5000)
    {
    //    emit tcpConnectFailed();
     //   return;
    }
    emit tcpConnect();
	runing = 1;
	while(runing)
	{
		while(tcpSocket.bytesAvailable() < sizeof(int))
			tcpSocket.waitForReadyRead(50);
        tcpSocket.read((char*)&size,sizeof(int));
		//	qDebug("Read");
		switch(type)
		{
			case PICTRUE:
				{
					mutex.lock();
					//in this part we receive a picture
					while(tcpSocket.bytesAvailable() < sizeof(int))
						tcpSocket.waitForReadyRead(50);
					tcpSocket.read((char*)&size,sizeof(int));
					point = buffer;
                    sum = 0;num =0;temp=0;
					while(sum < size)
					{
						temp = tcpSocket.bytesAvailable();
						tcpSocket.waitForReadyRead(50);
						if ( temp> size-num) 
							temp =(size-num);
						if (temp > 0)
						{
							num = tcpSocket.read(point,temp);
							sum += num;
							point += num;
						}
					}
					//transform the picture we recived and show it
					image_recv.loadFromData((uchar*)buffer,size,"JPG");
					pixmap = QPixmap::fromImage( image_recv.scaled(420,280, Qt::KeepAspectRatio) );
					emit recived(&pixmap);
					mutex.unlock();
					break;
				}
			case MOTOR:
				{
					break;
				}
			case HOLDER:
				{
					break;
				}
			case ULTRASONIC_L:
				{
					break;
				}
			case ULTRASONIC_M:
				{
					break;
				}
			case ULTRASONIC_R:
				{
					break;
				}
			default:
				{

				}
		}
	}
}

