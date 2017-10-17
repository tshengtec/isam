import QtQuick 2.5
import MyModels 1.0
import "../../../Common/ListView"
import "../../../Common/Button"

Item {
    id: rootItemId
    signal delCommodity(int index)
    property variant model: []
    width: parent.width; height: parent.height

    ListViewMore {
        id: listViewMoreId
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width; height: parent.height
        spacingWidth: [1*width/20,   3*width/20,   4*width/20, 1.5*width/20, 1*width/20,
                       1.5*width/20, 1.5*width/20, 2*width/20, 1.5*width/20, 1.5*width/20,
                       1.5*width/20]
        headerContentList: ["序号",     "条形码",  "商品名称",    "单位",  "数量",
                            "单价(元)", "折扣(%)", "折后单价(元)", "小计",  "备注",
                            "删除"]
        displayLine: 10
        modelStrList: ["",            "barCode",  "goodsName",       "unitName", "quantity",
                       "sellingPrice", "discount", "discountedPrice", "subtotal"]
        modelList: model
    }

    Column {
        anchors.fill: parent

        Item { width: 1; height: parent.height/(listViewMoreId.displayLine+1) }

        ListView {
            anchors.horizontalCenter: parent.horizontalCenter
            id: listViewBackGroundId
            width: parent.width; height: listViewMoreId.displayLine*parent.height/(listViewMoreId.displayLine+1)
            model: rootItemId.model
            clip: true
            interactive: false
            headerPositioning: ListView.OverlayHeader
            delegate:
            Item {
                x: xCount()
                width: listViewMoreId.spacingWidth[listViewMoreId.spacingWidth.length-1];
                height: listViewBackGroundId.height/listViewMoreId.displayLine

                MenuButton {
                    anchors.centerIn: parent
                    width: parent.width/1.5; height: parent.height/1.5
                    btnText: "删除"
                    onIsClicked: delCommodity(index) //note
                }
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
