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
import "../LoginWin"

Window {
    id: windowsId
    visible: true
    width: 0.8*Screen.desktopAvailableWidth
    height: 0.8*Screen.desktopAvailableHeight
    minimumWidth: 0.5*Screen.desktopAvailableWidth
    minimumHeight: 0.5*Screen.desktopAvailableHeight
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
            onSalseSearch: salesQueryWin.visible = true
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
            onSearched: {
                commodityQueryListModel.searchText = barCodeText
                selectedCommodityWin.visible = true
            }
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

    SalesDocumentsListModel {
        id: salesDocumentsListModel
    }

    //win-----------------------------

    SelectedCommodityWin {
        id: selectedCommodityWin
        displayListModel: commodityQueryListModel
//        visible: false
    }

    SettleMentWin {
        id: settleMentWin
        visible: false
    }

    SalesQueryWin {
        id: salesQueryWin
        visible: false
        allSalseListModelToLeftPart: salesDocumentsListModel
        commoditySalseListModelToRightPart: salesQueryListModel
    }

    LoginWin {
        id: loginWin
        visible: false
    }

}
