import QtQuick 2.0
import "../../../Common/Text"
import "../../../Common/Button"

Rectangle {
    id: rootRectId
    signal searched(string barCodeText)
    signal settleMented()
    width: parent.width; height: parent.height
    color: "lightblue"

    Row {
        width: parent.width; height: parent.height

        Item { width: 0.5*rootRectId.width/20; height: 1 }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: 6*rootRectId.width/20; height: rootRectId.height
            spacing: 1*rootRectId.height/20

            Item { width: 1; height: 1 }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                defaultText: "扫描条形码"
                onIsReturnPressed: searched(barCodeText)
            }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                defaultText: "输入价格无码收银(未完成)"
            }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                defaultText: "整单优惠(未完成)"
            }
        }

        Item { width: 3*rootRectId.width/20; height: 1 }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: 10*rootRectId.width/20; height: 9*rootRectId.height/10
            btnColor: "red"
            btnPressColor: "#5cb85c"
            btnText: "结算"
            radius: 5
            onIsClicked: settleMented();
        }
    }
}
