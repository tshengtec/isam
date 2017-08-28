import QtQuick 2.0
import "./content"
import "../Common/ListView"

Rectangle {
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
        width: parent.width/1.3; height: parent.height/1.5
        color: "white"

        Column {
            anchors.fill: parent

            TitleBar {
                width: parent.width; height: 2.5*parent.height/20
                onExited: rootId.visible = false
            }

            Item { width: 1; height: 0.5*parent.height/20 }

            SearchBar {
                id: searchBarId
                width: parent.width; height: 2*parent.height/20
                onSearched: displayListModel.searchText = text
            }

            Item { width: 1; height: 0.5*parent.height/20 }

            SearchCommodityList {
                width: parent.width; height: 12.5*parent.height/20
                model: displayListModel
                onAddCommodity: salesCommodityEditModel.add(getCommodityId(index))
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
