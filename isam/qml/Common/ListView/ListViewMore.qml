import QtQuick 2.5
import "./content"

Rectangle {
    property variant spacingWidth: [1*width/20, 3*width/20, 4*width/20, 1*width/20, 1.5*width/20,
                                    1.5*width/20, 2*width/20, 1.5*width/20, 4.5*width/20]
    property variant headerContentList: ["序号", "条形码", "商品名称", "数量", "单价(元)", "折扣(%)", "折后单价(元)", "小计", "备注"]
    property variant modelStrList: ["", "id", "name"] //obj.name =>str obj.name <=> obj["name"]
    property variant modelList: []
    property int displayLine: 5
    width: parent.width; height: parent.height
    color: "#00000000"

    //backGround
    ListView {
        id: listViewBackGroundId
        width: parent.width; height: parent.height
        model: displayLine
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: HeaderDelegate {
            z: 1.5
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/displayLine
            headerModel: headerContentList
            headerSpacingWidth: spacingWidth
        }

        delegate: ListViewBackGroupDelegate {
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/displayLine
            contentSpacingWidth: spacingWidth
        }
    }

    ListView {
        id: listViewId
        z: listViewBackGroundId*2
        width: parent.width; height: parent.height
        model: modelList
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: Item {
            clip: true
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/displayLine
        }
        delegate: ListViewDelegate {
            width: listViewId.width; height: listViewId.height/displayLine
            contentSpacingWidth: spacingWidth
            contentStrList: modelStrList
        }
    }

    Rectangle {
        width: parent.width; height: parent.height
        border.color: "#cccccc"
        border.width: 1
        color: "#00000000"
    }
}
