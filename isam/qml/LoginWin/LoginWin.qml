import QtQuick 2.0
import MyModels 1.0
import "../Common/Button"
import "./content"

Rectangle {
    id: windowsId
    width: parent.width; height: parent.height

    gradient: Gradient {
        GradientStop { position: 0.0; color: "lightsteelblue" }
        GradientStop { position: 1.0; color: "blue" }
    }

    AdminLoginWin {
        id: adminLoginWin
        width: parent.width; height: parent.height
        adminAccountModel: accountModel
    }

    GeneralLoginWin {
        id: generalLoginWin
        visible: generalLoginWin.isLoginSuccess
    }

    AccountModel {
        id: accountModel
    }
}
