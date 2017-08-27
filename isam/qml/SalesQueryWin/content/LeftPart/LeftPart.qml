import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    property variant allSalseListModel: []
    width: parent.width; height: parent.height
    color: "#d5d5d5"

    Column {
        anchors.fill: parent

        SalesTopBar {
            width: parent.width; height: 1.5*parent.height/20
        }

        BaseButton {
            width: parent.width; height: 1.5*parent.height/20
            color: "#eeeeee"

            Text {
                x: 5
                text: "销售统计"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height/3.5
                color: "#434350"
            }

            Text {
                x: parent.width - 20
                text: ">"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height/3
                color: "#434350"
            }

            Rectangle { width: parent.width; height: 1; color: "#d5d5d5"; anchors.bottom: parent.bottom }
        }

        AllSalesList {
            width: parent.width; height: 15.5*parent.height/20
            salseListModel: allSalseListModel
        }

        Rectangle {
            width: parent.width; height: 1.5*parent.height/20
        }
    }
}
