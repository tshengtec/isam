import QtQuick 2.0
import MyModels 1.0
import "./content"
import "../../../Common/Button"

Rectangle {
    signal salesSearch()
    signal commoditySearch();
    signal salesShift()
    id: rootId
    width: parent.width; height: parent.height
    color: "#38394e"

    Row {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 0.04*parent.width
        spacing: 20

        Item { width: 30; height: 1 }

        IconButton {
            width: 0.70*rootId.width/15; height: rootId.height/1.3
            title: "商品查询"
            icon: "qrc:/image/mainWin/commodityQuery.png"
            onClicked: commoditySearch()
        }

        IconButton {
            width: 0.70*rootId.width/15; height: rootId.height/1.3
            title: "销售查询"
            icon: "qrc:/image/mainWin/salesQuery.png"
            onClicked: salesSearch()
        }

        IconButton {
            width: 0.70*rootId.width/15; height: rootId.height/1.3
            title: "挂单"
            icon: "qrc:/image/mainWin/selfPending.png"
            onClicked: salesCommodityEditModel.onPendingOperation()
        }

        IconButton {
            width: 0.70*rootId.width/15; height: rootId.height/1.3
            title: "取单"
            icon: "qrc:/image/mainWin/selfGetting.png"
            onClicked: salesCommodityEditModel.onGettingOperation()
            noteStatus: salesCommodityEditModel.isPendingStatus

        }

        IconButton {
            width: 0.70*rootId.width/15; height: rootId.height/1.3
            title: "交班"
            icon: "qrc:/image/mainWin/salesShift.png"
            onClicked: salesShift()
        }
    }



    AccountInfoDisplay {
        anchors.left: parent.left
        y: -(1.5*rootId.height - rootId.height)/2
//        anchors.verticalCenter: parent.verticalCenter
        width: 6*parent.width/20; height: 1*rootId.height
    }

    ErrorTips {
        width: 4*parent.width/20; height: 9*parent.height/20
    }
}
