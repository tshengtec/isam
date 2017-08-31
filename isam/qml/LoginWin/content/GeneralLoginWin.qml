import QtQuick 2.0
import "../../Common/Button"

Item {
    id: itemId
    property bool isLoginSuccess: false
    property variant adminAccountModel
    width: parent.width; height: parent.height

    Column {
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            id: rectId
            anchors.horizontalCenter: parent.horizontalCenter
            width: 7*itemId.width/20; height: 4*itemId.height/10
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
                    text: "员工登录"
                    font.pixelSize: height/2.5

                    Rectangle {
                        anchors.bottom: parent.bottom
                        width: parent.width; height: 2
                        color: "#d5d5d5"
                    }
                }

                LoginTextInput {
                    id: accountId
                    width: parent.width; height: 2*parent.height/10
                    defaultText: "员工登录"
                }

                LoginTextInput {
                    id: passwordId
                    width: parent.width; height: 2*parent.height/10
                    defaultText: "填写密码"
                }

                ForgetPassword {
                    width: parent.width; height: 2*parent.height/10
                }
            }
        }

        MenuButton {
            width: 7*itemId.width/20; height: 1*itemId.height/10
            btnText: "登录"
            onIsClicked: {
                accountModel.verifyAccount()
            }
        }
    }

}

