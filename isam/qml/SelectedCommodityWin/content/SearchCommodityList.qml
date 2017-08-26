import QtQuick 2.5
import "../../Common/ListView"
import "../../Common/Button"

Item {
    signal addCommodity(int index)
    property variant model: []
    width: parent.width; height: parent.height

    ListViewMore {
        id: listViewMoreId
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 10; height: parent.height
        spacingWidth: [1.5*width/20, 4*width/20, 5*width/20, 1.5*width/20, 3*width/20, 3*width/20, 2*width/20]
        headerContentList: ["序号", "条形码", "商品名称", "单位", "库存数量", "零售价(元)", ""]
        displayLine: 5
        modelList: model
    }

    ListView {
        anchors.horizontalCenter: parent.horizontalCenter
        id: listViewBackGroundId
        width: parent.width - 10; height: parent.height
        model: listViewMoreId.displayLine
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        delegate:

        Item {
            visible: index !== 0
            x: xCount()
            width: listViewMoreId.spacingWidth[listViewMoreId.spacingWidth.length-1];
            height: listViewBackGroundId.height/listViewMoreId.displayLine

            MenuButton {
                anchors.centerIn: parent
                width: parent.width/1.5; height: parent.height/1.5
                btnText: "增加"
                onIsClicked: addCommodity(index)
            }
        }
    }

    function xCount() {
        var xValue = 0
        for (var i = 0; i < listViewMoreId.spacingWidth.length - 1; i++) {
            xValue += listViewMoreId.spacingWidth[i];
        }
        return xValue;
    }
}

