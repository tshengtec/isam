import QtQuick 2.0

Rectangle {
    property variant headerModel: []
    property variant headerSpacingWidth: []
    id: headerItemId
    width: parent.width; height: parent.height
    color: "#f0f0f0"
    Row {
        Repeater {
            model: headerModel
            Item {
                width: headerSpacingWidth[index]; height: headerItemId.height

                Text {
                    anchors.centerIn: parent
                    text: modelData
                    font.pixelSize: parent.height/2.5
                }

                Rectangle {
                    anchors.right: parent.right
                    width: 1; height: parent.height
                    color: "#d7d7d7"
                }
            }
        }
    }
}
