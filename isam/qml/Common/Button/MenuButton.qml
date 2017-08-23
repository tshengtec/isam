import QtQuick 2.0

BaseButton {
    id: baseButton
    radius: 8
    color: "#6ef2a0"

    onIsPressed: {
        baseButton.color = "white"
        textObj.color = "black"
    }
    onIsReleased: {
        baseButton.color = "#6ef2a0"
        textObj.color = "white"
    }
}
