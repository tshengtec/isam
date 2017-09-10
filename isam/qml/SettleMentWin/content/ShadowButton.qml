import QtQuick 2.0
import "../../Common/Text"

Rectangle {
    id: shadowButton

    signal clicked()

    property string title: ""
    property string titleColor: "black"
    property bool enable: true

    width: parent.width; height: parent.height
    radius: 8

    Rectangle {
        z: 2
        width: parent.width; height: parent.height
        radius: parent.radius
        color: parent.color

        MText {
            anchors.centerIn: parent
            font.pixelSize: 0.5*parent.height
            text: title
            color: titleColor
        }

        MouseArea {
            anchors.fill: parent
            onClicked: shadowButton.clicked()
            onPressed: parent.color = "#baceef"
            onReleased: parent.color = shadowButton.color
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 2*shadowButton.radius; height: 2*shadowButton.radius
        radius: shadowButton.radius
        border.color: "#b7b7b7"
    }

    Rectangle {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 2*shadowButton.radius; height: 2*shadowButton.radius
        radius: shadowButton.radius
        border.color: "#b7b7b7"
    }
    Rectangle {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 2*shadowButton.radius; height: 1
        color: "#b7b7b7"
    }

    Rectangle {
        y: parent.height - 2
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 2*shadowButton.radius; height: 1
        color: "#dcdcdc"
    }

    Rectangle {
        y: 0.5*parent.height - 2
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width -2; height: 0.5*parent.height
        radius: shadowButton.radius
    }
}

