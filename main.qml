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

        Component{
            id: homeComponent
            Home{}
        }

        Component{
            id: playerComponent
            Player{}
        }
    }
}
