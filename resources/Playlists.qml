import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: playlists_s
    width: parent.width
    height: parent.height
    property bool isRemoving: false
    property string selectedPlaylist: ""

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
                    playlists_s.isRemoving = !playlists_s.isRemoving
                    playlistGridView.model = playlistsModel.getPlaylists()
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
                    color: playlists_s.isRemoving ? "#666666" : "#555555"
                    radius: 10
                    property int playlistSizeN: playlistsModel.getPlaylistSize(modelData)

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

                    // Item {
                    //     id: playlistName
                    //     property string text: modelData
                    //     property string spacing: "      "
                    //     property string combined: text + spacing
                    //     property string display: combined.substring(step) + combined.substring(0, step)
                    //     property int step: 0
                    //     anchors.top: parent.top
                    //     anchors.margins: 5

                    //     Timer {
                    //       interval: 200
                    //       running: true
                    //       repeat: true
                    //       onTriggered: parent.step = (parent.step + 1) % parent.combined.length
                    //     }

                    //     Text {
                    //       text: parent.display
                    //       font.pixelSize: 16
                    //       color: "#F0F0F0"
                    //     }
                    // }

                    Text{
                        id: playlistSize
                        text: "Size: " + playlistSizeN
                        font.pixelSize: 16
                        color: "#F0F0F0"
                        anchors.centerIn: parent
                        anchors.margins: 5
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (playlists_s.isRemoving) {
                                playlists_s.selectedPlaylist = modelData;
                                confirmDeletePopup.open();
                            } else {
                                playlistContentsView.model = playlistsModel.getPlaylistContents(modelData);
                            }
                        }
                    }
                }
                width: parent.width
                height: Math.ceil(model.count / 6) * cellHeight
            }
        }

        Popup {
            id: confirmDeletePopup
            width: 300
            height: 100
            modal: true
            focus: true
            closePolicy: Popup.CloseOnPressOutside
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            background: Rectangle{
                color: "#555555"
                radius: 10
                border.color: "#222222"
                border.width: 2
            }

            Text{
                text: "Are you sure you want to delete playlist\n" + selectedPlaylist
                font.pixelSize: 16
                color: "#F0F0F0"
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                width: parent.width - 20
            }

            Button {
                id: confirmDeleteButton
                text: "Delete"
                anchors.top: parent.bottom
                anchors.left: parent.left
                anchors.leftMargin: 80
                anchors.topMargin: 10
                background: Rectangle {
                    color: "#FF5555"
                    radius: 10
                }
                onClicked: {
                    playlistsModel.removePlaylist(playlists_s.selectedPlaylist);
                    playlistGridView.model = playlistsModel.getPlaylists();
                    confirmDeletePopup.close();
                    playlists_s.isRemoving = false;
                }
            }

            Button {
                id: cancelDeleteButton
                text: "Cancel"
                anchors.top: parent.bottom
                anchors.left: confirmDeleteButton.right
                anchors.leftMargin: 50
                anchors.topMargin: 10
                background: Rectangle {
                    color: "#777777"
                    radius: 10
                }
                onClicked: {
                    confirmDeletePopup.close();
                }
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
