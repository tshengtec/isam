import QtQuick 2.0
import "../ProjectCommon/Bar"
import "./content/LeftPart"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopTitleBar {
            width: parent.width; height: 2*parent.height/20
            onBacked: rootId.visible = false
        }

        Row {
            width: parent.width; height: 18*parent.height/20

            LeftPart {
                width: 6*parent.width/20; height: parent.height
            }

        }

    }
}
