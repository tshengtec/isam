import QtQuick 2.0
import MyModels 1.0
import "../Common/Button"
import "./content"

Rectangle {
    id: windowsId
    width: parent.width; height: parent.height
    visible: !accountModel.isGeneralLogged

    Image { source: "qrc:/image/loginWin/background.png" }

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
    }

    AccountListModel {
        id: accountModel
    }
}
