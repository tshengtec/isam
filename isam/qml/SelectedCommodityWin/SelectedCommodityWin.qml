import QtQuick 2.0
import "./content"
import "../Common/ListView"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: "#60000000"

    MouseArea { anchors.fill: parent }

    Rectangle {
        id: backGroundId
        anchors.centerIn: parent
        width: parent.width/1.5; height: parent.height/1.6
        color: "#eeeeee"

        Column {
            anchors.fill: parent
            TitleBar {
                width: parent.width; height: 2.5*parent.height/20
                onExited: rootId.visible = false
            }

            ListViewMore {
                width: parent.width; height: 14*parent.height/20
                spacingWidth: [50, 150, 150]
                headerContentList: ["序号", "条形码", "商品名称"]
                modelList: salesQueryListModel
            }
        }
    }
}
