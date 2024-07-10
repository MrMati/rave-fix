import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: parent.width
        height: parent.height
        color: "lightgrey"

        Column {
            anchors.centerIn: parent

            Text {
                id: title
                text: qsTr("Music Player")
                font.pointSize: 24
            }

            Button {
                text: qsTr("Play")
                onClicked: mainWindow.play()
            }

            Button {
                text: qsTr("Pause")
                onClicked: mainWindow.pause()
            }

            Button {
                text: qsTr("Stop")
                onClicked: mainWindow.stop()
            }
        }
    }
}
