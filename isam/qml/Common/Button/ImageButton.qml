import QtQuick 2.0

Rectangle {
    id: imageButton
    signal clicked()
    property string source: ""
    property var scaleHeight: 1 //0.1 - 1.0
    property var scaleWidth: 1 //0.1 - 1.0
    width: parent.height; height: width
    color: "#00000000"

    Image {
        anchors.centerIn: parent
        width: 0.5*parent.height*scaleWidth; height: scaleHeight*parent.height*0.5
        source: imageButton.source
    }

    MouseArea {
        anchors.fill: parent
        onClicked: imageButton.clicked()
        hoverEnabled: true
        onEntered: parent.color = "#30000000"
        onExited: parent.color = "#00000000"
    }
}
