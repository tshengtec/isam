import QtQuick 2.0
import "../../../Common/Button"

Item {
    property variant allClassListModel: []
    width: parent.width; height: parent.height

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        model: ["1", "2222"]//allClassListModel
        delegate:
        Item {
            width: listViewId.width; height: listViewId.height/12

            Text {
                anchors.verticalCenter: parent.verticalCenter
                x: 2*parent.width/10
                text: modelData
                color: "black"
                font.pixelSize: parent.height/2.5
            }
            Rectangle { width: parent.width; height: 1; color: "#eeeeee"; anchors.bottom: parent.bottom }

        }
    }
}
