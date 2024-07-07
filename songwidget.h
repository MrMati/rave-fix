#ifndef SONGWIDGET_H
#define SONGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QUrl>

class SongWidget: public QWidget{
    Q_OBJECT

    public:
        SongWidget(QString name, QString artist, QString genre, QUrl fileUrl, QWidget *parent = nullptr);

    signals:
        void playClicked(QUrl fileUrl);

    private slots:
        void onPlayButtonClicked();

    private:
        QLabel *nameLabel;
        QLabel *artistLabel;
        QLabel *genreLabel;
        QPushButton *playButton;
        QUrl fileUrl;
};

#endif // SONGWIDGET_H
