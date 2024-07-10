#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStackedWidget>
#include <Qslider>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <iostream>
#include <QListWidget>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include "songs.h"


QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow: public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        Q_INVOKABLE void play() { player->play(); }
        Q_INVOKABLE void pause() { player->pause(); }
        Q_INVOKABLE void stop() { player->stop(); }

    protected:
        void closeEvent(QCloseEvent *event) override;

    private slots:
        void on_home_screen_clicked();
        void on_player_screen_clicked();

        void update_current_time(qint64 position);
        void update_current_volume(qint64 position);
        void onPlaySong(QUrl fileUrl);


    private:
        Ui::MainWindow* ui;
        QMediaPlayer* player;
        QAudioOutput* audioOutput;
        QStackedWidget* stackedWidget;
        QListWidget *songListWidget;
        Songs songs;

};
#endif
