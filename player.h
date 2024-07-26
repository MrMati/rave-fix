// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSettings>
#include <QMediaMetaData>

class Player: public QObject{
    Q_OBJECT
    Q_PROPERTY(qint64 position READ position NOTIFY positionChanged)
    Q_PROPERTY(qint64 duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString author READ author NOTIFY authorChanged)
    Q_PROPERTY(QUrl currentSongUrl READ currentSongUrl NOTIFY currentSongUrlChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying NOTIFY playbackStateChanged)

public:
    explicit Player(QObject *parent = nullptr);
    qint64 position() const;
    qint64 duration() const;
    Q_INVOKABLE int volume() const;
    Q_INVOKABLE void setVolume(int volume);
    QString title() const;
    QString author() const;
    Q_INVOKABLE void setSource(const QUrl &source);
    QUrl currentSongUrl() const;

    bool isPlaying() const;
    Q_INVOKABLE void playAndPause();

    void saveLastSong(const QUrl &song);
signals:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void volumeChanged(int volume);
    void titleChanged(const QString &title);
    void authorChanged(const QString &author);
    void playbackStateChanged();
    void currentSongUrlChanged(const QUrl &url);

public slots:
    void playPause();
    void setPosition(qint64 position);


private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    int previousVolume;
    QUrl previousSong;
    QString m_title;
    QString m_author;
    QUrl m_currentSongUrl;

private slots:
    void updateDuration(qint64 duration);
    void updatePosition(qint64 position);
    void updateMetaData();
};

#endif // PLAYER_H
