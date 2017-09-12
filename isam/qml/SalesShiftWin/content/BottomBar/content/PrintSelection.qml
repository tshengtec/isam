import QtQuick 2.0
import "../../../../Common/Text"

Rectangle {
    id: printSelection
    property bool select: false

    signal printSelected(bool status)

    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        anchors.fill: parent
        spacing: 5

        Image {
            width: height; height: 0.6*parent.height
            anchors.verticalCenter: parent.verticalCenter
            source: printSelection.select ?
                        "qrc:/image/settleMentWin/selected.png" : "qrc:/image/settleMentWin/select.png"
        }

        MText {
            anchors.verticalCenter: parent.verticalCenter
            text: "交班后打印"
            color: "black"
            font.pixelSize: 0.6*parent.height
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            printSelection.select = !printSelection.select
            printSelected(printSelection.select)
        }
    }
}

