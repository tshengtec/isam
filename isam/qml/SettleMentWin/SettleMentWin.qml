import QtQuick 2.0
import MyModels 1.0
import "../ProjectCommon/Bar"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopTitleBar {
            width: parent.width; height: 2*parent.height/20
            title: "结算"
            onBacked: rootId.visible = false
        }


    }
}
