import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: root

    signal dropDownList()
    signal minimize()
    signal maximize()
    signal close()

    width: parent.width; height: parent.height
    color: "#38384e"

    MouseArea {
        anchors.fill: parent
        onDoubleClicked: maximize()
        property point clickPos: "0, 0"
        onPressed: clickPos = Qt.point(mouse.x, mouse.y)
        onPositionChanged: {
            var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
//            windowsId
            windowsId.setX(windowsId.x + delta.x)
            windowsId.setY(windowsId.y + delta.y)
        }
    }

    Row {
        anchors {right: parent.right; rightMargin: 10; verticalCenter: parent.verticalCenter }
        spacing: 15

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/dropDownList.png"
            onIsClicked: dropDownList()
        }

        ImageButton {
            width: root.height; height: width
            scaleHeight: 0.2
            source: "qrc:/image/mainWin/minimize.png"
            onIsClicked: minimize()
        }

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/maximize.png"
            onIsClicked: maximize()
        }

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/close.png"
            onIsClicked: close()
        }
    }
}
