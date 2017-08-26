import QtQuick 2.5
import QtQuick.Window 2.2
import MyModels 1.0
import "./content/MenuBar"
import "./content/CommodityInfoListView"
import "./content/CommodityInfoOperation"
import "./content/BottomBar"

Window {
    id: windowsId
    visible: true
    width: 1280
    height: 768
    title: qsTr("")

    Column {
        MenuBar {
            width: windowsId.width; height: 2.5*windowsId.height/20
        }

        CommodityInfoListView {
            width: windowsId.width; height: 12.5*windowsId.height/20
        }

        CommodityInfoOperation {
            width: windowsId.width; height: 1*windowsId.height/20
        }

        BottomBar {
            width: windowsId.width; height: 4*windowsId.height/20
        }
    }

    //data
    SalesCommodityEditModel {
        id: salesCommodityEditModel
    }

    SalesCommodityListModel {
        id: salesCommodityListModel
    }

    SalesQueryListModel {
        id: salesQueryListModel
    }
}
