import QtQuick 2.15

Rectangle {
    id: songP
    height: 40
    width: parent.width * 0.95
    anchors.horizontalCenter: parent.horizontalCenter
    property bool liked: false
    property bool played: false

    Text {
        id: titleText
        font.pixelSize: 15
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            margins: 10
        }
        height: parent.height
        width: 300
        text: player.title
    }

    Text {
        id: authorText
        font.pixelSize: 15
        anchors {
            left: titleText.right
            leftMargin: 10
        }
        height: parent.height
        width: 300
        text: player.author
    }

    Image {
        id: heartImg
        height: parent.height
        width: parent.height
        anchors {
            bottom: parent.bottom
            right: playPauseImg.left
            rightMargin: 15
        }
        fillMode: Image.PreserveAspectFit
        source: "qrc:/resources/images/heart_black_empty.png"

        MouseArea{
            id: heartButton
            anchors.fill: parent
            onClicked:{
                liked = !liked
                if(liked){
                    heartImg.source = "qrc:/resources/images/heart_pink_fill.png"
                }else{
                    heartImg.source = "qrc:/resources/images/heart_black_empty.png"
                }
            }
            onPressed: heartImg.opacity = 0.7
            onReleased: heartImg.opacity = 1.0
            onCanceled: heartImg.opacity = 1.0
        }
    }

    Image {
        id: playPauseImg
        height: parent.height
        width: parent.height
        anchors {
            bottom: parent.bottom
            right: moreImg.left
        }
        fillMode: Image.PreserveAspectFit
        source: "qrc:/resources/images/play_dark2.png"

        MouseArea {
            id: playButton
            anchors.fill: parent
            onClicked: {
                played = !played
                if (played) {
                    playPauseImg.source = "qrc:/resources/images/pause_dark.png"
                } else {
                    playPauseImg.source = "qrc:/resources/images/play_dark2.png"
                }
            }
            onPressed: playPauseImg.opacity = 0.7
            onReleased: playPauseImg.opacity = 1.0
            onCanceled: playPauseImg.opacity = 1.0
        }
    }

    Image {
        id: moreImg
        height: parent.height
        width: parent.height
        anchors {
            bottom: parent.bottom
            right: parent.right
        }
        fillMode: Image.PreserveAspectFit
        source: "qrc:/resources/images/more_settings_dark.png"
        transform: Rotation {
            origin.x: moreImg.width / 2
            origin.y: moreImg.height / 2
            angle: 90
        }

        MouseArea {
            id: moreImgButton
            anchors.fill: parent
            onPressed: moreImg.opacity = 0.7
            onReleased: moreImg.opacity = 1.0
            onCanceled: moreImg.opacity = 1.0
        }
    }
}
