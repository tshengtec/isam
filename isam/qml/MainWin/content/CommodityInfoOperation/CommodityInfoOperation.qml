import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: rootRectId
    width: parent.width; height: parent.height
    color: "#00000000"

    Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width/10; height: parent.height
        color: "#00000000"
        Text {
            anchors.centerIn: parent
            text: "数量(件):"
            font.pixelSize: parent.height/2.5
        }
    }

    Row {
        anchors.right: parent.right
        anchors.rightMargin: 20
        height: rootRectId.height
        spacing: 10

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/10; height: rootRectId.height/1.2
            btnText: "打印上一单"
        }
        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/10; height: rootRectId.height/1.2
            btnText: "移除商品"
        }
    }
}
