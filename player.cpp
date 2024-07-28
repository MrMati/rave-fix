#include "player.h"

Player::Player(QObject *parent): QObject(parent), previousVolume(30){
    QSettings settings("AL", "Rave");
    int last_vol = settings.value("last_vol", 30).toInt();
    QUrl last_song = settings.value("last_song").toUrl();
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    setSource(last_song);
    if(last_vol == 0){
        setVolume(0);
        previousVolume = 30;
    }else{
        setVolume(last_vol);
    }
    connect(player, &QMediaPlayer::durationChanged, this, &Player::updateDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &Player::updatePosition);
    connect(player, &QMediaPlayer::metaDataChanged, this, &Player::updateMetaData);

    songs = new Songs();
}

void Player::playPause(){
    if(player->playbackState() == QMediaPlayer::PlayingState){
        player->pause();
    }else{
        player->play();
    }
    saveLastSong(m_currentSongUrl);
}

void Player::setSource(const QUrl &source) {
    if (m_currentSongUrl != source) {
        m_currentSongUrl = source;
        player->setSource(source);
        emit currentSongUrlChanged(m_currentSongUrl);
        bool liked = isCurrentSongLiked();
        emit currentSongLikedChanged(liked);
    }
}

bool Player::isCurrentSongLiked() const {
    // Find the song in the Songs library
    for (Song* song : songs->getLibrary()) {
        if (song->getFileUrl() == m_currentSongUrl) {
            return song->isLiked();
        }
    }
    return false;
}

void Player::setCurrentSongLiked(bool liked) {
    // Find the song in the Songs library and update like status
    for (Song* song : songs->getLibrary()) {
        if (song->getFileUrl() == m_currentSongUrl) {
            song->setLiked(liked);
            break;
        }
    }
}

void Player::saveLastSong(const QUrl &song) {
    QSettings settings("AL", "Rave");
    settings.setValue("last_song", song);
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

bool Player::isPlaying() const {
    return player->playbackState() == QMediaPlayer::PlayingState;
}


void Player::playAndPause()
{
    if(player->playbackState() == QMediaPlayer::PlayingState){
        player->pause();
    }else{
        player->play();
    }
}

QUrl Player::currentSongUrl() const {
    return m_currentSongUrl;
}
