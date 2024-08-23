#include "playlists.h"
#include <QDebug>

Playlists::Playlists(QObject *parent): QObject(parent), settings("AL", "Rave"){}

QStringList Playlists::getPlaylists() const{
    return settings.childGroups();
}

QStringList Playlists::getPlaylistContents(const QString &playlistName){
    settings.beginGroup(playlistName);
    QStringList contents = settings.value("songs").toStringList();
    settings.endGroup();
    return contents;
}

void Playlists::addPlaylist(const QString &playlistName){
    if(!settings.childGroups().contains(playlistName)){
        settings.beginGroup(playlistName);
        settings.setValue("songs", QStringList());
        settings.endGroup();
    }
}

void Playlists::addSongToPlaylist(const QString &playlistName, const QString &songUrl){
    settings.beginGroup(playlistName);
    QStringList songs = settings.value("songs").toStringList();
    if(!songs.contains(songUrl)){
        songs.append(songUrl);
        settings.setValue("songs", songs);
    }
    settings.endGroup();
}

void Playlists::removePlaylist(const QString &playlistName){
    settings.remove(playlistName);
}

int Playlists::getPlaylistSize(const QString &playlistName){
    return getPlaylistContents(playlistName).size();
}

void Playlists::removeSongFromPlaylist(const QString &playlistName, const QString &songUrl){
    settings.beginGroup(playlistName);
    QStringList songs = settings.value("songs").toStringList();
    if(songs.contains(songUrl)){
        songs.removeAll(songUrl);
        settings.setValue("songs", songs);
    }
    settings.endGroup();
}
