import QtQuick 2.5
import MyModels 1.0
import "./content"

Rectangle {
    property variant spacingWidth: [1*width/20, 3*width/20, 4*width/20, 1*width/20, 1.5*width/20,
                                    1.5*width/20, 2*width/20, 1.5*width/20, 4.5*width/20]
    width: parent.width; height: parent.height
    color: "lightblue"



    //backGround
    ListView {
        id: listViewBackGroundId
        width: parent.width; height: parent.height
        model: 10
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: HeaderDelegate {
            z: 1.5
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
        }

        delegate: ListViewDelegate {
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
        }
    }

    ListView {
        id: listViewId
        z: listViewBackGroundId*2
        width: parent.width; height: parent.height
        model: salesQueryListModel//salesCommodityListModel
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header: Item {
            clip: true
            width: listViewBackGroundId.width; height: listViewBackGroundId.height/11
        }
        delegate: SalesCommodityDelegete {
            width: listViewId.width; height: listViewId.height/11
        }
    }
}
