import QtQuick 2.0
import QtQuick.Window 2.2
import "../../../Common/Button"

Rectangle {
    id: root

    property variant window: globalModel.window

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
        property int total: 0
        onPressed: clickPos = Qt.point(mouse.x, mouse.y)
        onPositionChanged: {
            if (total++ != 2)
                return;
            total = 0;
            var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
            window.setX(window.x + delta.x)
            window.setY(window.y + delta.y)
        }
    }

    Row {
        anchors {right: parent.right; rightMargin: 10; verticalCenter: parent.verticalCenter }
        spacing: 15

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/dropDownList.png"
            onClicked: dropDownList()
        }

        ImageButton {
            width: root.height; height: width
            scaleHeight: 0.2
            source: "qrc:/image/mainWin/minimize.png"
            onClicked: minimize()
        }

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/maximize.png"
            onClicked: maximize()
        }

        ImageButton {
            width: root.height; height: width
            source: "qrc:/image/mainWin/close.png"
            onClicked: close()
        }
    }

    onDropDownList: {}
    onMinimize: window.showMinimized()
    onMaximize: window.visibility === Window.FullScreen ?
                window.showNormal() :
                window.showFullScreen()
    onClose: window.close()
}
