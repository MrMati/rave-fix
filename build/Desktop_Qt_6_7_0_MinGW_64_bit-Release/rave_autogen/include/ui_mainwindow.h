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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class CustomSlider;

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *player;
    QVBoxLayout *verticalLayout_2;
    QPushButton *homeScreen;
    QSlider *volumeSlider;
    QLabel *volume;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QLabel *timer;
    CustomSlider *timeSlider;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        player = new QWidget();
        player->setObjectName("player");
        verticalLayout_2 = new QVBoxLayout(player);
        verticalLayout_2->setObjectName("verticalLayout_2");
        homeScreen = new QPushButton(player);
        homeScreen->setObjectName("homeScreen");

        verticalLayout_2->addWidget(homeScreen);

        volumeSlider = new QSlider(player);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(volumeSlider);

        volume = new QLabel(player);
        volume->setObjectName("volume");

        verticalLayout_2->addWidget(volume);

        playButton = new QPushButton(player);
        playButton->setObjectName("playButton");

        verticalLayout_2->addWidget(playButton);

        pauseButton = new QPushButton(player);
        pauseButton->setObjectName("pauseButton");

        verticalLayout_2->addWidget(pauseButton);

        stopButton = new QPushButton(player);
        stopButton->setObjectName("stopButton");

        verticalLayout_2->addWidget(stopButton);

        timer = new QLabel(player);
        timer->setObjectName("timer");

        verticalLayout_2->addWidget(timer);

        timeSlider = new CustomSlider(player);
        timeSlider->setObjectName("timeSlider");
        timeSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(timeSlider);

        stackedWidget->addWidget(player);
        home = new QWidget();
        home->setObjectName("home");
        playerButton = new QPushButton(home);
        playerButton->setObjectName("playerButton");
        playerButton->setGeometry(QRect(10, 10, 93, 29));
        stackedWidget->addWidget(home);

        verticalLayout->addWidget(stackedWidget);

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
        volume->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        timer->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        playerButton->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
