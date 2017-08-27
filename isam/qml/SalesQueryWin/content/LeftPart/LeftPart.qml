import QtQuick 2.0

Rectangle {
    width: parent.width; height: parent.height
    color: "#d5d5d5"

    Column {
        anchors.fill: parent

        SalesTopBar {
            width: parent.width; height: 2*parent.height/20
        }
    }
}
