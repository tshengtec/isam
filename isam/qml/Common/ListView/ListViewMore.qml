import QtQuick 2.5
import "./content"

Rectangle {
    property variant spacingWidth: [1*width/20,   3*width/20,   4*width/20,   1.5*width/20, 1*width/20,
                                    1.5*width/20, 1.5*width/20, 2*width/20,   1.5*width/20, 3*width/20]
    property variant headerContentList: ["序号",     "条形码",  "商品名称",    "单位",  "数量",
                                         "单价(元)", "折扣(%)", "折后单价(元)", "小计",  "备注"]
    /*obj.name =>str obj.name <=> obj["name"]*/
    property variant modelStrList: ["",            "barCode",  "name",            "unitName", "count",
                                    "retailprice", "discount", "discountedPrice", "subtotal"]
    property variant modelList: []
    property int displayLine: 5
    width: parent.width; height: parent.height
    color: "#00000000"

//    backGround
    Column {
        anchors.fill: parent
        HeaderDelegate {
            z: 1.5
            width: parent.width; height: parent.height/(displayLine+1)
            headerModel: headerContentList
            headerSpacingWidth: spacingWidth
        }

        ListView {
            id: listViewBackGroundId
            width: parent.width; height: displayLine*parent.height/(displayLine+1)
            model: displayLine
            clip: true
            interactive: false
            headerPositioning: ListView.OverlayHeader
            delegate: ListViewBackGroupDelegate {
                width: listViewBackGroundId.width; height: listViewBackGroundId.height/displayLine
                contentSpacingWidth: spacingWidth
            }
        }
    }

    Column {
        anchors.fill: parent
        Item {
            clip: true
            width: parent.width; height: parent.height/(displayLine+1)
        }

        ListView {
            id: listViewId
            z: listViewBackGroundId*2
            width: parent.width; height: displayLine*parent.height/(displayLine+1)
            model: modelList
            clip: true
            interactive: false
            headerPositioning: ListView.OverlayHeader
            delegate: ListViewDelegate {
                width: listViewId.width; height: listViewId.height/displayLine
                contentSpacingWidth: spacingWidth
                contentStrList: modelStrList
            }
        }
    }

    Rectangle {
        width: parent.width; height: parent.height
        border.color: "#cccccc"
        border.width: 1
        color: "#00000000"
    }
}
