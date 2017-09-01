import QtQuick 2.0
import "../../../Common/Button"

Item {
    signal selectedCommodityType(string type)
    property variant allCommodityTypeModel: []
    width: parent.width; height: parent.height

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        model: allCommodityTypeModel
        currentIndex: 0
        delegate:
        Rectangle {
            width: listViewId.width; height: listViewId.height/12

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    selectedCommodityType(modelData)
                    listViewId.currentIndex = index
                }
            }

            Rectangle {
                x: parent.width/40
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width/20; height: width
                radius: width/2
                color: listViewId.currentIndex === index ? "#ff8400" : "#00000000"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                x: parent.width/10
                text: modelData
                color: "black"
                font.pixelSize: parent.height/2.5
            }
            Rectangle { width: parent.width; height: 1; color: "#d5d5d5"; anchors.bottom: parent.bottom }

        }
    }
}
