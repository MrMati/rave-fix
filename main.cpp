#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QQmlApplicationEngine engine;
    MainWindow w;
    // engine.rootContext()->setContextProperty("mainWindow", &w);
    // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    w.show();
    return a.exec();
}

/* to add:
    - better listing - using qml not qwidget, also under the qwidgets there should be qml with colour
    - music queue
    - shuffling music
    - saving last vol and track - some issues withh vol
    - add authors, music genres and others using mp3tag, then create playlists and make it possible for the user to make their own
    - once pressed play button, then it turns into a stop button
    - too long text should be automatically scrollable when hovered above it
*/
