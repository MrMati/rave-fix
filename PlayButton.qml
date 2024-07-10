import QtQuick 2.15

Rectangle{
    width: 50
    height: 50

    Image{
        id: playImage
        source: "qrc:/resources/images/play_black.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea{
        anchors.fill: parent
        onClicked: playClicked()
        onPressed: console.log("MouseArea pressed")
    }

    signal playClicked()
}
