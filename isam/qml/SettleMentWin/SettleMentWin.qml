import QtQuick 2.0
import MyModels 1.0
import "../ProjectCommon/Bar"
import "../ProjectCommon/Text"
import "../MainWin/content/TopBar"
import "./content"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: "#eeeeee"

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

        PayMentItem {
            width: parent.width; height: 17*parent.height/20
        }
    }
}
