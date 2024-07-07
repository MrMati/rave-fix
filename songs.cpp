#include "songs.h"

using namespace std;

Songs::Songs(){
    QUrl path = QUrl::fromLocalFile("C:/Users/adria/Desktop/Adrian/music");
    loadSongsFromDirectory(path.toLocalFile());
}

std::vector<Song*> Songs::getLibrary(){
    return library;
}

void Songs::loadSongsFromDirectory(QString directoryPath){
    QDir dir(directoryPath);
    if(!dir.exists()){
        qDebug() << "Directory does not exist: " << directoryPath.toStdString();
        return;
    }
    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    for(const QFileInfo& fileInfo: fileList){
        addSong(fileInfo.absoluteFilePath());
    }
}

void Songs::addSong(QString filePath){
    QFileInfo fileInfo(filePath);

    Song* song = new Song;
    song->name = fileInfo.fileName().toStdString();
    song->file_url = QUrl::fromLocalFile(filePath);
    song->artist.push_back("Unknown Artist");
    song->genre = "Unknown Genre";

    library.push_back(song);
}
