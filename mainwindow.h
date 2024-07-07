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
#include "songs.h"


QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow: public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

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

// in home user can chose the song, then it opens player with this music
