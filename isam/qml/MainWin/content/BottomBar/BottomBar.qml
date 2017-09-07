import QtQuick 2.0
import "../../../Common/Text"
import "../../../Common/Button"
import "../../../Common/SliderButton"
import "./content"

Rectangle {
    id: rootRectId
    signal searched(string barCodeText)
    signal settleMented()
    width: parent.width; height: parent.height
//    color: "lightblue"

    Row {
        width: parent.width; height: parent.height

        Item { width: 0.2*rootRectId.width/20; height: 1 }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: 6*rootRectId.width/20; height: rootRectId.height
            spacing: 1*rootRectId.height/20

            Item { width: 1; height: 1 }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                defaultText: "扫描条形码"
                border.color: "#c2c2c2"
                onIsReturnPressed: searched(barCodeText)
                rightIcon: "qrc:/image/mainWin/board/board.png"
            }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                defaultText: "输入价格无码收银(未完成)"
                border.color: "#c2c2c2"
                rightIcon: "qrc:/image/mainWin/board/board.png"
            }

            SpecialOffersBar {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10

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
