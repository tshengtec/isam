import QtQuick 2.0

BaseButton {
    property bool statusModel: false
    property string btnColor: "#6ef2a0"
    property string btnPressColor: "white"
    id: baseButton
    radius: 8
    color: btnColor

    onIsPressed: {
        baseButton.color = btnPressColor
        textObj.color = "black"
    }
    onIsReleased: {
        baseButton.color = btnColor
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
