import QtQuick 2.0
import "../../Common/Button"
import "../../Common/Text"

Rectangle {
    signal exited()
    width: parent.width; height: parent.height
    radius: 10
    color: "#ed9b13"

    Rectangle {
        width: parent.width; height: 0.5*parent.height
        color: parent.color
        anchors.bottom: parent.bottom
    }

    MText {
        x: 15
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: parent.height/2.5
        color: "white"
        text: "搜索商品"
    }

    ImageButton {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 15
        width: 0.8*parent.height; height: 0.8*parent.height
        source: "qrc:/image/mainWin/close.png"
        radius: width/2
        onClicked: exited()
    }
}
