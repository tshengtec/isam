import QtQuick 2.0
import "../../Common/Button"

Item {
    id: selectBar

    signal searched(string text)
    property alias textInputFocus: textInputId.focus
    property alias text: textInputId.text
    width: parent.width; height: parent.height

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        width: 0.9*parent.width; height: parent.height

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: 0.942*parent.width; height: parent.height
            color: "white"
            radius: 5
            border.color: "#d5d5d5"

            TextInput {
                id: textInputId
                x: 2
                clip: true
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width - 2*x; height: parent.height/1.5
                font.pixelSize: height
                Keys.onReturnPressed: searched(text)
            }
        }

        Rectangle {
            width: 0.058*parent.width; height: width
            anchors.verticalCenter: parent.verticalCenter
            radius: 5
            color: "#5b79f5"

            Rectangle {
                anchors.left: parent.left
                width: parent.width/2; height: parent.height
                color: parent.color
            }

            ImageButton {
                anchors.centerIn: parent
                width: parent.width; height: width
                source: "qrc:/image/mainWin/search.png"
                onClicked: searched(text)
            }
        }
    }

}
