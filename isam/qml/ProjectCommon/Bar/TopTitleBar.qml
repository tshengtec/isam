import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    signal backed()
    property alias title: textId.text
    width: parent.width; height: parent.height
    color: "#38394e"

    ImageButton {
        y: -(1.5*parent.height - parent.height)/2
        width: parent.height; height: parent.height
        source: "qrc:/image/commodityQuery/back.png"
        scaleWidth: 0.6
        onClicked: backed()
    }

    Item {
        y: -(1.5*parent.height - parent.height)/2
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200; height: parent.height

        Text {
            id: textId
            anchors.centerIn: parent
            text: "销售查询"
            font.pixelSize: parent.height/2.5
            color: "white"
        }
    }
}
