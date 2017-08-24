import QtQuick 2.0

Rectangle {
    property variant model: modelData
    id: delegeRectId
    width: parent.width; height: parent.height
    color: index%2 === 0 ? "white" : "#eeeeee"

    Rectangle {
        width: parent.width; height: 1
        color: "#d7d7d7"
    }

    Row {
        Repeater {
            model: listViewBackGroundId.count
            Item {
                width: spacingWidth[index]; height: delegeRectId.height
                clip: true
                Rectangle {
                    anchors.right: parent.right
                    width: 1; height: parent.height
                    color: "#d7d7d7"
                }
            }
        }
    }
}
