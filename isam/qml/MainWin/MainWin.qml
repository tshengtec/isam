import QtQuick 2.5
import QtQuick.Window 2.2
import MyModels 1.0
import "./content/MenuBar"
import "./content/CommodityInfoListView"
import "./content/CommodityInfoOperation"
import "./content/BottomBar"
import "../SelectedCommodityWin"
import "../SettleMentWin"
import "../SalesQueryWin"

Window {
    id: windowsId
    visible: true
    width: 1280/1.5
    height: 768/1.5
//    width: 1280
//    height: 768
    title: qsTr("")

    Item {
        width: parent.width; height: parent.height
        MouseArea {
            anchors.fill: parent
            propagateComposedEvents: true
            onClicked: {
                focus = true
            }
        }
    }

    Column {
        MenuBar {
            width: windowsId.width; height: 2.5*windowsId.height/20
        }

        CommodityInfoListView {
            width: windowsId.width; height: 12.5*windowsId.height/20
            model: salesCommodityListModel
            onDelCommodity: salesCommodityEditModel.remove(salesCommodityListModel.at(index).id)
        }

        CommodityInfoOperation {
            width: windowsId.width; height: 1*windowsId.height/20
            onRemoveAll: salesCommodityEditModel.removeAll()
        }

        BottomBar {
            width: windowsId.width; height: 4*windowsId.height/20
            onSearched: selectedCommodityWin.visible = true
            onSettleMented: salesCommodityEditModel.settleMent()
        }
    }

    //data
    SalesCommodityEditModel {
        id: salesCommodityEditModel
    }

    SalesCommodityListModel {
        id: salesCommodityListModel
    }

    CommodityQueryListModel {
        id: commodityQueryListModel
        commodityType: "all"
    }

    SalesQueryListModel {
        id: salesQueryListModel
    }

    //win-----------------------------

    SelectedCommodityWin {
        id: selectedCommodityWin
        displayListModel: commodityQueryListModel
        visible: false
    }

    SettleMentWin {
        id: settleMentWin
        visible: false
    }

    SalesQueryWin {
        id: salesQueryWin

    }
}
