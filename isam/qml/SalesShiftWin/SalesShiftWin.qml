import QtQuick 2.0
import "../ProjectCommon/Bar"

Rectangle {
    property variant allSalseListModelToLeftPart: []
    property variant commoditySalseListModelToRightPart: [] //
    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopTitleBar {
            title: "交班"
            width: parent.width; height: 2*parent.height/20
            onBacked: rootId.visible = false
        }

        Row {
            width: parent.width; height: 18*parent.height/20
        }

    }

    onVisibleChanged: {
        if (visible) {
            allSalseListModelToLeftPart.reload()
        }
    }
}
