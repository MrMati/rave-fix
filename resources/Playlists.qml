import QtQuick 2.15

Item {
    id: playlists_s
    width: parent.width
    height: parent.height

    Rectangle{
        id: container
        anchors.fill: parent
        width: parent.width
        height: parent.height
        color: "#444444"

        MoreButton {
            id: more3
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 10
        }

        Image{
            id: goBack
            width: 45
            height: 45
            anchors{
                verticalCenter: more3.verticalCenter
                left: more3.right
                margins: 5
            }
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/back_dark.png"

            MouseArea {
                id: goBackButton
                anchors.fill: parent
                onPressed: goBack.opacity = 0.7
                onReleased: goBack.opacity = 1.0
                onCanceled: goBack.opacity = 1.0
                onClicked:{
                    // stackView.push(playerComponent)
                }
            }
        }
    }
}
