import QtQuick 2.0

Item {
    property variant indexValue: index
    property variant contentSpacingWidth: []
    property variant contentStrList: []
    id: delegeRectId
    width: parent.width; height: parent.height

    Row {
        Repeater {
            model: contentSpacingWidth.length
            Item {
                width: contentSpacingWidth[index]; height: delegeRectId.height
                clip: true
                Text {
                    text: String(getCommodityInfo(index))
                    color: "black"
                    anchors.centerIn: parent
                    font.pixelSize: parent.height/3
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
        if (index === 0)
            return indexValue + 1;

        return String(modelData[contentStrList[index]] !== undefined ?
               modelData[contentStrList[index]] : "")
    }

}
