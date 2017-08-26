import QtQuick 2.0

Rectangle {
    property variant model: modelData
    property variant contentSpacingWidth: []
    id: delegeRectId
    width: parent.width; height: parent.height
    color: index%2 === 0 ? "white" : "#eeeeee"
    clip: true

//    Rectangle {
//        width: parent.width; height: 1
//        color: "#d7d7d7"
//    }

    Row {
        Repeater {
            model: contentSpacingWidth.length
            Item {
                width: contentSpacingWidth[index]; height: delegeRectId.height
//                clip: true
                Rectangle {
                    anchors.right: parent.right
                    width: 1; height: parent.height
                    color: "#d7d7d7"
                }
            }
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width; height: 1
        clip: true
        color: "#d7d7d7"
    }
}
