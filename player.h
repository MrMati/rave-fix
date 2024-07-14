// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player : public QObject{
    Q_OBJECT
    Q_PROPERTY(qint64 position READ position NOTIFY positionChanged)
    Q_PROPERTY(qint64 duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

    public:
        explicit Player(QObject *parent = nullptr);
        void setSource(const QString &source);
        qint64 position() const;
        qint64 duration() const;
        Q_INVOKABLE int volume() const;
        Q_INVOKABLE void setVolume(int volume);

    signals:
        void positionChanged(qint64 position);
        void durationChanged(qint64 duration);
        void volumeChanged(int volume);

    public slots:
        void playPause();
        void setPosition(qint64 position);

    private:
        QMediaPlayer *player;
        QAudioOutput *audioOutput;

    private slots:
        void updateDuration(qint64 duration);
        void updatePosition(qint64 position);
};

#endif // PLAYER_H
