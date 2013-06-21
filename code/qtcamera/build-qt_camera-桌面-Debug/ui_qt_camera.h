/********************************************************************************
** Form generated from reading UI file 'qt_camera.ui'
**
** Created: Fri Jun 21 23:38:40 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_CAMERA_H
#define UI_QT_CAMERA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_cameraClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_3;
    QSpinBox *spinBox;
    QLabel *label_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_10;
    QLabel *screan;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *camera;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_cameraClass)
    {
        if (qt_cameraClass->objectName().isEmpty())
            qt_cameraClass->setObjectName(QString::fromUtf8("qt_cameraClass"));
        qt_cameraClass->resize(770, 515);
        centralWidget = new QWidget(qt_cameraClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 130, 80, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(580, 200, 81, 31));
        spinBox->setMaximum(3);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(580, 180, 80, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 190, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(670, 190, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 240, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(580, 360, 91, 16));
        label_9->setFont(font);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(670, 370, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(580, 420, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(490, 370, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(580, 380, 81, 31));
        spinBox_2->setMaximum(2);
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(580, 310, 80, 40));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);
        screan = new QLabel(centralWidget);
        screan->setObjectName(QString::fromUtf8("screan"));
        screan->setGeometry(QRect(20, 0, 431, 321));
        screan->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(460, 0, 21, 481));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 350, 471, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(470, 110, 301, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(470, 280, 301, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 380, 421, 91));
        layoutWidget->setAutoFillBackground(false);
        layoutWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAutoFillBackground(false);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);


        verticalLayout->addLayout(horizontalLayout);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(80, 330, 271, 20));
        label_11->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(492, 22, 270, 64));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_4->addWidget(label_7);

        camera = new QLabel(layoutWidget1);
        camera->setObjectName(QString::fromUtf8("camera"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(32);
        sizePolicy1.setVerticalStretch(150);
        sizePolicy1.setHeightForWidth(camera->sizePolicy().hasHeightForWidth());
        camera->setSizePolicy(sizePolicy1);
        camera->setBaseSize(QSize(320, 240));
        camera->setAutoFillBackground(true);
        camera->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(camera);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_6 = new QLineEdit(layoutWidget1);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_3->addWidget(lineEdit_6);

        lineEdit_7 = new QLineEdit(layoutWidget1);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_3->addWidget(lineEdit_7);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(180, 360, 121, 17));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_12->setFont(font2);
        qt_cameraClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        spinBox->raise();
        label_8->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        label_9->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        spinBox_2->raise();
        pushButton_10->raise();
        screan->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        line_4->raise();
        label_11->raise();
        label_12->raise();
        menuBar = new QMenuBar(qt_cameraClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 26));
        qt_cameraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_cameraClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qt_cameraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_cameraClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qt_cameraClass->setStatusBar(statusBar);

        retranslateUi(qt_cameraClass);

        QMetaObject::connectSlotsByName(qt_cameraClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_cameraClass)
    {
        qt_cameraClass->setWindowTitle(QApplication::translate("qt_cameraClass", "qt_camera", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("qt_cameraClass", "Front", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("qt_cameraClass", "SPEED LEVEL", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("qt_cameraClass", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("qt_cameraClass", "Right", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("qt_cameraClass", "Back", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("qt_cameraClass", "HOLDER LEVEL", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("qt_cameraClass", "Right", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("qt_cameraClass", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("qt_cameraClass", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("qt_cameraClass", "Front", 0, QApplication::UnicodeUTF8));
        screan->setText(QString());
        label_3->setText(QApplication::translate("qt_cameraClass", "left", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("qt_cameraClass", "middle", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("qt_cameraClass", "right", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_6->setText(QApplication::translate("qt_cameraClass", "IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("qt_cameraClass", "Port\357\274\232", 0, QApplication::UnicodeUTF8));
        camera->setText(QString());
        pushButton->setText(QApplication::translate("qt_cameraClass", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("qt_cameraClass", "Cancel", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("qt_cameraClass", "Ultrasonic Wave", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qt_cameraClass: public Ui_qt_cameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_CAMERA_H
