import QtQuick 2.0
import "../../Common/Button"
import "../../Common/Text"

Rectangle {
    id: leftIconRightTextBtn

    signal clicked()

    property string icon: ""
    property string text: ""
    property bool select: false

    width: parent.width; height: parent.height
    radius: 5
    color: select ? "#baceef" : "white"

    Row {
        anchors.fill: parent

        Item {
            width: 0.4*parent.width; height: parent.height

            ImageButton {
                anchors.horizontalCenter: parent.horizontalCenter
                width: height; height: parent.height
                scaleWidth: 1.4
                scaleHeight: 1.4
                backGroundColor: "#00000000"
                source: icon
            }
        }

        Item {
            width: 0.6*parent.width; height: parent.height

            MText {
                anchors.centerIn: parent
                text: leftIconRightTextBtn.text
                font.pixelSize: 0.3*leftIconRightTextBtn.height
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            leftIconRightTextBtn.clicked()
        }
    }
}
