import QtQuick 2.0
import "../../../../Common/Text"
import "../../../../Common/SliderButton"

ISAMTextInput {
    width: parent.width; height: parent.height
    border.color: "#c2c2c2"
    rightIcon: "qrc:/image/mainWin/board/board.png"
    textInputXOffset: leftIconItem.width + 3
    defaultText: sliderButton.onOff ? "0" : "100"

    Item {
        id: leftIconItem
        anchors.left: parent.left
        width: 3.5*parent.height; height: parent.height

        MouseArea { anchors.fill: parent }

        SliderButton {
            id: sliderButton
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width; height: 0.8*parent.height
            onOff: false
            contentText: onOff ? "整单优惠(元)" : "整单折扣(%)"
        }
    }
}

