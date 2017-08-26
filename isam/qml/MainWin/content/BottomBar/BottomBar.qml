import QtQuick 2.0
import "../../../Common/Text"

Rectangle {
    id: rootRectId
    signal searched()
    width: parent.width; height: parent.height
    color: "lightblue"

    Row {
        width: parent.width; height: parent.height

        Item { width: 0.5*rootRectId.width/20; height: 1 }

        Column {
            anchors.verticalCenter: parent.verticalCenter
            width: 6*rootRectId.width/20; height: rootRectId.height
            spacing: 1*rootRectId.height/20

            Item { width: 1; height: 1 }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
                onIsReturnPressed: searched()
            }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
            }

            ISAMTextInput {
                width: 6*rootRectId.width/20; height: 2.5*rootRectId.height/10
            }
        }

        Item { width: 3*rootRectId.width/20; height: 1 }

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: 10*rootRectId.width/20; height: 9*rootRectId.height/10
            color: "red"
            radius: 5
        }
    }
}
