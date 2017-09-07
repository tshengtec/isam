import QtQuick 2.0
import "../../Common/Button"

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

    Text {
        x: 15
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: parent.height/2
        color: "white"
        text: "选择商品"
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

//    MenuButton {
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.right: parent.right
//        anchors.rightMargin: 15
//        width: parent.height/1.2; height: width
//        btnText: "X"
//        onIsClicked: {
//            exited();
//        }
//    }
}
