#include "SongWidget.h"

SongWidget::SongWidget(QString name, QString artist, QString genre, QUrl fileUrl, QWidget *parent): QWidget(parent), fileUrl(fileUrl){
    nameLabel = new QLabel(name);
    artistLabel = new QLabel(artist);
    genreLabel = new QLabel(genre);
    playButton = new QPushButton("Play");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(nameLabel);
    layout->addWidget(artistLabel);
    layout->addWidget(genreLabel);
    layout->addWidget(playButton);
    setLayout(layout);

    connect(playButton, &QPushButton::clicked, this, &SongWidget::onPlayButtonClicked);
}

void SongWidget::onPlayButtonClicked(){
    qDebug() << "Play button clicked for song: " << fileUrl.toString();
    emit playClicked(fileUrl);
}
