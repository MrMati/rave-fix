/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *player;
    QPushButton *homeScreen;
    QSlider *timeSlider;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    QPushButton *playButton;
    QSlider *volumeSlider;
    QLabel *timer;
    QLabel *volume;
    QWidget *home;
    QPushButton *playerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 571));
        player = new QWidget();
        player->setObjectName("player");
        homeScreen = new QPushButton(player);
        homeScreen->setObjectName("homeScreen");
        homeScreen->setGeometry(QRect(10, 10, 93, 29));
        timeSlider = new QSlider(player);
        timeSlider->setObjectName("timeSlider");
        timeSlider->setGeometry(QRect(20, 500, 631, 22));
        timeSlider->setOrientation(Qt::Horizontal);
        stopButton = new QPushButton(player);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(560, 430, 93, 29));
        pauseButton = new QPushButton(player);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(460, 430, 93, 29));
        playButton = new QPushButton(player);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(360, 430, 93, 29));
        volumeSlider = new QSlider(player);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(40, 260, 22, 160));
        volumeSlider->setOrientation(Qt::Vertical);
        timer = new QLabel(player);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(700, 500, 63, 20));
        volume = new QLabel(player);
        volume->setObjectName("volume");
        volume->setGeometry(QRect(40, 430, 63, 20));
        stackedWidget->addWidget(player);
        home = new QWidget();
        home->setObjectName("home");
        playerButton = new QPushButton(home);
        playerButton->setObjectName("playerButton");
        playerButton->setGeometry(QRect(10, 10, 93, 29));
        stackedWidget->addWidget(home);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        homeScreen->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        timer->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        volume->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        playerButton->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
