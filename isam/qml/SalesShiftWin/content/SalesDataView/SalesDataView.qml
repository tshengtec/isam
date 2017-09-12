import QtQuick 2.0
import "./content"

Rectangle {
    width: parent.width; height: parent.height
    color: "#e7eded"

    Row {
        anchors.fill: parent

        Item { width: 0.05*parent.width; height: 1 }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: 0.3*parent.width; height: 0.8*parent.height
            spacing: 20

            PayTypeLabel {
                width: parent.width; height: (parent.height - 2*20)/3;
                icon: "qrc:/image/common/money.png"
                title: "现金"
                money: "0.00"
            }

            PayTypeLabel {
                width: parent.width; height: (parent.height - 2*20)/3;
                icon: "qrc:/image/common/weChatPay.png"
                title: "微信"
                money: "0.00"
            }

            PayTypeLabel {
                width: parent.width; height: (parent.height - 2*20)/3;
                icon: "qrc:/image/common/alipay.png"
                title: "支付宝"
                money: "0.00"
            }
        }

        Item { width: 0.15*parent.width; height: 1 }

        Column {
            width: 0.4*parent.width; height: parent.height

            Item { width: 1; height: 0.1*parent.height }

            CircularStatistics {
                anchors.horizontalCenter: parent.horizontalCenter
                width: height; height: 0.7*parent.height
            }

            Item { width: 1; height: 0.1*parent.height }

            PayTypeBar {
                width: parent.width; height: 0.06*parent.height
            }
        }
    }
}
