import QtQuick 2.0
import "../Button"

Rectangle {
    width: parent.width; height: parent.height
    color: "#90000000"

    Rectangle {
        anchors.centerIn: parent
        width: 0.33*parent.width; height: 0.4*parent.height
        radius: 8
        color: "#ff8400"

        Column {
            anchors.fill: parent

            Item {
                width: parent.width; height: 0.1*parent.height
            }

            Rectangle {
                width: parent.width; height: 0.65*parent.height
                color: "#00000000"
            }

            Row {
                width: parent.width; height: 0.25*parent.height

                NormalButton {
                    width: parent.width/2; height: parent.height
                    color: "white"
                    btnText: "确定"
                    btnColor: "blue"
                    fontPixelSize: height/3
                }

                Rectangle { width: 1; height: parent.height; color: "#c0c0c0"}

                NormalButton {
                    width: parent.width/2; height: parent.height
                    color: "white"
                    btnText: "取消"
                    btnColor: "blue"
                    fontPixelSize: height/3
                }
            }
        }
    }
}
