import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    signal removeAll()
    id: rootRectId
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        anchors.left: parent.left
        anchors.leftMargin: 10
        height: rootRectId.height
        spacing: 100

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/10; height: parent.height
            color: "#00000000"
            Text {
                anchors.centerIn: parent
                color: "#858585"
                text: "数量(件): 0"
                font.pixelSize: parent.height/2.5
            }
        }

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/10; height: parent.height
            color: "#00000000"
            Text {
                anchors.centerIn: parent
                color: "#858585"
                text: "合计(元): 0"
                font.pixelSize: parent.height/2.5
            }
        }
    }


    Row {
        anchors.right: parent.right
        anchors.rightMargin: 10
        height: rootRectId.height
        spacing: 10

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/15; height: rootRectId.height/1.2
            btnColor: "#5467ef"
            radius: 5
            btnText: "打印上一单"
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootRectId.width/15; height: rootRectId.height/1.2
            btnText: "移除全部商品"
            btnColor: "#b0b0b0"
            radius: 5
            onIsClicked: removeAll()
        }
    }
}
