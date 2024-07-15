#include "songs.h"
#include <QDebug>

Songs::Songs() {
    connect(&player_temp, &QMediaPlayer::mediaStatusChanged, this, &Songs::onMediaLoaded);
    QUrl path = QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music");
    loadSongsFromDirectory(path.toLocalFile());
}

std::vector<Song*> Songs::getLibrary() {
    return library;
}

void Songs::loadSongsFromDirectory(QString directoryPath) {
    QDir dir(directoryPath);
    if (!dir.exists()) {
        qDebug() << "Directory does not exist: " << directoryPath.toStdString();
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

        Song* song = new Song;
        song->file_url = player_temp.source();
        song->name = player_temp.metaData().value(QMediaMetaData::Title).toString().toStdString();

        QVariant artistData = player_temp.metaData().value(QMediaMetaData::Author);
        if (artistData.isValid()) {
            song->artist.push_back(artistData.toString().toStdString());
        }
        library.push_back(song);

        pendingUrls.erase(pendingUrls.begin());
        if (!pendingUrls.empty()) {
            player_temp.setSource(pendingUrls.front());
        }
    }
}
