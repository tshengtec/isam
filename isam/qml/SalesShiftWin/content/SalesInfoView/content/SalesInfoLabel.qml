import QtQuick 2.0
import "../../../../Common/Text"

Rectangle {
    property string title: ""
    property string content: ""

    width: parent.width; height: parent.height
    color: "white"
    radius: 8

    Column {
        anchors.centerIn: parent
        spacing: 10

        Item {
            width: salesInfoView.width; height: 0.2*salesInfoView.height
            MText {
                anchors.centerIn: parent
                text: title
                color: "black"
                font.pixelSize: parent.height
            }
        }

        Item {
            width: salesInfoView.width; height: 0.2*salesInfoView.height
            MText {
                anchors.centerIn: parent
                text: content
                color: "#ff8400"
                font.bold: true
                font.pixelSize: parent.height
            }
        }
    }
}

