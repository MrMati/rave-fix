#include "player.h"

Player::Player(QObject *parent): QObject(parent){
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music/Blessed & Possessed.mp3"));
    connect(player, &QMediaPlayer::durationChanged, this, &Player::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &Player::updatePosition);
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
    audioOutput->setVolume(linearVolume);
    emit volumeChanged(volume);
}
