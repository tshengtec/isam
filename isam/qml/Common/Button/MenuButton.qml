import QtQuick 2.0

BaseButton {
    property bool statusModel: false
    id: baseButton
    radius: 8
    color: "#6ef2a0"

    onIsPressed: {
        baseButton.color = "white"
        textObj.color = "black"
    }
    onIsReleased: {
        baseButton.color = "#6ef2a0"
        textObj.color = "white"
    }

    Rectangle {
        id: statusId
        visible: statusModel
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        width: 1.5*parent.width/10; height: width
        color: "#ff8400"
        radius: width/2
    }
}
