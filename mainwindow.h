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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_home_screen_clicked();
    void on_player_screen_clicked();
    void slider_clicked(int value);

    void on_time_slider_slider_pressed();

    void update_current_time(qint64 position);
    void update_current_volume(qint64 position);

private:
    Ui::MainWindow* ui;
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
    QStackedWidget* stackedWidget;


};
#endif

// in home user can chose the song, then it opens player with this music
