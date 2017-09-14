import QtQuick 2.0
import "./content"
import "../../../Common/Button"
import "../../../Common/Text"

Rectangle {
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        anchors.fill: parent

        PrintSelection {
            width: 0.5*parent.width; height: parent.height
        }

        Item {
            id: item
            width: 0.5*parent.width; height: parent.height

            Row {
                anchors.right: parent.right
                spacing: 10

                MenuButton {
                    width: 0.23*item.width; height: item.height
                    btnText: "今日销售统计"
                    btnColor: "#f59c0c"
                    radius: 5
                }

                MenuButton {
                    width: 0.23*item.width; height: item.height
                    btnText: "交班并退出"
                    btnColor: "#4284f4"
                    radius: 5
                    onIsClicked: globalModel.window.close()
                }
            }
        }
    }
}
