import QtQuick 2.0
import "../../Common/Button"
import "../../Common/Text"

Rectangle {
    id: paymentOperation

    signal deleted()

    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        anchors.fill: parent
        spacing: 10

        Row {
            width: parent.width; height: 0.25*(parent.height-30)
            spacing: 10

            Rectangle {
                id: deleteButton
                property bool select: false
                width: 0.28*parent.width; height: parent.height
                color: select ? "#f34b53" : "white"
                radius: 8

                ImageButton {
                    anchors.centerIn: parent
                    width: 0.4*parent.width; height: 0.6*parent.height
                    scaleWidth: 2.7; scaleHeight: 1.8
                    backGroundColor: "#00000000"
                    source: "qrc:/image/settleMentWin/delete.png"
                }

                MouseArea {
                    anchors.fill: parent
                    onPressed: deleteButton.select = true
                    onReleased: deleteButton.select = false
                    onClicked: deleted()
                }
            }

            Rectangle {
                id: payCom
                property bool select: false
                anchors.verticalCenter: parent.verticalCenter
                width: 0.46*parent.width; height: parent.height
                color: select ? "#baceef" : "white"
                radius: 8

                Row {
                    anchors.fill: parent
                    clip: true

                    Item {
                        width: 0.5*parent.width; height: parent.height
                        Image {
                            width: height; height: 0.4*parent.height
                            anchors.centerIn: parent
                            source: payCom.select ?
                                           "qrc:/image/settleMentWin/selected.png" : "qrc:/image/settleMentWin/select.png"
                        }
                    }

                    Item {
                        width: 0.5*parent.width; height: parent.height
                        MText {
                            anchors.verticalCenter: parent.verticalCenter
                            text: "组合支付"
                            color: "black"
                            font.pixelSize: 0.3*parent.height
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        payCom.select = !payCom.select
                    }
                }
            }

        }
    }
}
