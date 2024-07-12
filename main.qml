import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomSlider 1.0
import "resources"

ApplicationWindow{
    visible: true
    width: 820
    height: 600
    title: qsTr("Rave")

    // Home{
    //     id: home_screen
    // }

    Player{
        id: player_screen
    }

    // QQuickWidget {
    //                 id: customSlider1Widget
    //                 width: parent.width * 0.8
    //                 height: 40
    //                 anchors.horizontalCenter: parent.horizontalCenter
    //                 anchors.top: play.bottom
    //                 anchors.topMargin: 20
    //                 source: "qrc:/CustomSliderWidget.qml"
    //             }

    //             QQuickWidget {
    //                 id: customSlider2Widget
    //                 width: parent.width * 0.8
    //                 height: 40
    //                 anchors.horizontalCenter: parent.horizontalCenter
    //                 anchors.top: customSlider1Widget.bottom
    //                 anchors.topMargin: 20
    //                 source: "qrc:/CustomSliderWidget.qml"
    //             }
}
