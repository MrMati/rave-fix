#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <QObject>
#include <QSettings>
#include <QStringList>
#include <QString>

class Playlists: public QObject{
    Q_OBJECT

    public:
        explicit Playlists(QObject *parent = nullptr);

        Q_INVOKABLE QStringList getPlaylists() const;
        Q_INVOKABLE QStringList getPlaylistContents(const QString &playlistName);
        Q_INVOKABLE void addPlaylist(const QString &playlistName);
        Q_INVOKABLE void addSongToPlaylist(const QString &playlistName, const QString &songUrl);
        Q_INVOKABLE void removePlaylist(const QString &playlistName);
        Q_INVOKABLE int getPlaylistSize(const QString &playlistName);
        Q_INVOKABLE void removeSongFromPlaylist(const QString &playlistName, const QString &songUrl);

    private:
        QSettings settings;
};

#endif // PLAYLISTS_H
