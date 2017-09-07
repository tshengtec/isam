import QtQuick 2.0
import "../Text"

BaseButton {
    width: parent.width; height: parent.height
    onIsEntered: color = "#300000000"
    onIsExited: color = "#00000000"

    Row {
        Image {
            anchors.centerIn: parent
            width: 0.5*parent.height; height: scaleHeight*width
            source: root.source
        }

        MText {

        }
    }
}
