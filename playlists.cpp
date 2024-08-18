#include "playlists.h"

Playlists::Playlists(QObject *parent): QObject(parent),settings("AL", "Rave"){}

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

void Playlists::addSongToPlaylist(const QString &playlistName, const QString &song){
    settings.beginGroup(playlistName);
    QStringList songs = settings.value("songs").toStringList();
    songs.append(song);
    settings.setValue("songs", songs);
    settings.endGroup();
}

void Playlists::removePlaylist(const QString &playlistName){
    settings.remove(playlistName);
}
