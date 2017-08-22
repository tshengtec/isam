import QtQuick 2.0

//Todo
Rectangle {
    width: parent.width; height: parent.height
    color: "blue"

    Row {
        Image {
            source: ""//logo
        }
        Text {
            text: "Soft Title"
        }
    }

    Rectangle {
        width: 200; height: parent.height
        color: "blue"
    }
}
