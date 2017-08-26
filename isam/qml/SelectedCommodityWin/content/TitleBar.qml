import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    signal exited()
    width: parent.width; height: parent.height
    color: "#337cc9"

    Text {
        x: 15
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: parent.height/2
        color: "white"
        text: "选择商品"
    }

    MenuButton {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 15
        width: parent.height/1.2; height: width
        btnText: "X"
        onIsClicked: {
            exited();
        }
    }
}
