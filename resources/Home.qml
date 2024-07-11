import QtQuick 2.15

Item{
    id: home_s
    width: parent.width
    height: parent.height
    property bool open_tab: false

    Rectangle {
        id: container
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
            id: player
            width: 50
            height: 50
            anchors.verticalCenter: more1.verticalCenter
            anchors.left: more1.right
            anchors.margins: 10
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/sound_dark.png"
            MouseArea{
                id: playerButton
                anchors.fill: parent
                onPressed: player.opacity = 0.7
                onReleased: player.opacity = 1.0
                onCanceled: player.opacity = 1.0
            }
        }
    }
}
