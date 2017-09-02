import QtQuick 2.0
import MyModels 1.0
import "./content"
import "../../../Common/Button"

Rectangle {
    signal salseSearch()
    signal commoditySearch();
    id: rootId
    width: parent.width; height: parent.height
    color: "#337cc9"//themesModel.backgroundColor

    Row {
        anchors.fill: parent
        spacing: 20

        Item { width: 30; height: 1 }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: 2*rootId.width/15; height: rootId.height/1.2
            btnText: "销售查询"
            onIsClicked: {
                salseSearch()
            }
        }
        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: 2*rootId.width/15; height: rootId.height/1.2
            btnText: "商品查询"
            onIsClicked: {
                commoditySearch()
            }
        }
        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "挂单"
            onIsClicked: {
                salesCommodityEditModel.onPendingOperation()
            }
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "取单"
            onIsClicked: salesCommodityEditModel.onGettingOperation()
            statusModel: salesCommodityEditModel.isPendingStatus
        }

        MenuButton {
            anchors.verticalCenter: parent.verticalCenter
            width: rootId.width/15; height: rootId.height/1.2
            btnText: "交班"
        }
    }



    Rectangle {
        anchors.right: parent.right
        width: 2*parent.width/20; height: rootId.height/1.2
        color: "lightblue"

        ListView {
            anchors.right: parent.right
            width: 100
            delegate:
                Text {
                    id: textId
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: "white"
                    text: "ddd"
                    font.pixelSize: parent.height/2.5
                }
        }

    }

    ErrorTips {
        width: 4*parent.width/20; height: 9*parent.height/20
    }

    //-----------------data
    AccountListModel {
        id: accountListModel
    }
}
