import QtQuick 2.15
import QtQuick.Controls 2.15

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
                    stackView.pop()
                }
            }
        }

        Image{
            id: addPlaylist
            width: 45
            height: 45
            anchors {
                right: parent.right
                top: parent.top
                margins: 10
            }
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/add_dark.png"

            MouseArea {
                id: addPlaylistButton
                anchors.fill: parent
                onPressed: addPlaylist.opacity = 0.7
                onReleased: addPlaylist.opacity = 1.0
                onCanceled: addPlaylist.opacity = 1.0
                onClicked: {
                    playlistPopup.open()
                }
            }
        }

        Image{
            id: removePlaylist
            width: 45
            height: 45
            anchors{
                right: addPlaylist.left
                top: parent.top
                margins: 10
            }
            fillMode: Image.PreserveAspectFit
            source: "qrc:/resources/images/remove_dark.png"

            MouseArea {
                id: removePlaylistButton
                anchors.fill: parent
                onPressed: removePlaylist.opacity = 0.7
                onReleased: removePlaylist.opacity = 1.0
                onCanceled: removePlaylist.opacity = 1.0
                onClicked: {
                    // to do
                }
            }
        }

        Popup{
            id: playlistPopup
            width: 200
            height: 85
            closePolicy: Popup.CloseOnPressOutside
            x: addPlaylist.x - width - 10
            y: addPlaylist.y
            modal: true
            focus: true
            background: Rectangle{
                color: "transparent"
            }

            Rectangle{
                width: parent.width
                height: parent.height
                color: "#222222"
                radius: 20
                clip: true
                Keys.onEscapePressed:{
                    playlistPopup.close();
                }

                Rectangle{
                    width: parent.width - 5
                    height: parent.height - 5
                    color: "#555555"
                    radius: 20
                    anchors.centerIn: parent

                    Column{
                        spacing: 10
                        padding: 20
                        anchors.centerIn: parent

                        TextField{
                            id: playlistNameField
                            placeholderText: "Enter playlist name"
                            width: 170
                            anchors.horizontalCenter: parent.horizontalCenter
                            color: "#F0F0F0"
                            background: Rectangle{
                                color: "#777777"
                                radius: 10
                            }
                            padding: 10
                            Keys.onReturnPressed:{
                                addButton.clicked();
                            }
                            Keys.onEscapePressed:{
                                playlistPopup.close();
                            }
                        }

                        Row{
                            spacing: 10
                            anchors.horizontalCenter: parent.horizontalCenter

                            Button{
                                id: addButton
                                text: "Add"
                                focusPolicy: Qt.ClickFocus
                                background: Rectangle{
                                    color: "#777777"
                                    radius: 10
                                }
                                padding: 10
                                onClicked:{
                                    let name = playlistNameField.text;
                                    let playlists = playlistsModel.getPlaylists();
                                    if (name.length > 0 && !playlists.includes(name)){
                                        playlistsModel.addPlaylist(name);
                                        playlistPopup.close();
                                        playlistNameField.text = "";
                                        playlistGridView.model = playlistsModel.getPlaylists();
                                    }
                                }
                            }

                            Button{
                                id: cancelButton
                                text: "Cancel"
                                background: Rectangle{
                                    color: "#777777"
                                    radius: 10
                                }
                                padding: 10
                                onClicked:{
                                    playlistPopup.close();
                                }
                            }
                        }
                    }
                }
            }
        }

        ScrollView {
            id: playlistGridViewScroll
            anchors{
                top: goBack.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                margins: 10
            }

            GridView {
                id: playlistGridView
                anchors.fill: parent
                model: playlistsModel.getPlaylists()
                cellWidth: (parent.width - 20) / 6
                cellHeight: cellWidth
                clip: true

                delegate: Rectangle {
                    id: playlist_p
                    width: playlistGridView.cellWidth - 5
                    height: playlistGridView.cellHeight - 5
                    color: "#555555"
                    radius: 10

                    Text {
                        id: playlistName
                        text: modelData
                        font.pixelSize: 16
                        color: "#F0F0F0"
                        wrapMode: Text.Wrap
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: playlistSize.top
                        anchors.margins: 5

                    }

                    Text{
                        id: playlistSize
                        text: "size: to do"
                        font.pixelSize: 16
                        color: "#F0F0F0"
                        anchors.centerIn: parent
                        anchors.margins: 5
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            playlistContentsView.model = playlistsModel.getPlaylistContents(modelData)
                        }
                    }
                }
                width: parent.width
                height: Math.ceil(model.count / 6) * cellHeight
            }
        }

        ListView{
            id: playlistContentsView
            anchors.top: playlistGridViewScroll.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: 200
            model: []

            delegate: Item{
                width: parent.width
                height: 40

                Text{
                    text: modelData
                    font.pixelSize: 18
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                }
            }
        }
    }
}
