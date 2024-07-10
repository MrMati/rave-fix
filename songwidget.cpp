#include "SongWidget.h"
#include <QDebug>
#include <QQuickItem>

SongWidget::SongWidget(QString name, QString artist, QString genre, QUrl fileUrl, QWidget *parent)
    : QWidget(parent), fileUrl(fileUrl) {
    nameLabel = new QLabel(name);
    artistLabel = new QLabel(artist);
    genreLabel = new QLabel(genre);

    playButton = new QQuickWidget(this);
    playButton->setSource(QUrl(QStringLiteral("qrc:/PlayButton.qml")));
    playButton->setResizeMode(QQuickWidget::SizeRootObjectToView);

    connect(playButton, &QQuickWidget::statusChanged, this, [this](QQuickWidget::Status status){
        if(status == QQuickWidget::Ready){
            QQuickItem *rootObject = playButton->rootObject();
            connect(rootObject, SIGNAL(playClicked()), this, SLOT(onPlayButtonClicked()));
        }
    });
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(nameLabel);
    layout->addWidget(artistLabel);
    layout->addWidget(genreLabel);
    layout->addWidget(playButton);
    setLayout(layout);
}

void SongWidget::onPlayButtonClicked() {
    qDebug() << "Play button clicked for song: " << fileUrl.toString();
    emit playClicked(fileUrl);
}
