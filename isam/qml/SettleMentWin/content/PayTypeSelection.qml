import QtQuick 2.0
import "../../ProjectCommon/Button"
import "../../Common/Button"
import "../../Common/Text"

Rectangle {
    property bool cash: true
    property bool alipay: false
    property bool wxpay: false

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
                width: parent.width - 15; height: parent.height - 15
                spacing: 5

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/money.png"
                    text: "现金"
                    select: cash
                    onClicked: privateValue.checkStatus(!cash, wxpay, alipay) ?
                                   cash = !cash : ""
                }

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/weChatPay.png"
                    text: "微信"
                    select: wxpay
                    onClicked: privateValue.checkStatus(cash, !wxpay, alipay) ?
                                   wxpay = !wxpay : ""
                }

                LeftIconRightTextBtn {
                    width: parent.width; height: (parent.height - 2*parent.spacing)/3
                    icon: "qrc:/image/settleMentWin/alipay.png"
                    text: "支付宝"
                    select: alipay
                    onClicked: privateValue.checkStatus(cash, wxpay, !alipay) ?
                                   alipay = !alipay : ""
                }
            }
        }

        Item { width: 0.02*parent.width; height: parent.height }

        Rectangle {
            id: payCom
            property bool select: false
            visible: false
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
                    privateValue.isGroup = payCom.select
                    if (!privateValue.isGroup)
                        privateValue.payIndex = 1
                }
            }
        }
    }

    Item {
        id: privateValue
        property bool isGroup: false;
        property var payStatusMapList:[{"cash": true, "alipay": false, "wxpay": false},
                                       {"cash": false, "alipay": true, "wxpay": false},
                                       {"cash": false, "alipay": false, "wxpay": true},
                                       {"cash": true, "alipay": true, "wxpay": false},
//                                       {"cash": false, "alipay": true, "wxpay": true},
                                       {"cash": true, "alipay": false, "wxpay": true}
                                      ]

        function checkStatus(cash, wxpay, alipay) {
            var _cash, _alipay, _wxpay;
            for (var i = 0; i < payStatusMapList.length; i++) {
                _cash = payStatusMapList[i].cash
                _alipay = payStatusMapList[i].alipay
                _wxpay = payStatusMapList[i].wxpay
                if (_cash === cash && _alipay === alipay && _wxpay === wxpay)
                    return true
            }
            return false
        }
    }

    function init() {
        cash = true
        alipay = false
        wxpay = false
    }
}
