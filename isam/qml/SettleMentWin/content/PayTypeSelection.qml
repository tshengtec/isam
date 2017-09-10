import QtQuick 2.0
import "../../ProjectCommon/Button"
import "../../Common/Button"
import "../../Common/Text"

Rectangle {
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        width: parent.width; height: parent.height

        Rectangle {
            width: 0.5*parent.width; height: parent.height
            color: "#d7d7d7"
            radius: 5

            Column {
                anchors.centerIn: parent
                width: parent.width - 10; height: parent.height - 10
                spacing: 5

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/money.png"
                    text: "现金"
                }

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/weChatPay.png"
                    text: "微信"
                }

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/alipay.png"
                    text: "支付宝"
                }
            }
        }

        Item { width: 0.02*parent.width; height: parent.height }

        Rectangle {
            id: payCom
            property bool select: false
            anchors.verticalCenter: parent.verticalCenter
            width: parent.height/3; height: parent.height/3
            color: select ? "#baceef" : "white"
            radius: 8

            Column {
                anchors.fill: parent
                clip: true

                Item {
                    width: parent.width; height: 0.6*parent.height
                    Image {
                        width: height; height: 0.6*parent.height
                        anchors.centerIn: parent
                        source: payCom.select ?
                                       "qrc:/image/settleMentWin/selected.png" : "qrc:/image/settleMentWin/select.png"
                    }
                }

                Item {
                    width: parent.width; height: 0.4*parent.height
                    MText {
                        anchors.centerIn: parent
                        text: "组合支付"
                        color: "black"
                        font.pixelSize: 0.5*parent.height
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
