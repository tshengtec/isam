import QtQuick 2.0

BaseButton {
    width: parent.width/2; height: parent.height
    color: "white"
    btnText: "取消"
    btnColor: "blue"
    fontPixelSize: height/3
    onIsPressed: {
        backGround.color = "#60000000"
    }
    onIsReleased: {
        backGround.color = "#00000000"
    }

    Rectangle {
        id: backGround
        anchors.fill: parent
        color: "#00000000"
    }
}
