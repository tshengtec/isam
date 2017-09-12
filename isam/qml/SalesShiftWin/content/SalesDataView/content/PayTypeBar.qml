import QtQuick 2.0

Item {
    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent
        spacing: 20

        Row {
            width: (parent.width - 2*20)/3; height: parent.height
            spacing: 5

            Rectangle {
                width: height; height: parent.height
                color: "#f59c0c"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height
                text: "现金支付"
            }
        }

        Row {
            width: (parent.width - 2*20)/3; height: parent.height
            spacing: 5

            Rectangle {
                width: height; height: parent.height
                color: "#31ce4b"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height
                text: "微信支付"
            }
        }


        Row {
            width: (parent.width - 2*20)/3; height: parent.height
            spacing: 5

            Rectangle {
                width: height; height: parent.height
                color: "#17a1de"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height
                text: "支付宝支付"
            }
        }
    }
}
