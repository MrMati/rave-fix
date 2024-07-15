#include "player.h"

Player::Player(QObject *parent): QObject(parent), previousVolume(30){
    QSettings settings("AL", "Rave");
    int last_vol = settings.value("last_vol", 30).toInt();

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));
    if(last_vol == 0){
        setVolume(0);
        previousVolume = 30;
    }else{
        setVolume(last_vol);
    }
    connect(player, &QMediaPlayer::durationChanged, this, &Player::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &Player::updatePosition);
    connect(player, &QMediaPlayer::metaDataChanged, this, &Player::updateMetaData);
}

void Player::playPause(){
    if(player->playbackState() == QMediaPlayer::PlayingState){
        player->pause();
    }else{
        player->play();
    }
}

void Player::setSource(const QString &source){
    player->setSource(QUrl::fromLocalFile(source));
}


qint64 Player::position() const{
    return player->position();
}

void Player::setPosition(qint64 position){
    player->setPosition(position);
}

qint64 Player::duration() const{
    return player->duration();
}

void Player::updateDuration(qint64 duration){
    emit durationChanged(duration);
}

void Player::updatePosition(qint64 position){
    emit positionChanged(position);
}

int Player::volume() const{
    return qRound(audioOutput->volume() * 100);
}

void Player::setVolume(int volume) {
    qreal linearVolume = volume / 100.0;
    if (volume == 0) {
        previousVolume = qRound(audioOutput->volume() * 100);
        audioOutput->setVolume(0.0);
    } else {
        audioOutput->setVolume(linearVolume);
    }

    QSettings settings("AL", "Rave");
    settings.setValue("last_vol", volume);

    emit volumeChanged(volume);
}

QString Player::title() const {
    return m_title;
}

QString Player::author() const {
    return m_author;
}

void Player::updateMetaData() {
    m_title = player->metaData().value(QMediaMetaData::Title).toString();
    m_author = player->metaData().value(QMediaMetaData::ContributingArtist).toString();
    emit titleChanged(m_title);
    emit authorChanged(m_author);
}
