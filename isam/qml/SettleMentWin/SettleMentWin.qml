import QtQuick 2.0
import MyModels 1.0
import "../ProjectCommon/Bar"
import "../MainWin/content/TopBar"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopBar {
            width: parent.width; height: 1*parent.height/20
        }


        TopTitleBar {
            width: parent.width; height: 2*parent.height/20
            title: "结算"
            onBacked: rootId.visible = false
        }


    }
}
