import QtQuick 2.0
import "../../../Common/ListView"

Rectangle {
    property variant commoditySalseListModel: []
    width: parent.width; height: parent.height
    color: "white"

    ListViewMore {
        width: parent.width; height: parent.height - 10
        modelList: commoditySalseListModel
        spacingWidth: [1*width/20, 3.5*width/20, 4*width/20, 1.5*width/20, 2*width/20,
                                        2*width/20, 2.5*width/20, 1.5*width/20, 2*width/20]
        headerContentList: ["序号", "条形码", "商品名称", "数量", "单价(元)", "折扣(%)", "折后单价(元)", "小计", "备注"]
        modelStrList: ["", "id", "name"] //obj.name =>str obj.name <=> obj["name"]
        displayLine: 13
    }
}
