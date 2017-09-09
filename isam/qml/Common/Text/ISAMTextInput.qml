import QtQuick 2.5

Rectangle {
    signal isReturnPressed(string barCodeText)
    property alias text: textInputId.text
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
        height: parent.height/1.5
        font.pixelSize: height
        Keys.onReturnPressed: isReturnPressed(text)
//        onTextChanged: {
//            for (var index = 0; index < text.length; index++) {
//                if (text.charCodeAt(index) > 255)
//                    return font.pixelSize = parent.height/2
//            }
//            return font.pixelSize = height
//        }
    }

    MText {
        x: 2 + textInputXOffset
        visible: parent.text === "" //&& textInputId.focus === false
        font.pixelSize: parent.height/2
        color: "#555555"
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

