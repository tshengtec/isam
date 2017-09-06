import QtQuick 2.0

Item {
    id: itemId
    signal logout()
    property alias text: textId.text
    property string icon: ""

    width: parent.width; height: parent.height

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        height: parent.height
        spacing: 10

        Image {
            anchors.verticalCenter: parent.verticalCenter
            width: 0.8*itemId.width/10; height: width
            source: icon
        }

        Text {
            id: textId
            visible: true
            width: 5.5*itemId.width/10; height: itemId.height
            verticalAlignment: Text.AlignVCenter
            text: ""
            elide: Text.ElideMiddle
            clip: true
            color: "#1f1f1f"
            font.pixelSize: height/3
        }

        Rectangle {
            width: 1.2*itemId.width/10; height: 0.5*itemId.height
            anchors.verticalCenter: parent.verticalCenter
            radius: 5
            border.color: "blue"

            Text {
                anchors.centerIn: parent
                text: "注销"
                color: "blue"
                font.pixelSize: parent.height/2
            }

            MouseArea {
                anchors.fill: parent
                onClicked: logout()
                hoverEnabled: true
                onEntered: parent.color = "#d5d5d5"
                onExited: parent.color = "#00000000"
                onPressed: parent.color = "lightblue"
                onReleased: parent.color = "#00000000"
            }
        }
    }
}
