import QtQuick 2.0
import MyModels 1.0
import "./content"
import "../Common/Button"
import "../Common/Text"
import "../ProjectCommon/Bar"
import "../MainWin/content/TopBar"

Rectangle {
    property variant allSalseListModelToLeftPart: []
    property variant commoditySalseListModelToRightPart: [] //
    id: rootId
    width: parent.width; height: parent.height
    color: "#eeeeee"

    Column {
        anchors.fill: parent

        TopBar {
            width: parent.width; height: 1*parent.height/20
        }

        TopTitleBar {
            title: "交班"
            width: parent.width; height: 2*parent.height/20
            onBacked: {
                rootId.visible = false
            }
        }

        Item { width: parent.width; height: 0.03*parent.height }

        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 0.85*parent.width; height: 0.85*parent.height

            MText {
                id: loginAndLogoutDateTimeId
                width: parent.width; color: "#337cc9"; font.pixelSize: 0.03*parent.height
                text: "本次登录时段: " + getLoginDateTime() + "~" + getLogoutDateTime()
            }

            SalesInfoView {
                width: parent.width; height: 0.3*parent.height
            }
        }

//        Item {
//            id: bottomItemId
//            width: parent.width; height: 15*parent.height/20

//            Column {
//                anchors.centerIn: parent

//                MText {
//                    id: cashiersInfoId
//                    text: "收银员: " + getCashiersInfo()
//                    color: "#337cc9"
//                    font.pixelSize: bottomItemId.height/20
//                }
//                MText {
//                    id: loginAndLogoutDateTimeId
//                    text: "本次登录时段: " + getLoginDateTime() + "~" + getLogoutDateTime()
//                    color: "#337cc9"
//                    font.pixelSize: bottomItemId.height/20
//                }
//                MText {
//                    text: "销售额: " + salesDocumentsListModel.sales
//                    color: "#337cc9"
//                    font.pixelSize: bottomItemId.height/20
//                }
//                MText {
//                    text: "销售笔数: " + salesDocumentsListModel.salesNumber
//                    color: "#337cc9"
//                    font.pixelSize: bottomItemId.height/20
//                }
//            }
//        }

//        Item {
//            width: parent.width; height: 2*parent.height/20
//            MenuButton {
//                anchors.right: parent.right
//                anchors.rightMargin: 30
//                anchors.verticalCenter: parent.verticalCenter
//                width: parent.width/10; height: parent.height/1.2
//                btnText: "交班退出"
//                onIsClicked: Qt.quit()
//            }
//        }
    }

    onVisibleChanged: {
        if (visible) {
        }
    }

    AccountListModel {
        id: accountListModel
    }

    SalesDocumentsListModel {
        id: salesDocumentsListModel
    }

    function getCashiersInfo() {
        for (var i = 0; i < accountListModel.size(); i++) {
            if (accountListModel.at(i).type === "general")
                return accountListModel.at(i).name
        }
        return ""
    }

    function getLoginDateTime() {
        for (var i = 0; i < accountListModel.size(); i++) {
            if (accountListModel.at(i).type === "general")
                return Qt.formatDateTime(accountListModel.at(i).loginDateTime, "yyyy-MM-dd hh:mm:ss")
        }
        return ""
    }

    function getLogoutDateTime() {
        var date = new Date()
        return Qt.formatDateTime(date, "yyyy-MM-dd hh:mm:ss")
    }
}
