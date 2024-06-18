#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customslider.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));


    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::update_current_time);
    connect(ui->volumeSlider, &QSlider::sliderMoved, this, &MainWindow::update_current_volume);


    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &QSlider::sliderMoved, this, [this](int value){audioOutput->setVolume(value / 100.0);});

    connect(ui->timeSlider, &QSlider::sliderMoved, this, [this](int value){player->setPosition(static_cast<qint64>(value));});
    connect(player, &QMediaPlayer::positionChanged, this, [this](qint64 position) {ui->timeSlider->setValue(static_cast<int>(position));});
    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 duration){ui->timeSlider->setMaximum(static_cast<int>(duration));});

    qDebug() << "before custom slider object" << (ui->timeSlider == nullptr);
    CustomSlider *customSlider = static_cast<CustomSlider*>(ui->timeSlider);
    qDebug () << (customSlider == nullptr);
    connect(customSlider, &CustomSlider::slider_clicked, this, &MainWindow::slider_clicked);
    qDebug() << "after custom sider object" ;

    connect(ui->homeScreen, &QPushButton::clicked, this, &MainWindow::on_home_screen_clicked);
    connect(ui->playerButton, &QPushButton::clicked, this, &MainWindow::on_player_screen_clicked);


    ui->stackedWidget->setCurrentIndex(0);
    qint64 initial_vol = 40;
    ui->volumeSlider->setValue(initial_vol);
    audioOutput->setVolume(initial_vol / 10);
    ui->volume->setText(QString::number(initial_vol));

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_home_screen_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_player_screen_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::slider_clicked(int value)
{
    qDebug() << "lamda value: " << value;
    player->setPosition(static_cast<qint64>(value));
}

void MainWindow::on_time_slider_slider_pressed()
{
    slider_clicked(50);
}

void MainWindow::update_current_time(qint64 position){
    qint64 minutes = position / 60000;
    qint64 seconds = (position / 1000) % 60;

    QString timeString = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));

    ui->timer->setText(timeString);
}

void MainWindow::update_current_volume(qint64 position){
    qint64 vol = position;

    QString timeString = QString("%1").arg(vol);

    ui->volume->setText(timeString);
}
