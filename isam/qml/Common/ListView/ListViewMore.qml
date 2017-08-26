import QtQuick 2.0
import "./content"

Rectangle {
    property variant spacingWidth: [1*width/20, 3*width/20, 4*width/20, 1*width/20, 1.5*width/20,
                                    1.5*width/20, 2*width/20, 1.5*width/20, 4.5*width/20]
    property variant headerContentList: ["序号", "条形码", "商品名称", "数量", "单价(元)", "折扣(%)", "折后单价(元)", "小计", "备注"]
    property variant contentList: []
    width: parent.width; height: parent.height
    color: "lightblue"



    //backGround
    ListView {
        id: listViewBackGroundId
        width: parent.width; height: parent.height
        model: spacingWidth.length
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: HeaderDelegate {
            z: 1.5
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
            headerModel: headerContentList
            headerSpacingWidth: spacingWidth
        }

        delegate: ListViewBackGroupDelegate {
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
            contentSpacingWidth: spacingWidth
        }
    }

    ListView {
        id: listViewId
        z: listViewBackGroundId*2
        width: parent.width; height: parent.height
        model: contentList
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: Item {
            clip: true
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
        }
        delegate: ListViewDelegate {
            width: listViewId.width; height: listViewId.height/11
        }
    }
}
