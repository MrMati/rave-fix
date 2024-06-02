#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &QSlider::sliderMoved, this, [this](int value) {audioOutput->setVolume(value / 100.0);});
    connect(ui->timeSlider, &QSlider::sliderMoved, this, [this](int value) {player->setPosition(static_cast<qint64>(value));});
    connect(ui->homeScreen, &QPushButton::clicked, this, &MainWindow::on_homeScreen_clicked);
    connect(ui->playerButton, &QPushButton::clicked, this, &MainWindow::on_playerScreen_clicked);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_homeScreen_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_playerScreen_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::set_position(int position){
    player->setPosition(position);
}
