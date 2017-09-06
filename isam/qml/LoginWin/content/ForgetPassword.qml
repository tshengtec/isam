import QtQuick 2.0

Item {
    signal forgetPassworded()
    id: itemId
    width: parent.width; height: parent.height

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height
        spacing: 10

        Item {
            anchors.verticalCenter: parent.verticalCenter
            width: itemId.width/10; height: 0.7*parent.height
        }

        Item {
            width: 7*itemId.width/10; height: parent.height

            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: "忘记密码?"
                color: "#337cc9"
                font.pixelSize: parent.height/3

                MouseArea {
                    anchors.fill: parent
                    onClicked: forgetPassworded()
                    hoverEnabled: true
                    onEntered: parent.color = "black"
                    onExited: parent.color = "#337cc9"
                }
            }
        }
    }
}
