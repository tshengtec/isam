import QtQuick 2.0
import "../Common/Button"

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
            anchors.horizontalCenter: parent.horizontalCenter
            width: 8*windowsId.width/20; height: 5*windowsId.height/10
            border.color: "#e5e5e5"
            border.width: 1
            radius: 5
        }

        MenuButton {
            width: 8*windowsId.width/20; height: 1*windowsId.height/10
            btnText: "登录"
        }
    }
}
