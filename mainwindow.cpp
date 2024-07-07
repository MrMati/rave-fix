#include "mainwindow.h"
#include "customslider.h"
#include "songwidget.h"
#include "songs.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::update_current_time);
    connect(ui->volumeSlider, &CustomSlider::slider_clicked, this, &MainWindow::update_current_volume);

    connect(ui->playButton, &QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &CustomSlider::slider_clicked, this, [this](int value){audioOutput->setVolume(value / 100.0);});

    connect(ui->timeSlider, &CustomSlider::slider_clicked, this, [this](int value){player->setPosition(static_cast<qint64>(value));});
    connect(player, &QMediaPlayer::positionChanged, this, [this](qint64 position) {ui->timeSlider->setValue(static_cast<int>(position));});
    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 duration){ui->timeSlider->setMaximum(static_cast<int>(duration));});

    connect(ui->homeScreen, &QPushButton::clicked, this, &MainWindow::on_home_screen_clicked);
    connect(ui->playerButton, &QPushButton::clicked, this, &MainWindow::on_player_screen_clicked);

    ui->stackedWidget->setCurrentIndex(0);
    qint64 initial_vol = 40;
    ui->volumeSlider->setValue(initial_vol);
    audioOutput->setVolume(initial_vol / 10);
    ui->volume->setText(QString::number(initial_vol));

    songListWidget = new QListWidget(this);
    for(const Song *song : songs.getLibrary()){
        QListWidgetItem *item = new QListWidgetItem(songListWidget);
        SongWidget *songWidget = new SongWidget(QString::fromStdString(song->name),
                                                QString::fromStdString(song->artist.at(0)),
                                                QString::fromStdString(song->genre),
                                                song->file_url);
        connect(songWidget, &SongWidget::playClicked, this, &MainWindow::onPlaySong);
        item->setSizeHint(songWidget->sizeHint());
        songListWidget->setItemWidget(item, songWidget);
    }

    QVBoxLayout* homeLayout = qobject_cast<QVBoxLayout*>(ui->home->layout());
    if(!homeLayout){
        homeLayout = new QVBoxLayout(ui->home);
        ui->home->setLayout(homeLayout);
    }
    int margin = static_cast<int>(ui->home->height() * 0.1);
    homeLayout->setContentsMargins(0, margin, 0, 0);
    homeLayout->addWidget(songListWidget);
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

void MainWindow::onPlaySong(QUrl fileUrl){
    player->setSource(fileUrl);
    player->play();
}
