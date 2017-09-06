import QtQuick 2.0
import MyModels 1.0
import "../Common/TipsWin"
import "../Common/Button"
import "./content"

Rectangle {
    id: windowsId
    width: parent.width; height: parent.height
    visible: !accountModel.isGeneralLogged

    Image { width: parent.width; height: 0.5*parent.height; source: "qrc:/image/loginWin/background.png" }

    AdminLoginWin {
        id: adminLoginWin
        z: 1.5
        width: parent.width; height: parent.height
        adminAccountModel: accountModel
        visible: !accountModel.isAdminLogged
    }

    GeneralLoginWin {
        id: generalLoginWin
        generalAccountModel: accountModel
        visible: !accountModel.isGeneralLogged
        onLogout: yesORNoTipsWin.show()
    }

    YesOrNoTipsWin {
        id: yesORNoTipsWin
        width: parent.width; height: parent.height
        onSure: accountModel.logoutAdminAccount()
    }

    AccountListModel {
        id: accountModel
    }
}
