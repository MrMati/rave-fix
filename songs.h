#ifndef SONGS_H
#define SONGS_H
#include <vector>
#include <string>
#include <QUrl>

struct Song{
    std::string name;
    std::vector<std::string> artist;
    std::string genre;
    QUrl file_url;
};

class songs{
    public:
        songs();

    private:
        std::vector<Song*> library;

};

#endif // SONGS_H
// uploading file directly from app, needed all data to provide, dragging into box
