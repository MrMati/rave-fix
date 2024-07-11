import QtQuick 2.15
import QtQuick.Controls 2.15
import "resources"

ApplicationWindow{
    visible: true
    width: 820
    height: 600
    title: qsTr("Rave")

    // Home{
    //     id: home_screen
    // }

    Player{
        id: player_screen
    }
}
