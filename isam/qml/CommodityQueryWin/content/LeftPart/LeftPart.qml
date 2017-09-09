import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: rootRectId
    signal selectedCommodityType(string type)
    property variant allCommodityClassModel: []
    width: parent.width; height: parent.height
    color: "#d5d5d5"

    Column {
        anchors.fill: parent

        BaseButton {
            width: parent.width; height: 1.5*parent.height/20
            btnText: "选择分类"
            color: "#5acaa4"
        }

        AllClassListView {
            width: parent.width; height: 18.5*parent.height/20
            allCommodityTypeModel: allCommodityClassModel
            onSelectedCommodityType: rootRectId.selectedCommodityType(type)
        }
    }

}
