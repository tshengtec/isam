import QtQuick 2.0
import "./content"
import "../../../Common/Text"

Rectangle {
    id: salesInfoView
    width: parent.width; height: parent.height
    color: "#00000000"

    Row {
        anchors.fill: parent
        spacing: 15

        SalesInfoLabel {
            anchors.verticalCenter: parent.verticalCenter
            width: (parent.width - 3*parent.spacing)/3; height: parent.height
            title: "总金额"
            content: "0.00"
        }

        SalesInfoLabel {
            anchors.verticalCenter: parent.verticalCenter
            width: (parent.width - 3*parent.spacing)/3; height: parent.height
            title: "销售额"
            content: "0.00"
        }

        SalesInfoLabel {
            anchors.verticalCenter: parent.verticalCenter
            width: (parent.width - 3*parent.spacing)/3; height: parent.height
            title: "销售笔数"
            content: "0" + "笔"
        }
    }
}
