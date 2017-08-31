import QtQuick 2.0
import MyModels 1.0
import "../Common/Button"
import "./content"

Rectangle {
    id: windowsId
    width: parent.width; height: parent.height
    visible: !accountModel.isGeneralLogged

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightsteelblue" }
        GradientStop { position: 1.0; color: "blue" }
    }

    AdminLoginWin {
        id: adminLoginWin
        z: 1.5
        width: parent.width; height: parent.height
        adminAccountModel: accountModel
        visible: !accountModel.isAdminLogged
    }

    GeneralLoginWin {
        id: generalLoginWinS
        generalAccountModel: accountModel
        visible: !accountModel.isGeneralLogged
    }

    AccountModel {
        id: accountModel
    }
}
