import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    property variant allCommodityClassModel: []
    width: parent.width; height: parent.height
    color: "#d5d5d5"

    Column {
        anchors.fill: parent

        BaseButton {
            width: parent.width; height: 1.5*parent.height/20
            btnText: "选择分类"
            color: "#5acaa4"
        }

        BaseButton {
            width: parent.width; height: 1.5*parent.height/20
            color: "#eeeeee"

            Row {
                anchors.fill: parent

                Item { width: parent.width/20; height: 1}

                Text {
                    text: ">"
                    rotation: 90
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: parent.height/2.5
                    color: "#434350"
                }
                Item { width: parent.width/20; height: 1}
                Text {
                    text: "全部分类"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: parent.height/3
                    color: "#434350"
                }
            }

            Rectangle { width: parent.width; height: 1; color: "#d5d5d5"; anchors.bottom: parent.bottom }
        }

        AllClassListView {
            width: parent.width; height: 17*parent.height/20
            allClassListModel: allCommodityClassModel
        }
    }

}
