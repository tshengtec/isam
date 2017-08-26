import QtQuick 2.0
import "./content"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: "#60000000"

    MouseArea { anchors.fill: parent }

    Rectangle {
        id: backGroundId
        anchors.centerIn: parent
        width: parent.width/1.5; height: parent.height/1.6
        color: "#eeeeee"

        Column {
           TitleBar {
               width: backGroundId.width; height: 1.5*rootId.height/20
               onExited: rootId.visible = false
           }
        }
    }
}
