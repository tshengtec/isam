import QtQuick 2.0

Rectangle {
    id: root
    signal isClicked()
    property string source: ""
    property var scaleHeight: 1 //0.1 - 1.0
    width: parent.height; height: width
    color: "#00000000"

    Image {
        anchors.centerIn: parent
        width: 0.5*parent.height; height: scaleHeight*width
        source: root.source
    }

    MouseArea {
        anchors.fill: parent
        onClicked: isClicked()
        hoverEnabled: true
        onEntered: parent.color = "#30000000"
        onExited: parent.color = "#00000000"
    }
}
