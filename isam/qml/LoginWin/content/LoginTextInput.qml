import QtQuick 2.0

Item {
    property alias defaultText: defaultTextId.text
    property alias text: textInputId.text
    property alias echoMode: textInputId.echoMode
    property string icon: ""
    id: itemId
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

        TextInput {
            id: textInputId
            width: 7*itemId.width/10; height: parent.height
            verticalAlignment: Text.AlignVCenter
            text: ""
            font.pixelSize: height/2
            clip: true

            Text {
                id: defaultTextId
                visible: (parent.text.length == 0)
                width: parent.width; height: parent.height
                verticalAlignment: Text.AlignVCenter
                text: ""
                color: "#cccccc"
                font.pixelSize: height/2.5
            }

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width; height: 1
                color: "#d5d5d5"
            }
        }
    }
}


