import QtQuick 2.0
import MyModels 1.0
import "./content/SalesInfoView"
import "./content/SalesDataView"
import "./content/BottomBar"
import "../Common/Button"
import "../Common/Text"
import "../ProjectCommon/Bar"
import "../MainWin/content/TopBar"
import "../Common/Window"

MyWindow {
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

            Item { width: 1; height: 0.01*parent.height }

            SalesInfoView {
                width: parent.width; height: 0.2*parent.height
                totalAmountMoney: salesDocumentsListModel.sales
                totalNumber: salesDocumentsListModel.salesNumber
            }

            Item { width: 1; height: 0.05*parent.height }

            SalesDataView {
                width: parent.width; height: 0.5*parent.height
                moneyPay: salesDocumentsListModel.sales
            }

            Item { width: 1; height: 0.05*parent.height }

            BottomBar {
                width: parent.width; height: 0.05*parent.height

            }
        }
    }

    onVisibleChanged: {
        if (visible) {
            loginAndLogoutDateTimeId.text = "本次登录时段: " + getLoginDateTime() + "~" + getLogoutDateTime()
            salesDocumentsListModel.reload()
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
