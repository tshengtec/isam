import QtQuick 2.0
import "../Text"

Rectangle {
    id: iconButton

    property string icon: ""
    property string title: ""
    property bool noteStatus: false

    signal clicked()
    signal pressed()
    signal released()
    signal entered()
    signal exited()

    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        anchors.fill: parent
        clip: true

        Image {
            width: height; height: 0.65*iconButton.height
            anchors.horizontalCenter: parent.horizontalCenter
            source: icon
        }

        MText {
            anchors.horizontalCenter: parent.horizontalCenter
            width: title.length*font.pixelSize; height: 0.35*iconButton.height
            text: title
            color: "white"
            font.pixelSize: 0.7*height/*0.25*iconButton.width*/
        }
    }

    Rectangle {
        id: statusId
        visible: noteStatus
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        width: 1.5*parent.width/10; height: width
        color: "#ff8400"
        radius: width/2
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            iconButton.color = "#30000000"
            iconButton.entered()
        }
        onExited: {
            iconButton.color = "#00000000"
            iconButton.exited()
        }
        onClicked: iconButton.clicked()
        onPressed: iconButton.pressed()
        onReleased: iconButton.released()
    }
}
