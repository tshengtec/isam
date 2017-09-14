import QtQuick 2.5

Rectangle {
    signal isReturnPressed(string barCodeText)
    property alias text: textInputId.text
    property alias textColor: textInputId.color
    property string defaultText: ""
    property string rightIcon: ""
    property int textInputXOffset: 0

    width: parent.width; height: parent.height
    radius: 3
    color: "white"
    border.color: "cyan"
    border.width: 1

    TextInput {
        id: textInputId
        anchors.verticalCenter: parent.verticalCenter
        x: 2 + textInputXOffset
        clip: true
        width: parent.width - 2*2 - (rightIcon === "" ? 0 : rightIconItem.width) - textInputXOffset;
//        font.family: "微软雅黑"
        color: "#858585"
        height: parent.height/1.5
        font.pixelSize: height
        Keys.onReturnPressed: isReturnPressed(text)
    }

    MText {
        x: 2 + textInputXOffset
        visible: parent.text === "" //&& textInputId.focus === false
        font.pixelSize: parent.height/2.5
        color: "#858585"
        text: defaultText
        anchors.verticalCenter: parent.verticalCenter
    }

    Item {
        id: rightIconItem
        anchors.right: parent.right
        width: parent.height; height: parent.height

        Image {
            anchors.centerIn: parent
            width: 0.8*parent.height; height: 0.7*parent.height
            source: rightIcon
        }
    }
}

