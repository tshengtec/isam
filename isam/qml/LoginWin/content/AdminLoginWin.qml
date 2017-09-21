import QtQuick 2.0
import "../../Common/Button"

Item {
    id: itemId
    property variant adminAccountModel
    width: parent.width; height: parent.height
    onVisibleChanged: {
        if (visible)
            init()
    }    

    Column {
        anchors.centerIn: parent
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Rectangle {
            id: rectId
            anchors.horizontalCenter: parent.horizontalCenter
            width: 6*itemId.width/20; height: 4*itemId.height/10
            border.color: "#c0c0c0"
            border.width: 1
            radius: 5

            Column {
                width: parent.width; height: parent.height

                BaseButton {
                    width: parent.width; height: 2*parent.height/10
                    btnColor: "black"
                    btnText: "帐号登录"
                    fontPixelSize: height/3

                    BaseButton {
                        id: errorId
                        visible: adminAccountModel.error !== ""
                        onVisibleChanged: if (visible) timerId.start()
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width - 10; height: parent.height
                        color: "white"
                        btnColor: "#ff8400"
                        btnText: adminAccountModel.error
                        Timer {
                            id: timerId
                            interval: 1000; repeat: true
                            onTriggered: {
                                stop()
                                adminAccountModel.error = ""
                            }
                        }
                    }

                    Rectangle {
                        anchors.bottom: parent.bottom
                        width: parent.width; height: 2
                        color: "#d5d5d5"
                    }
                }

                Item { width: 1; height: 0.25*parent.width/10 }

                LoginTextInput {
                    id: accountId
                    width: parent.width; height: 1.5*parent.height/10
                    icon: "qrc:/image/common/account.png"
                    defaultText: "请输入帐号"
                }

                Item { width: 1; height: 0.25*parent.width/10 }

                LoginTextInput {
                    id: passwordId
                    width: parent.width; height: 1.5*parent.height/10
                    icon: "qrc:/image/common/password.png"
                    defaultText: "请输入密码"
                    echoMode: TextInput.Password
                }

                ForgetPassword {
                    width: parent.width; height: 2*parent.height/10
                    onForgetPassworded: adminAccountModel.forgetPassword()
                }

                MenuButton {
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: 0.8*parent.width; height: 2*parent.height/10
                    btnText: "登录"
                    btnColor: "#ff8400"
                    onIsClicked: {
                        adminAccountModel.loginAccount("admin", accountId.text, passwordId.text)
                    }
                }

            }
        }
    }

    function init() {
        accountId.text = "";
        passwordId.text = "";
    }
}
