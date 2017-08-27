import QtQuick 2.0

Rectangle {
    signal todaySales();
    signal squadSales();
    property bool selectedStatus: true
    width: parent.width; height: parent.height
    color: "#eeeeee"

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width; height: 1
        color: "#d5d5d5"
    }

    Row {
        anchors.fill: parent
        Text {
            width: parent.width/2; height: parent.height
            font.pixelSize: height/3
            color: selectedStatus ? "#33a4e2" : "#434350"
            text: "今天本机销售"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            Rectangle {
                width: parent.width; height: 1
                anchors.bottom: parent.bottom
                color: selectedStatus ? "#33a4e2" : "#00000000"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    todaySales()
                    selectedStatus = true
                }
            }
        }

        Text {
            width: parent.width/2; height: parent.height
            font.pixelSize:  height/3
            color: !selectedStatus ? "#33a4e2" : "#434350"
            text: "本次当班销售"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            Rectangle {
                width: parent.width; height: 1
                anchors.bottom: parent.bottom
                color: !selectedStatus ? "#33a4e2" : "#00000000"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    squadSales()
                    selectedStatus = false
                }
            }
        }
    }
}
