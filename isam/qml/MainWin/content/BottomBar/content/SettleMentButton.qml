import QtQuick 2.0
import "../../../../Common/Text"

Rectangle {
    id: settleMentButton

    signal clicked()

    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        width: parent.width; height: parent.height

        Rectangle {
            width: 0.3*parent.width; height: parent.height
            color: "#f55e63"

            Column {
                property int fontSize: 0.2*parent.height
                anchors.centerIn: parent
                width: parent.width

                MText {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: parent.fontSize
                    color: "white"
                    text: "结算"
                }
                MText {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: parent.fontSize
                    color: "white"
                    text: "(空格键)"
                }
            }
        }

        Rectangle {
            width: 0.7*parent.width; height: parent.height
            color: "#f34b53"

            Column {
                property int fontSize: 0.3*parent.height
                anchors.verticalCenter: parent.verticalCenter
                x: 20
                width: parent.width

                MText {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: parent.fontSize
                    color: "white"
                    text: "总金额"
                }
                MText {
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 1.5*parent.fontSize
                    color: "white"
                    text: "0.00"
                }
            }
        }
    }


    Rectangle {
        id: backGround
        width: parent.width; height: parent.height
        color: "#00000000"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: settleMentButton.clicked()
        onEntered: backGround.color = "#30000000"
        onExited: backGround.color = "#00000000"
    }
}
