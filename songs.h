#ifndef SONGS_H
#define SONGS_H

#include <QObject>
#include <QMediaPlayer>
#include <QDir>
#include <QFileInfoList>
#include <QAbstractListModel>
#include <vector>

class Song : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QStringList artist READ getArtist NOTIFY artistChanged)
    Q_PROPERTY(QUrl fileUrl READ getFileUrl NOTIFY fileUrlChanged)

public:
    explicit Song(QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString &name);

    QStringList getArtist() const;
    void setArtist(const QStringList &artist);

    QUrl getFileUrl() const;
    void setFileUrl(const QUrl &fileUrl);

    friend class Songs;

signals:
    void nameChanged();
    void artistChanged();
    void fileUrlChanged();

private:
    QString m_name;
    QStringList m_artist;
    QUrl m_fileUrl;
};

class Songs : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> songList READ getSongList NOTIFY songListChanged)

public:
    Songs();
    std::vector<Song*> getLibrary();
    Q_INVOKABLE QList<QObject*> getSongList() const;
    Q_INVOKABLE void loadSongsFromDirectory(QString directoryPath);

signals:
    void songListChanged();

private slots:
    void onMediaLoaded(QMediaPlayer::MediaStatus status);

private:
    void addSong(QString filePath);
    std::vector<Song*> library;
    QList<QObject*> songList;
    QMediaPlayer player_temp;
    std::vector<QUrl> pendingUrls;
};

#endif // SONGS_H
