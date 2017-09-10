import QtQuick 2.0
import "../../Common/Text"

Rectangle {
    id: salesInfoView
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        anchors.fill: parent
        spacing: 15

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: (parent.width - 3*parent.spacing)/3; height: parent.height
            color: "white"
            radius: 8

            Column {
                anchors.centerIn: parent
                spacing: 10

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "总金额"
                        color: "black"
                        font.pixelSize: parent.height
                    }
                }

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "0.00"
                        color: "#ff8400"
                        font.bold: true
                        font.pixelSize: parent.height
                    }
                }
            }

            Column {
                anchors.centerIn: parent
                spacing: 10

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "总金额"
                        color: "black"
                        font.pixelSize: parent.height
                    }
                }

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "0.00"
                        color: "#ff8400"
                        font.bold: true
                        font.pixelSize: parent.height
                    }
                }
            }

            Column {
                anchors.centerIn: parent
                spacing: 10

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "总金额"
                        color: "black"
                        font.pixelSize: parent.height
                    }
                }

                Item {
                    width: salesInfoView.width; height: 0.2*salesInfoView.height
                    MText {
                        anchors.centerIn: parent
                        text: "0.00"
                        color: "#ff8400"
                        font.bold: true
                        font.pixelSize: parent.height
                    }
                }
            }

        }

    }
}
