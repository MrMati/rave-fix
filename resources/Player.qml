import QtQuick 2.15
import QtQuick.Controls 2.15

Item{
    id: player_s
    width: parent.width
    height: parent.height
    property bool open_tab: false
    property bool liked: false
    property bool played: false
    property bool sound: true

    Rectangle{
        id: dropAreaContainer
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: "#444444"


        Image{
            id: more1
            width: 45
            height: 45
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/more_dark.png"

            MouseArea{
                id: moreButton1
                anchors.fill: parent
                onClicked: {
                    open_tab = !open_tab
                    if(open_tab){
                        more1.source = "qrc:/resources/images/more_dark2.png"
                    }else{
                        more1.source = "qrc:/resources/images/more_dark.png"
                    }
                }
                onPressed: more1.opacity = 0.7
                onReleased: more1.opacity = 1.0
                onCanceled: more1.opacity = 1.0
            }
        }

        Image{
            id: home
            width: 45
            height: 45
            anchors.verticalCenter: more1.verticalCenter
            anchors.left: more1.right
            anchors.margins: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/home_dark.png"
            MouseArea{
                id: homeButton
                anchors.fill: parent
                onPressed: home.opacity = 0.7
                onReleased: home.opacity = 1.0
                onCanceled: home.opacity = 1.0
            }
        }

        Image{
            id: volume
            width: 45
            height: 45
            anchors.horizontalCenter: more1.horizontalCenter
            anchors.top: more1.bottom
            anchors.margins: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/vol_dark.png"
            MouseArea{
                id: volumeButton
                anchors.fill: parent
                onClicked: {
                    sound = !sound
                    if(sound){
                        volume.source = "qrc:/resources/images/vol_dark.png"
                    }else{
                        volume.source = "qrc:/resources/images/mute_dark.png"
                    }
                }
                onPressed: volume.opacity = 0.7
                onReleased: volume.opacity = 1.0
                onCanceled: volume.opacity = 1.0
            }
        }

        Slider{
            id: sliderVol
            orientation: Qt.Vertical
            anchors.top: volume.bottom
            anchors.horizontalCenter: volume.horizontalCenter
            anchors.margins: 20
            from: 40
            to: 100
            value: 0
            stepSize: 1
            width: 20
            height: parent.height * 0.4
            background: Rectangle{
                width: 5
                height: parent.height
                x: sliderVol.leftPadding + sliderVol.availableWidth / 2 - width / 2
                y: sliderVol.topPadding
                color: "#F0F0F0"
            }

            handle: Rectangle{
                width: 20
                height: 20
                radius: 10
                color: sliderVol.pressed ? "#66BB6A" : "#1DB954"
                border.width: 3
                border.color: "#66BB6A"
                x: sliderVol.leftPadding + sliderVol.availableWidth / 2 - width / 2
                y: sliderVol.topPadding + sliderVol.visualPosition * (sliderVol.availableHeight - height)
                scale: sliderVol.pressed ? 1.2 : 1
            }

            onValueChanged: {
                    console.log(sliderVol.value)
                    if (sliderVol.value == 0) {
                        volume.source = "qrc:/resources/images/mute_dark.png"
                        sound = false
                    } else {
                        volume.source = "qrc:/resources/images/vol_dark.png"
                        sound = true
                    }
                }
        }



        Image{
            id: heart
            width: 45
            height: 45
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/heart_black_empty.png"

            MouseArea{
                id: heartButton
                anchors.fill: parent
                onClicked: {
                    liked = !liked
                    if(liked){
                        heart.source = "qrc:/resources/images/heart_pink_fill.png"
                    }else{
                        heart.source = "qrc:/resources/images/heart_black_empty.png"
                    }
                }
                onPressed: heart.opacity = 0.7
                onReleased: heart.opacity = 1.0
                onCanceled: heart.opacity = 1.0
            }
        }

        Image{
            id: play
            width: 35
            height: 35
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 30
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/play_dark.png"

            MouseArea{
                id: playButton
                anchors.fill: parent
                onClicked: {
                    played = !played
                    if(played){
                        play.source = "qrc:/resources/images/pause_dark.png"
                    }else{
                        play.source = "qrc:/resources/images/play_dark.png"
                    }
                }
                onPressed: play.opacity = 0.7
                onReleased: play.opacity = 1.0
                onCanceled: play.opacity = 1.0
            }
        }

        Image{
            id: prev
            width: 35
            height: 35
            anchors.right: play.left
            anchors.bottom: parent.bottom
            anchors.margins: 30
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/next_prev_dark.png"
            transform: Rotation{
                origin.x: prev.width / 2
                origin.y: prev.height / 2
                angle: 180
            }
            MouseArea{
                id: prevButton
                anchors.fill: parent
                onPressed: prev.opacity = 0.7
                onReleased: prev.opacity = 1.0
                onCanceled: prev.opacity = 1.0
            }
        }

        Image{
            id: next
            width: 35
            height: 35
            anchors.left: play.right
            anchors.bottom: parent.bottom
            anchors.margins: 30
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/next_prev_dark.png"

            MouseArea{
                id: nextButton
                anchors.fill: parent
                onPressed: next.opacity = 0.7
                onReleased: next.opacity = 1.0
                onCanceled: next.opacity = 1.0
            }
        }

        Slider{
            id: slider
            anchors.bottom: play.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 20
            from: 0
            to: 100
            value: 0
            stepSize: 1
            width: parent.width * 0.8
            height: 20
            background: Rectangle{
                height: 5
                width: parent.width
                x: slider.leftPadding
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                color: "#F0F0F0"
            }

            handle: Rectangle{
                width: 20
                height: 20
                radius: 10
                color: slider.pressed ? "#66BB6A" : "#1DB954"
                border.width: 3
                border.color: "#66BB6A"
                x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                scale: slider.pressed ? 1.2 : 1
            }

            onValueChanged:{
                console.log(slider.value)
            }
        }

        Text{
            id: currTime
            width: contentWidth
            height: contentHeight
            color: "#F0F0F0"
            font.pixelSize: 15
            anchors.right: slider.left
            anchors.verticalCenter: slider.verticalCenter
            anchors.rightMargin: 20
            text: "00:00"
        }

        Text{
            id: totalTime
            width: contentWidth
            height: contentHeight
            color: "#F0F0F0"
            font.pixelSize: 15
            anchors.left: slider.right
            anchors.verticalCenter: slider.verticalCenter
            anchors.leftMargin: 20
            text: "03:00"
        }

        Text{// when longer than limit then it slides autmoatically back and forth
            id: songName
            width: 100
            height: 20
            color: "#F0F0F0"
            font.pixelSize: 12
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 20
            text: "Music Name"
        }

        Text{
            id: songAuthors
            width: 100
            height: 20
            color: "#F0F0F0"
            font.pixelSize: 12
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 20
            text: "Music Authors"
        }
    }
}
