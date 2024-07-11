import QtQuick 2.15
import QtQuick.Controls 2.15

Item{
    id: player_s
    width: parent.width
    height: parent.height
    property bool open_tab: false
    property bool liked: false
    property bool played: false

    Rectangle{
            id: dropAreaContainer
            anchors.fill: parent
            width: parent.width
            height: parent.height
            color: "#444444"


            Image{
                id: more1
                width: 50
                height: 50
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
                width: 50
                height: 50
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
                id: heart
                width: 50
                height: 50
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
                width: 40
                height: 40
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
                width: 40
                height: 40
                anchors.right: play.left
                anchors.bottom: parent.bottom
                anchors.margins: 30
                fillMode: Image.PreserveAspectFit
                source: "qrc:/resources/images/next_prev_dark.png"
                transform: Rotation {
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
                width: 40
                height: 40
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
    }
}
