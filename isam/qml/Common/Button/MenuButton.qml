import QtQuick 2.0

BaseButton {
    id: baseButton
    radius: 8
    color: "blue"

    onIsPressed: {
        baseButton.color = "white"
        textObj.color = "black"
    }
    onIsReleased: {
        baseButton.color = "blue"
        textObj.color = "white"
    }
}
