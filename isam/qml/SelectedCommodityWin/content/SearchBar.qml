import QtQuick 2.0

Item {
    signal searched(string text)
    property alias textInputFocus: textInputId.focus
    property alias text: textInputId.text
    width: parent.width; height: parent.height

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 40; height: parent.height
        color: "white"
        border.color: "#00787d"

        TextInput {
            id: textInputId
            x: 2
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width - 2*x; height: parent.height/1.5
            font.pixelSize: height
            Keys.onReturnPressed: searched(text)
        }
    }

}
