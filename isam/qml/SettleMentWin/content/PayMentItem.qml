import QtQuick 2.0

Rectangle {
    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        anchors.centerIn: parent
        width: parent.width; height: 0.9*parent.height

        Row {
            width: parent.width; height: 0.4*parent.height

            Item { width: 0.15*parent.width; height: parent.height }

            EditPayNumber {
                width: 0.5*parent.width; height: parent.height
            }

            Item { width: 0.01*parent.width; height: parent.height }

            PayTypeSelection {
                width: 0.45*parent.width; height: parent.height

            }
        }
    }
}
