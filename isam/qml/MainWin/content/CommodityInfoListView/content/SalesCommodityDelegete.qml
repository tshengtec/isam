import QtQuick 2.0
import "../../../../Common/Text"

Item {
    property variant indexValue: index
    id: delegeRectId
    width: parent.width; height: parent.height

    Row {
        Repeater {
            model: listViewBackGroundId.count
            Item {
                width: spacingWidth[index]; height: delegeRectId.height
                clip: true
                MText {
                    text: String(getCommodityInfo(index))
                    color: "black"
                    anchors.centerIn: parent
                    font.pixelSize: parent.height/2.5
                }
                Rectangle {
                    anchors.right: parent.right
                    width: 1; height: parent.height
                    color: "#d7d7d7"
                }
            }
        }
    }

    function getCommodityInfo(index) {
        if (modelData === undefined)
            return ""
        switch(index) {
        case 0: return indexValue
        case 1: return modelData.id
        case 2: return modelData.name
        default: return ""
        }
    }

}
