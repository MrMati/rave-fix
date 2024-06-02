#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStackedWidget>
#include <Qslider>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_homeScreen_clicked();
    void on_playerScreen_clicked();
    void set_position(int position);

private:
    Ui::MainWindow* ui;
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
    QStackedWidget* stackedWidget;

};
#endif

// in home user can chose the song, then it opens player with this music
