import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    width: parent.width; height: parent.height
    color: "#d5d5d5"

    Column {
        anchors.fill: parent

        SalesTopBar {
            width: parent.width; height: 2*parent.height/20
        }

        BaseButton {
            width: parent.width; height: 2*parent.height/20
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
        }
    }
}
