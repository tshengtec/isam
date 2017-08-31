import QtQuick 2.0
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

    Item {
        anchors.right: parent.right
        width: textId.text.length*height/2.5; height: rootId.height/1.2

        Text {
            id: textId
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: "white"
            text: "xxx公司"
            font.pixelSize: parent.height/2.5
        }
    }

    BaseButton {
        id: tipsLabelId
        visible: salesCommodityEditModel.errorStr !== ""
        anchors.centerIn: parent
        width: 4*parent.width/20; height: 9*parent.height/20
        radius: 5
        color: "#ff8400"
        btnText: salesCommodityEditModel.errorStr
    }

    Timer {
        interval: 2000; running: salesCommodityEditModel.errorStr !== ""; repeat: true
        onTriggered: {
            salesCommodityEditModel.errorStr = ""
            stop()
        }
    }
}
