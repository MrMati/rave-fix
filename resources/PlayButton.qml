import QtQuick 2.15

Rectangle {
    width: 50
    height: 50

    property bool playing: false // To track play/pause state

    Image {
        id: playImage
        source: "qrc:/resources/images/play_black.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            playing = !playing
            if (playing) {
                playClicked()
                playImage.source = "qrc:/resources/images/pause_black.png"
            } else {
                pauseClicked()
                playImage.source = "qrc:/resources/images/play_black.png"
            }
        }
        onPressed: console.log("MouseArea pressed")
    }

    signal playClicked()
    signal pauseClicked()

    function resetPlayButton() {
        playing = false
        playImage.source = "qrc:/resources/images/play_black.png"
    }
}
