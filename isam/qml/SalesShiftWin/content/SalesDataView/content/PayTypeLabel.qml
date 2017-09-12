import QtQuick 2.0
import "../../../../Common/Button"
import "../../../../Common/Text"

Rectangle {
    id: payTypeLabel
    property string icon: ""
    property string title: ""
    property string money: ""

    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent

        Row {
            width: 0.4*parent.width; height: parent.height
            spacing: 5

            ImageButton {
                anchors.verticalCenter: parent.verticalCenter
                width: height; height: parent.height
                scaleWidth: 1.3
                scaleHeight: 1.3
                backGroundColor: "#00000000"
                source: icon
            }

            MText {
                anchors.verticalCenter: parent.verticalCenter
                text: payTypeLabel.title
                font.pixelSize: 0.3*payTypeLabel.height
            }
        }

        Item {
            width: 0.6*parent.width; height: parent.height

            MText {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 15
                text: payTypeLabel.money
                font.bold: true
                font.pixelSize: 0.3*payTypeLabel.height
            }
        }
    }
}
