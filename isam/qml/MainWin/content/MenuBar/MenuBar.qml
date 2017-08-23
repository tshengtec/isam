import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: themesModel.backgroundColor

    Row {
        anchors.fill: parent
        spacing: 20

        Item { width: 50; height: 1 }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "退货"
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
}
