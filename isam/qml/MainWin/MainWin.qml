import QtQuick 2.5
import QtQuick.Window 2.2
import "./content/MenuBar"
import "./content/CommodityInfoListView"
import "./content/CommodityInfoOperation"

Window {
    id: windowsId
    visible: true
    width: 1024
    height: 600
    title: qsTr("")

//    Column {
//        MenuBar {
//            width: windowsId.width; height: 2*windowsId.height/20
//        }

//        CommodityInfoListView {
//            width: windowsId.width; height: 13*windowsId.height/20
//        }

//        CommodityInfoOperation {
//            width: windowsId.width; height: 1*windowsId.height/20
//        }
//    }
}
