import QtQuick 2.0
import "../../Common/Text"

Rectangle {
    id: textInputNumber

    property string rightNumberColor: "black"
    property alias rightNumnber: textInput.text
    property string addText: ""
    property string leftTitle: ""
    property string leftTitleColor: "black"
    property bool enable: true
    property alias textInputFocus: textInput.focus
    property bool isSubText: false

    width: parent.width; height: parent.height
    radius: 8

    onAddTextChanged: {
        var text = textInput.text
        var cursorPosition = textInput.cursorPosition
        var startText = text.slice(0, textInput.cursorPosition)
        var endText = text.slice(textInput.cursorPosition, text.length)
        textInput.text = startText + addText + endText
        textInput.cursorPosition = textInput.text.length - (text.length - cursorPosition)
    }

    onIsSubTextChanged: {
        if (isSubText) {
            var text = textInput.text
            var cursorPosition = textInput.cursorPosition
            var startText = text.slice(0, textInput.cursorPosition - 1)
            var endText = text.slice(textInput.cursorPosition, text.length)
            textInput.text = startText + endText
            textInput.cursorPosition = textInput.text.length - (text.length - cursorPosition)
            isSubText = false
        }
    }

    Row {
        z: 2
        anchors.fill: parent

        Item { width: 15; height: 1 }

        Item {
            width: 0.2*parent.width; height: parent.height

            MText {
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 0.3*parent.height
                text: leftTitle
                color: leftTitleColor
            }
        }

        Item {
            width: 0.8*parent.width - 15; height: parent.height

            TextInput {
                id: textInput
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignRight
                clip: true
                font.bold: true
                enabled: enable
                font.family: "微软雅黑"
                color: enable ? rightNumberColor : "#d5d5d5"
//                text: rightNumnber
                text: "0.00"
                font.pixelSize: 0.5*parent.height
                width: parent.width;
//                onFocusChanged: {
//                    if (focus) {
//                        cursorPosition = text.length
//                    }
//                }
            }
        }
    }




    Rectangle {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 2*textInputNumber.radius; height: 2*textInputNumber.radius
        radius: textInputNumber.radius
        border.color: "#b7b7b7"
    }

    Rectangle {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 2*textInputNumber.radius; height: 2*textInputNumber.radius
        radius: textInputNumber.radius
        border.color: "#b7b7b7"
    }
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 2*textInputNumber.radius; height: 1
        color: "#b7b7b7"
    }

    Rectangle {
        y: parent.height - 2
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 2*textInputNumber.radius; height: 1
        color: "#dcdcdc"
    }

    Rectangle {
        y: 0.5*parent.height - 2
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width -2; height: 0.5*parent.height
        radius: textInputNumber.radius
    }
}
