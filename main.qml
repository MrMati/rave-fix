import QtQuick 2.15
import QtQuick.Controls 2.15
import "resources"

ApplicationWindow{
    visible: true
    width: 820
    height: 600
    title: qsTr("Rave")

    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: homeComponent
        property var currentComponent: homeComponent


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
