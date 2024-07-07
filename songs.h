#ifndef SONGS_H
#define SONGS_H

#include <vector>
#include <string>
#include <QUrl>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <iostream>

struct FileInfo{
    QString name;
    QString path;
    qint64 size;
};

struct Song{
    std::string name;
    std::vector<std::string> artist;
    std::string genre;
    QUrl file_url;
};

class Songs{
    public:
        Songs();
        std::vector<Song*> getLibrary();

    private:
        std::vector<Song*> library;
        void loadSongsFromDirectory(QString directoryPath);
        void addSong(QString filePath);
};

#endif // SONGS_H
// uploading file directly from app, needed all data to provide, dragging into box
