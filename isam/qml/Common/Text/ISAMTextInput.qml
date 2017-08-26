import QtQuick 2.5

Rectangle {
    signal isReturnPressed()
    width: parent.width; height: parent.height
    radius: 3
    color: "white"
    border.color: "cyan"
    border.width: 1

    TextInput {
        id: textInputId
        anchors.verticalCenter: parent.verticalCenter
        x: 2
        clip: true
        width: parent.width - 2*x; height: parent.height/1.5
        font.pixelSize: height
        Keys.onReturnPressed: isReturnPressed()
    }
}

