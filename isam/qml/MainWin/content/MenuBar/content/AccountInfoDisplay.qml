import QtQuick 2.0
import MyModels 1.0

Item {
    width: parent.width; height: parent.height

    ListView {
        id: listViewAccountInfoId
        anchors.fill: parent
        model: accountListModel
        interactive: false
        delegate:
        Text {
            width: listViewAccountInfoId.width; height: listViewAccountInfoId.height/2
            elide: Text.ElideMiddle
            color: "white"
            text: (index === 0 ? "管理员帐号: " : "员工　帐号: ") +
                  (modelData !== undefined ? modelData.name : "")
            font.pixelSize: 0.8*height
        }
    }

    //-----------------data
    AccountListModel {
        id: accountListModel
    }
}
