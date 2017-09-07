import QtQuick 2.0
import MyModels 1.0

Rectangle {
    id: accountInfoDisplay
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        height: parent.height
        spacing: 20

        Item { width: 1; height: 1 }

        Image {
            anchors.verticalCenter: parent.verticalCenter
            width: height; height: 0.8*accountInfoDisplay.height
            source: "qrc:/image/ico/logo.png"
        }

        Rectangle { anchors.verticalCenter: parent.verticalCenter; width: 1.5; height: 0.6*accountInfoDisplay.height; color: "#6d6e80" }

        ListView {
            id: listViewAccountInfoId
            width: 0.6*accountInfoDisplay.width; height: accountInfoDisplay.height
            model: accountListModel
            interactive: false
            delegate:
            Item {
                width: listViewAccountInfoId.width; height: listViewAccountInfoId.height/2

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    width: listViewAccountInfoId.width;
                    elide: Text.ElideMiddle
                    color: "white"
                    text: (index === 0 ? "管理员帐号:  " : "员工　帐号:  ") +
                          (modelData !== undefined ? modelData.name : "")
                    font.pixelSize: 0.3*parent.height
                }
            }
        }

    }

    //-----------------data
    AccountListModel {
        id: accountListModel
    }
}
