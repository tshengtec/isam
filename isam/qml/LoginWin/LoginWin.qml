import QtQuick 2.0
import "../Common/Button"
import "./content"

Rectangle {
    id: windowsId
    width: parent.width; height: parent.height

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightsteelblue" }
        GradientStop { position: 1.0; color: "blue" }
    }

    Column {
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            id: rectId
            anchors.horizontalCenter: parent.horizontalCenter
            width: 7*windowsId.width/20; height: 4*windowsId.height/10
            border.color: "#e5e5e5"
            border.width: 1
            radius: 5

            Column {
                width: parent.width; height: parent.height
                spacing: 8

                Text {
                    width: parent.width; height: 2.5*parent.height/10
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "帐号登录"
                    font.pixelSize: height/2.5

                    Rectangle {
                        anchors.bottom: parent.bottom
                        width: parent.width; height: 2
                        color: "#d5d5d5"
                    }
                }

                LoginTextInput {
                    width: parent.width; height: 2*parent.height/10
                    text: "帐号登录"
                }

                LoginTextInput {
                    width: parent.width; height: 2*parent.height/10
                    text: "填写密码"
                }

                ForgetPassword {
                    width: parent.width; height: 2*parent.height/10
                }
            }
        }

        MenuButton {
            width: 7*windowsId.width/20; height: 1*windowsId.height/10
            btnText: "登录"
        }
    }
}
