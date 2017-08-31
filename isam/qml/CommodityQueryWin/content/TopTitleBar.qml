import QtQuick 2.0
import "../../Common/Button"
import "../../Common/Text"

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
        text: "商品查询"
        font.pixelSize: parent.height/2.5
        color: "white"
    }

    ISAMTextInput {
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        width: 3*parent.width/20; height: 5*parent.height/10
        radius: height/2
        defaultText: "  搜索条形码或名称"
    }
}
