import QtQuick 2.0
import "../../../Common/Button"

Item {
    property variant salseListModel: []
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        BaseButton {
            width: parent.width; height: 2*parent.height/20
            color: "#eeeeee"

            Text {
                x: 5
                text: "销售单据列表"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: parent.height/3.5
                color: "#434350"
            }

            BaseButton {
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.verticalCenter: parent.verticalCenter
                width: 2*parent.width/20; height: width
                radius: width/2
                btnText: listViewId.count
                color: "#33a4e2"
            }

            Rectangle { width: parent.width; height: 1; color: "#d5d5d5"; anchors.bottom: parent.bottom }
        }

        ListView {
            id: listViewId
            width: parent.width; height: 17.2*parent.height/20
            clip: true
            model: salseListModel
            delegate:
            Rectangle {
                width: listViewId.width; height: listViewId.height/7
                color: listViewId.currentIndex === index ? "lightblue" : "#00000000"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        listViewId.currentIndex = index
                        salesQueryListModel.reload(modelData.id)
                    }
                }

                Column {
                    width: 12*parent.width/20; height: parent.height

                    Text {
                        x: 5
                        width: parent.width; height: parent.height/2
                        verticalAlignment: Text.AlignVCenter
                        text: "订单号:  " + modelData.id
                        font.pixelSize: parent.height/4
                        color: "#434350"
                    }

                    Text {
                        x: 5
                        width: parent.width; height: parent.height/2
                        verticalAlignment: Text.AlignVCenter
                        text: "金    额:  "+ modelData.amountMoney +"(元)"
                        font.pixelSize: parent.height/4
                        color: "#434350"
                    }
                }


                Text {
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    text: Qt.formatTime(modelData.time, "hh:mm AP")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: parent.height/4
                    color: "#434350"
                }

                Rectangle { width: parent.width; height: 1; color: "#eeeeee"; anchors.bottom: parent.bottom }

            }
        }
    }
}
