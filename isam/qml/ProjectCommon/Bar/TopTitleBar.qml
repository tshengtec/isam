import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    signal backed()
    width: parent.width; height: parent.height
    color: "#337cc9"

    MenuButton {
        width: height; height: parent.height
        btnText: "返回"
        radius: 0
        onIsClicked: backed()
    }

    Text {
        anchors.centerIn: parent
        text: "销售查询"
        font.pixelSize: parent.height/2.5
        color: "white"
    }
}
