#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWidget>
#include "customslider.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    // MainWindow w;
    qmlRegisterType<CustomSlider>("CustomSlider", 1, 0, "CustomSlider");
    // engine.rootContext()->setContextProperty("mainWindow", &w);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    // w.show();
    return a.exec();
}

/* to add:
    - better listing - using qml not qwidget, also under the qwidgets there should be qml with colour
    - music queue
    - shuffling music
    - too long text should be automatically scrollable when hovered above it
*/
