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

                BaseButton {
                    width: parent.width; height: 2.5*parent.height/10
                    btnColor: "black"
                    btnText: "帐号登录"

                    BaseButton {
                        id: errorId
                        visible: false
                        onVisibleChanged: if (visible) timerId.start()
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width - 10; height: parent.height
                        color: "white"
                        btnColor: "#ff8400"
                        btnText: "帐号或密码错误"
                        Timer {
                            id: timerId
                            interval: 1000; repeat: true
                            onTriggered: {
                                stop()
                                errorId.visible = false
                            }
                        }
                    }

                    Rectangle {
                        anchors.bottom: parent.bottom
                        width: parent.width; height: 2
                        color: "#d5d5d5"
                    }
                }

                Item { width: 1; height: 0.5*parent.width/10 }

                LoginTextInput {
                    id: accountId
                    width: parent.width; height: 2*parent.height/10
                    defaultText: "请输入帐号"
                }

                Item { width: 1; height: 0.5*parent.width/10 }

                LoginTextInput {
                    id: passwordId
                    width: parent.width; height: 2*parent.height/10
                    defaultText: "填写密码"
                    echoMode: TextInput.Password
                }

//                ForgetPassword {
//                    width: parent.width; height: 2*parent.height/10
//                }
            }
        }

        MenuButton {
            width: 7*itemId.width/20; height: 1*itemId.height/10
            btnText: "登录"
            onIsClicked: {
                adminAccountModel.isAdminLogged = adminAccountModel.loginAccount("admin", accountId.text, passwordId.text)
                errorId.visible = !adminAccountModel.isAdminLogged
            }
        }
    }

    function init() {
        accountId.text = "";
        passwordId.text = "";
    }
}
