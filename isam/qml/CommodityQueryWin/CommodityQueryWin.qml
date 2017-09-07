import QtQuick 2.0
import MyModels 1.0
import "./content"
import "./content/LeftPart"
import "./content/RightPart"
import "../MainWin/content/TopBar"

Rectangle {

    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopBar {
            width: parent.width; height: 1*parent.height/20
        }

        TopTitleBar {
            id: topTitleBar
            width: parent.width; height: 2*parent.height/20
            onBacked: rootId.visible = false
            onSearched: commodityQueryListModel.searchText = searchText
        }

        Row {
            width: parent.width; height: 17*parent.height/20

            LeftPart {
                width: 5*parent.width/20; height: parent.height
                allCommodityClassModel: commodityQueryListModel.commodityTypeList
                onSelectedCommodityType: {
                    topTitleBar.searchTextInputIdText = ""
                    commodityQueryListModel.searchText = ""
                    commodityQueryListModel.commodityType = type
                }
            }

            RightPart {
                width: 15*parent.width/20; height: parent.height
                commodityListModel: commodityQueryListModel
            }
        }

    }

    onVisibleChanged: {
        if (visible) {
            commodityQueryListModel.reload()
        }
    }

    CommodityQueryListModel {
        id: commodityQueryListModel
        commodityType: "all"
        searchText: ""
        isNotStrSearchAll: true
    }
}
