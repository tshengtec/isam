import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: themesModel.backgroundColor

    Row {
        anchors.fill: parent
        spacing: 20

        Item { width: 30; height: 1 }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "销售"
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "挂单"
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "取单"
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "交班"
        }
    }

    Item {
        anchors.right: parent.right
        width: textId.text.length*height/2.5; height: rootId.height/1.2

        Text {
            id: textId
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: "white"
            text: "xxx公司"
            font.pixelSize: parent.height/2.5
        }
    }
}