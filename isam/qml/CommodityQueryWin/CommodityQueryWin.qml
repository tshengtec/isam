import QtQuick 2.0
import "./content"
import "./content/LeftPart"
import "./content/RightPart"

Rectangle {
    property variant commodityQueryModel: []

    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopTitleBar {
            width: parent.width; height: 2*parent.height/20
            onBacked: rootId.visible = false
        }

        Row {
            width: parent.width; height: 18*parent.height/20

            LeftPart {
                width: 5*parent.width/20; height: parent.height
//                allCommodityClassModel: allSalseListModelToLeftPart
            }

            RightPart {
                width: 15*parent.width/20; height: parent.height
//                commoditySalseListModel: commoditySalseListModelToRightPart
            }
        }

    }

    onVisibleChanged: {
        if (visible) {
            commodityQueryModel.reload()
        }
    }
}
