#include "SongWidget.h"
#include <QDebug>
#include <QQuickItem>

SongWidget::SongWidget(QString name, QString artist, QString genre, QUrl fileUrl, QWidget *parent)
    : QWidget(parent), fileUrl(fileUrl) {
    nameLabel = new QLabel(name);
    artistLabel = new QLabel(artist);
    genreLabel = new QLabel(genre);

    playButton = new QQuickWidget(this);
    playButton->setSource(QUrl(QStringLiteral("qrc:/resources/PlayButton.qml")));
    playButton->setResizeMode(QQuickWidget::SizeRootObjectToView);

    connect(playButton, &QQuickWidget::statusChanged, this, [this](QQuickWidget::Status status){
        if(status == QQuickWidget::Ready){
            QQuickItem *rootObject = playButton->rootObject();
            connect(rootObject, SIGNAL(playClicked()), this, SLOT(onPlayButtonClicked()));
            connect(rootObject, SIGNAL(pauseClicked()), this, SLOT(onPauseButtonClicked()));
        }
    });

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(nameLabel);
    layout->addWidget(artistLabel);
    layout->addWidget(genreLabel);
    layout->addWidget(playButton);
    setLayout(layout);
}

QQuickWidget* SongWidget::getPlayButton() const{
    return playButton;
}

void SongWidget::onPlayButtonClicked() {
    qDebug() << "Play button clicked for song: " << fileUrl.toString();
    emit playClicked(fileUrl);
}

void SongWidget::onPauseButtonClicked(){
    qDebug() << "Pause button clicked for song: " << fileUrl.toString();
    emit pauseClicked();
}
