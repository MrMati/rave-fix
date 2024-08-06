import QtQuick 2.15
import QtQuick.Controls 2.15
import "resources"

ApplicationWindow{
    visible: true
    width: 820
    height: 600
    title: qsTr("Rave")
    property alias homeComponent: homeComponent
    property alias playerComponent: playerComponent
    property alias playlistsComponent: playlistsComponent

    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: homeComponent

        Component{
            id: homeComponent
            Home{objectName: "homeComponent"}
        }

        Component{
            id: playerComponent
            Player{objectName: "playerComponent"}
        }

        Component{
            id: playlistsComponent
            Playlists{objectName: "playlistsComponent"}
        }
    }
}
