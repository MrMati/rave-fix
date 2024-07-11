#ifndef SONGWIDGET_H
#define SONGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QUrl>
#include <QQuickWidget>

class SongWidget: public QWidget{
    Q_OBJECT

    public:
        SongWidget(QString name, QString artist, QString genre, QUrl fileUrl, QWidget *parent = nullptr);
        QQuickWidget* getPlayButton() const;

    signals:
        void playClicked(QUrl fileUrl);
        void pauseClicked();

    private slots:
        void onPlayButtonClicked();
        void onPauseButtonClicked();

    private:
        QLabel *nameLabel;
        QLabel *artistLabel;
        QLabel *genreLabel;
        QQuickWidget *playButton;
        QUrl fileUrl;
};

#endif // SONGWIDGET_H
