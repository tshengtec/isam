import QtQuick 2.0
import MyModels 1.0
import "../ProjectCommon/Bar"

Rectangle {
    property variant allSalseListModelToLeftPart: []
    property variant commoditySalseListModelToRightPart: [] //
    id: rootId
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        TopTitleBar {
            title: "交班"
            width: parent.width; height: 2*parent.height/20
            onBacked: {
                rootId.visible = false
            }
        }

        Item {
            id: bottomItemId
            width: parent.width; height: 18*parent.height/20

            Column {
                anchors.centerIn: parent

                Text {
                    text: "收银员: 1001"
                    color: "#337cc9"
                    font.pixelSize: bottomItemId.height/20
                }
                Text {
                    text: "本次登录时段: 22222"
                    color: "#337cc9"
                    font.pixelSize: bottomItemId.height/20
                }
                Text {
                    text: "销售额: " + salesDocumentsListModel.sales
                    color: "#337cc9"
                    font.pixelSize: bottomItemId.height/20
                }
                Text {
                    text: "销售笔数: " + salesDocumentsListModel.salesNumber
                    color: "#337cc9"
                    font.pixelSize: bottomItemId.height/20
                }
            }
        }
    }

    onVisibleChanged: {
        if (visible) {
            salesDocumentsListModel.reload()
        }
    }

    AccountListModel {
        id: accountListModel
    }

    SalesDocumentsListModel {
        id: salesDocumentsListModel
    }
}
