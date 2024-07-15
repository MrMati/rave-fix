#include "mainwindow.h"
#include "customslider.h"
#include "songwidget.h"
#include "songs.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // load settings
    QSettings settings("AL", "Rave");
    QString last_played_song = settings.value("last_played_song", "").toString();

    int last_vol = settings.value("last_vol", 40).toInt();
    if(!last_played_song.isEmpty()){
        player->setSource(QUrl::fromUserInput(last_played_song));
    }

    audioOutput->setVolume(last_vol / 100.0);
    ui->volumeSlider->setValue(last_vol);
    ui->volume->setText(QString::number(last_vol));

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

    // songListWidget = new QListWidget(this);
    // for(const Song *song : songs.getLibrary()){
    //     QListWidgetItem *item = new QListWidgetItem(songListWidget);
    //     SongWidget *songWidget = new SongWidget(QString::fromStdString(song->name),
    //                                             QString::fromStdString(song->artist.at(0)),
    //                                             song->file_url);
    //     connect(songWidget, &SongWidget::playClicked, this, &MainWindow::onPlaySong);
    //     connect(songWidget, &SongWidget::pauseClicked, this, &MainWindow::onPauseSong);
    //     item->setSizeHint(songWidget->sizeHint());
    //     songListWidget->setItemWidget(item, songWidget);
    // }

    QVBoxLayout* homeLayout = qobject_cast<QVBoxLayout*>(ui->home->layout());
    if(!homeLayout){
        homeLayout = new QVBoxLayout(ui->home);
        ui->home->setLayout(homeLayout);
    }
    int margin = static_cast<int>(ui->home->height() * 0.1);
    homeLayout->setContentsMargins(0, margin, 0, 0);
    homeLayout->addWidget(songListWidget);

    // QQmlApplicationEngine *engine = new QQmlApplicationEngine(this);
    // engine->rootContext()->setContextProperty("mainWindow", this);
    // engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    QSettings settings("AL", "Rave");
    QUrl current_song = player->source().url();
    int current_volume = static_cast<int>(audioOutput->volume() * 100);

    settings.setValue("last_played_song", current_song.toString());
    settings.setValue("last_vol", current_volume);

    QMainWindow::closeEvent(event);
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

void MainWindow::onPauseSong() {
    player->pause();
}

// void MainWindow::resetPlayButtons() {
//     for (int i = 0; i < songListWidget->count(); ++i) {
//         QListWidgetItem *item = songListWidget->item(i);
//         SongWidget *songWidget = qobject_cast<SongWidget *>(songListWidget->itemWidget(item));
//         if (songWidget) {
//             QObject *rootObject = qobject_cast<QObject *>(songWidget->getPlayButton()->rootObject());
//             if (rootObject) {
//                 QMetaObject::invokeMethod(rootObject, "resetPlayButton", Qt::DirectConnection);
//             }
//         }
//     }
// }
