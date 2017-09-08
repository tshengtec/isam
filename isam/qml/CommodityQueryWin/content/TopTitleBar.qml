import QtQuick 2.0
import "../../Common/Button"
import "../../Common/Text"
import "../../ProjectCommon/Bar"

TopTitleBar {
    signal searched(string searchText)
    property alias searchTextInputIdText: searchTextInputId.text
    width: parent.width; height: parent.height
    color: "#38394e"
    title: "商品查询"

    Rectangle {
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        width: 4*parent.width/20; height: 5*parent.height/10
        radius: height/2

        ISAMTextInput {
            id: searchTextInputId
            anchors.centerIn: parent
            width: parent.width - 20; height: parent.height
            border.color: "#00000000"
            rightIcon: "qrc:/image/mainWin/board/board.png"
            radius: height/2
            defaultText: " 搜索条形码或名称"
            onIsReturnPressed: searched(barCodeText)
        }
    }
}
