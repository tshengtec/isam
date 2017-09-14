import QtQuick 2.0
import "./content"
import "../Common/ListView"
import "../Common/Text"
import "../Common/Window"

MyWindow {
    property variant displayListModel: []
    id: rootId
    width: parent.width; height: parent.height
    color: "#60000000"
    onVisibleChanged: {
        if (visible) {
            searchBarId.textInputFocus = true
        }
        else {
            searchBarId.textInputFocus = false
        }
    }

    MouseArea { anchors.fill: parent }

    Rectangle {
        id: backGroundId
        anchors.centerIn: parent
        width: 0.5*parent.width; height: parent.height/1.5
        radius: 10
        color: "white"

        Column {
            anchors.fill: parent

            TitleBar {
                width: parent.width; height: 2*parent.height/20
                onExited: rootId.visible = false
            }

            Item { width: 1; height: 0.5*parent.height/20 }

            SearchBar {
                id: searchBarId
                width: parent.width; height: 2*parent.height/20
                text: displayListModel.searchText
                onSearched: displayListModel.searchText = text
            }

            Item { width: 1; height: 0.5*parent.height/20 }

            SearchCommodityList {
                width: parent.width; height: 13*parent.height/20
                model: displayListModel
                onAddCommodity: salesCommodityEditModel.add(getCommodityId(index))
            }

            Row {
                x: 10
                width: parent.width; height: 2*parent.height/20

                MText {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "匹配到"
                    color: "#b8b8b8"
                    font.pixelSize: parent.height/3
                }
                MText {
                    anchors.verticalCenter: parent.verticalCenter
                    color: "red"
                    text: String(displayListModel.total)
                    font.pixelSize: parent.height/3
                }
                MText {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "个商品"
                    color: "#b8b8b8"
                    font.pixelSize: parent.height/3
                }
            }
        }
    }

    function getCommodityId(index) {
        if (displayListModel !== undefined && index < (displayListModel.size()) && index >= 0)
            return displayListModel.at(index).id
        else
            return "";
    }
}
