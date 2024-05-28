#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Set media to play
    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));

    // Connect UI elements to media player and audio output slots
    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &QSlider::valueChanged, this, [this](int value) {
        audioOutput->setVolume(value / 100.0);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
