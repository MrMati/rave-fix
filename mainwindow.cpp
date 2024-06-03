#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customslider.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &QSlider::sliderMoved, this, [this](int value){
        audioOutput->setVolume(value / 100.0);
    });

    connect(ui->timeSlider, &QSlider::sliderMoved, this, [this](int value){
        player->setPosition(static_cast<qint64>(value));
    });
    connect(player, &QMediaPlayer::positionChanged, this, [this](qint64 position) {
        ui->timeSlider->setValue(static_cast<int>(position));
    });
    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 duration){
        ui->timeSlider->setMaximum(static_cast<int>(duration));
    });
    CustomSlider *customSlider = qobject_cast<CustomSlider*>(ui->timeSlider);
    connect(customSlider, &CustomSlider::sliderClicked, this, [this](int value) {
        player->setPosition(static_cast<qint64>(value));
    });
// pointer doesnt jump when i press somewhere on the slider
    connect(ui->homeScreen, &QPushButton::clicked, this, &MainWindow::on_homeScreen_clicked);
    connect(ui->playerButton, &QPushButton::clicked, this, &MainWindow::on_playerScreen_clicked);


    ui->stackedWidget->setCurrentIndex(0);
    ui->volumeSlider->setValue(40);
    audioOutput->setVolume(0.4);

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
