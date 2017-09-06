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
    //    color: "lightblue"

    Row {
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
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
