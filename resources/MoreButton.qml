import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: moreButtonComponent
    width: 45
    height: 45
    property bool open_tab: false


    Image {
        id: more
        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectFit
        source: "qrc:/resources/images/more_dark.png"

        MouseArea {
            id: moreButton
            anchors.fill: parent
            onClicked: {
                open_tab = !open_tab
                if (open_tab) {
                    more.source = "qrc:/resources/images/more_dark2.png"
                    popup.open()
                }
            }
            onPressed: more.opacity = 0.7
            onReleased: more.opacity = 1.0
            onCanceled: more.opacity = 1.0
        }
    }

    Popup {
        id: popup
        width: 190
        height: 190
        closePolicy: Popup.CloseOnPressOutside
        x: more.x + more.width + 5
        y: more.y + more.height + 5

        onClosed: {
            more.source = "qrc:/resources/images/more_dark.png"
            open_tab = false
        }

        background: Rectangle {
            color: "transparent"
        }

        Rectangle {
            width: parent.width
            height: parent.height
            color: "#222222"
            radius: 20
            clip: true

            Rectangle {
                width: parent.width - 5
                height: parent.height - 5
                color: "#555555"
                radius: 20
                anchors.centerIn: parent


                Image{
                    id: playlists
                    width: 45
                    height: 45
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.margins: 10
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/resources/images/list_dark2.png"
                    opacity: playlistsButton.enabled ? 1.0 : 0.5

                    MouseArea{
                        id: playlistsButton
                        anchors.fill: parent
                        enabled: stackView.currentItem.objectName !== "playlistsComponent"
                        onPressed: playlists.opacity = 0.7
                        onReleased: playlists.opacity = 1.0
                        onCanceled: playlists.opacity = 1.0
                        onClicked:{
                            stackView.push(playlistsComponent);
                        }
                    }
                }

                Image{
                    id: playAnother
                    width: 45
                    height: 45
                    anchors.left: playlists.right
                    anchors.top: parent.top
                    anchors.margins: 10
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/resources/images/sound_dark.png"
                    opacity: playAnotherButton.enabled ? 1.0 : 0.5

                    MouseArea{
                        id: playAnotherButton
                        anchors.fill: parent
                        enabled: stackView.currentItem.objectName !== "playerComponent"
                        onPressed: playAnother.opacity = 0.7
                        onReleased: playAnother.opacity = 1.0
                        onCanceled: playAnother.opacity = 1.0
                        onClicked:{
                            stackView.push(playerComponent);
                        }
                    }
                }

                Image{
                    id: homeAnother
                    width: 45
                    height: 45
                    anchors.left: playAnother.right
                    anchors.top: parent.top
                    anchors.margins: 10
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/resources/images/home_dark.png"
                    opacity: homeAnotherButton.enabled ? 1.0 : 0.5

                    MouseArea{
                        id: homeAnotherButton
                        anchors.fill: parent
                        enabled: stackView.currentItem.objectName !== "homeComponent"
                        onPressed: homeAnother.opacity = 0.7
                        onReleased: homeAnother.opacity = 1.0
                        onCanceled: homeAnother.opacity = 1.0
                        onClicked:{
                            stackView.push(homeComponent);
                        }
                    }
                }
            }
        }
    }
}
