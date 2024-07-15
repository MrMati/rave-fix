#ifndef SONGS_H
#define SONGS_H

#include <vector>
#include <string>
#include <QUrl>
#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QObject>
#include <QVariant>

struct FileInfo{
    QString name;
    QString path;
    qint64 size;
};

struct Song{
    std::string name;
    std::vector<std::string> artist;
    QUrl file_url;
};

class Songs: public QObject{
    Q_OBJECT

    public:
        Songs();
        std::vector<Song*> getLibrary();

    private slots:
        void onMediaLoaded(QMediaPlayer::MediaStatus status);

    private:
        std::vector<Song*> library;
        std::vector<QUrl> pendingUrls;
        QMediaPlayer player_temp;
        void loadSongsFromDirectory(QString directoryPath);
        void addSong(QString filePath);
};

#endif // SONGS_H
