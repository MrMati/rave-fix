#include "songs.h"
#include <QDebug>
#include <QMediaMetaData>

Song::Song(QObject *parent) : QObject(parent) {}

QString Song::getName() const {
    return m_name;
}

void Song::setName(const QString &name) {
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

QStringList Song::getArtist() const {
    return m_artist;
}

void Song::setArtist(const QStringList &artist) {
    if (artist != m_artist) {
        m_artist = artist;
        emit artistChanged();
    }
}

QUrl Song::getFileUrl() const {
    return m_fileUrl;
}

void Song::setFileUrl(const QUrl &fileUrl) {
    if (fileUrl != m_fileUrl) {
        m_fileUrl = fileUrl;
        emit fileUrlChanged();
    }
}

Songs::Songs() {
    connect(&player_temp, &QMediaPlayer::mediaStatusChanged, this, &Songs::onMediaLoaded);
    QUrl path = QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music");
    loadSongsFromDirectory(path.toLocalFile());
}

std::vector<Song*> Songs::getLibrary() {
    return library;
}

QList<QObject*> Songs::getSongList() const {
    QList<QObject*> list;
    for (const auto& song : library) {
        list.append(song);
    }
    return list;
}

void Songs::loadSongsFromDirectory(QString directoryPath) {
    QDir dir(directoryPath);
    if (!dir.exists()) {
        qDebug() << "Directory does not exist: " << directoryPath;
        return;
    }
    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    for (const QFileInfo& fileInfo : fileList) {
        addSong(fileInfo.absoluteFilePath());
    }
}

void Songs::addSong(QString filePath) {
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    pendingUrls.push_back(fileUrl);

    if (pendingUrls.size() == 1) {
        player_temp.setSource(fileUrl);
    }
}

void Songs::onMediaLoaded(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::LoadedMedia) {
        Song *song = new Song(this);
        song->m_fileUrl = player_temp.source();
        song->setName(player_temp.metaData().value(QMediaMetaData::Title).toString());

        QVariant artistData = player_temp.metaData().value(QMediaMetaData::ContributingArtist);
        if (artistData.isValid()) {
            song->setArtist(artistData.toString().split(";")); // Assuming artists are separated by semicolons
        }

        library.push_back(song);
        songList.append(song);

        emit songListChanged();

        pendingUrls.erase(pendingUrls.begin());
        if (!pendingUrls.empty()) {
            player_temp.setSource(pendingUrls.front());
        }
    }
}
