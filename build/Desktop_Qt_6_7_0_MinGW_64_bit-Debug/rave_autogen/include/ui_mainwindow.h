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
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSlider *volumeSlider;
    QPushButton *otherScreen;
    QStackedWidget *stackedWidget;
    QWidget *welcome;
    QPushButton *homeScreen;
    QWidget *home;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(300, 220, 93, 29));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(290, 280, 93, 29));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(290, 340, 93, 29));
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(300, 410, 160, 22));
        volumeSlider->setOrientation(Qt::Horizontal);
        otherScreen = new QPushButton(centralwidget);
        otherScreen->setObjectName("otherScreen");
        otherScreen->setGeometry(QRect(60, 80, 93, 29));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(360, 10, 281, 201));
        welcome = new QWidget();
        welcome->setObjectName("welcome");
        homeScreen = new QPushButton(welcome);
        homeScreen->setObjectName("homeScreen");
        homeScreen->setGeometry(QRect(30, 90, 93, 29));
        stackedWidget->addWidget(welcome);
        home = new QWidget();
        home->setObjectName("home");
        pushButton = new QPushButton(home);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 110, 93, 29));
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        otherScreen->setText(QCoreApplication::translate("MainWindow", "other", nullptr));
        homeScreen->setText(QCoreApplication::translate("MainWindow", "home", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "gobacktohome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
