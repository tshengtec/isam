import QtQuick 2.0

Rectangle {
    signal isClicked()
    signal isPressed()
    signal isReleased()
    property string btnText: ""
    property alias btnColor: textId.color
    property variant textObj: textId
    property alias fontPixelSize: textId.font.pixelSize
    width: parent.width; height: parent.height
    color: "#00000000"

    Text {
        id: textId
        anchors.centerIn: parent
        text: btnText
        color: "white"
        font.pixelSize: parent.height/2.5
    }

    MouseArea {
        anchors.fill: parent
        onClicked: isClicked()
        onPressed: isPressed()
        onReleased: isReleased()
    }
}
