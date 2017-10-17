import QtQuick 2.0
import "../../../Common/ListView"

Rectangle {
    property variant commodityListModel: []
    width: parent.width; height: parent.height
    color: "white"

    ListViewMore {
        width: parent.width; height: parent.height - 10
        modelList: commodityListModel
        spacingWidth: [1*width/20, 3.5*width/20, 6*width/20, 1.5*width/20, 2*width/20,
                       2*width/20, 2.5*width/20, 1.5*width/20]
        headerContentList: ["序号",        "条形码",  "商品名称",    "单位",  "数量",
                            "零售价(元)", "是否打折", "是否积分"]
        modelStrList: ["",            "barCode", "goodsName", "unitName", "stock",
                       "sellingPrice", "discount", ""] //obj.name =>str obj.name <=> obj["name"]
        displayLine: 13
    }
}
