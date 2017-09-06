import QtQuick 2.0
import "../Text"
import "../Button"

Rectangle {
    id: root

    signal cancel()
    signal sure()
    width: parent.width; height: parent.height
    color: "#90000000"
    visible: false

    Rectangle {
        anchors.centerIn: parent
        width: 0.33*parent.width; height: 0.4*parent.height
        radius: 8
        color: "#ff8400"

        Column {
            anchors.fill: parent

            Item {
                anchors.right: parent.right
                width: 0.08*parent.width; height: 0.1*parent.height

                Image {
                    anchors.centerIn: parent
                    source: "qrc:/image/loginWin/close.png"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: { hide(); cancel(); }
                        hoverEnabled: true
                        onEntered: parent.source = "qrc:/image/loginWin/selectedclose.png"
                        onExited: parent.source = "qrc:/image/loginWin/close.png"
                    }
                }
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                height: 0.65*parent.height
                spacing: 10

                Image {
                    anchors.verticalCenter: parent.verticalCenter
                    width: tipsLogoutInfo.font.pixelSize; height: width
                    source: "qrc:/image/loginWin/tips.png"
                }

                MText {
                    id: tipsLogoutInfo
                    anchors.verticalCenter: parent.verticalCenter
                    text: "你确定要注销当前账户吗？"
                    color: "white"
                    font.pixelSize: 0.13*parent.height
                }
            }

            Row {
                width: parent.width; height: 0.25*parent.height

                NormalButton {
                    width: parent.width/2; height: parent.height
                    color: "white"
                    btnText: "确定"
                    fontPixelSize: height/3
                    onIsClicked: { hide(); sure() }
                }

                Rectangle { width: 1; height: parent.height; color: "#c0c0c0"}

                NormalButton {
                    width: parent.width/2 -1; height: parent.height
                    color: "white"
                    btnText: "取消"
                    fontPixelSize: height/3
                    onIsClicked: { hide(); cancel() }
                }
            }
        }
    }

    function show() {
        root.visible = true
    }

    function hide() {
        root.visible = false
    }
}
