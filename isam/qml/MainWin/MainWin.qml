import QtQuick 2.5
import QtQuick.Window 2.2
import MyModels 1.0
import "./content/TopBar"
import "./content/MenuBar"
import "./content/CommodityInfoListView"
import "./content/CommodityInfoOperation"
import "./content/BottomBar"
import "../SelectedCommodityWin"
import "../SettleMentWin"
import "../SalesQueryWin"
import "../LoginWin"
import "../CommodityQueryWin"
import "../SalesShiftWin"

Window {
    id: window
    x: (Screen.width - width)/2
    y: (Screen.height - height)/2
    visible: true
    width: 0.7*Screen.width
    height: 0.8*Screen.height
    minimumWidth: 0.5*Screen.width
    minimumHeight: 0.5*Screen.height
    flags: Qt.Window | Qt.FramelessWindowHint
    Component.onCompleted: globalModel.window = window
    onClosing: {
        if (!loginWin.visible) {
            close.accepted = false
            salesShiftWin.visible = true
        }
    }

    MouseArea {
        anchors.fill: parent
        propagateComposedEvents: true
        onClicked: {
            focus = true
        }
    }

    Column {
        TopBar {
            width: window.width; height: 1*window.height/20
        }

        MenuBar {
            width: window.width; height: 2*window.height/20
            onSalesSearch: salesQueryWin.visible = true
            onCommoditySearch: commodityQueryWin.visible = true
            onSalesShift: salesShiftWin.visible = true
        }

        CommodityInfoListView {
            width: window.width; height: 12*window.height/20
            model: salesCommodityListModel
            onDelCommodity: salesCommodityEditModel.remove(salesCommodityListModel.at(index).id)
        }

        CommodityInfoOperation {
            width: window.width; height: 1*window.height/20
            onRemoveAll: salesCommodityEditModel.removeAll()
        }

        BottomBar {
            width: window.width; height: 4*window.height/20
            amountMoney: salesCommodityListModel.amountMoney
            onSearched: {
                commodityQueryListModel.searchText = barCodeText
                selectedCommodityWin.visible = true
            }
            onSettleMented: settleMentWin.show() //salesCommodityEditModel.settleMent()
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

    //win-----------------------------

    LoginWin {
        id: loginWin
        onClose: window.close()
//        visible: false
    }

    SelectedCommodityWin {
        id: selectedCommodityWin
        displayListModel: commodityQueryListModel
        visible: false
    }

    SalesQueryWin {
        id: salesQueryWin
        visible: false
    }

    CommodityQueryWin {
        id: commodityQueryWin
        visible: false
    }

    SettleMentWin {
        id: settleMentWin
        visible: false
        paymentModel: salesCommodityEditModel
    }

    SalesShiftWin {
        id: salesShiftWin
        visible: false
    }

}
