import QtQuick 2.5

Rectangle {
    property variant spacingWidth: [70, 130, 215, 70, 90, 90, 90, 100, 170]
    width: parent.width; height: parent.height
    color: "lightblue"



    ListView {
        id: listViewId
        anchors.fill: parent
        model: 10
        clip: true
        interactive: false
        headerPositioning: ListView.OverlayHeader
        header:
        Rectangle {
            id: headerItemId
            z: 1.5
            width: listViewId.width; height: listViewId.height/11
            color: "#d5d5d5"
            Row {
                Repeater {
                    model: ["序号", "条形码", "商品名称", "数量", "单价(元)", "折扣(%)", "折后单价(元)", "小计", "备注"]//listViewId.count
                    Item {
                        width: spacingWidth[index]; height: headerItemId.height

                        Text {
                            anchors.centerIn: parent
                            text: modelData
                            font.pixelSize: parent.height/2.5
                        }

                        Rectangle {
                            anchors.right: parent.right
                            width: 1; height: parent.height
                            color: "gray"
                        }
                    }
                }
            }
        }
        delegate:
        Rectangle {
            id: delegeRectId
            width: listViewId.width; height: listViewId.height/11
            color: index%2 === 0 ? "white" : "#d5d5d5"

            Rectangle {
                width: parent.width; height: 1
                color: "gray"
            }

            Row {
                Repeater {
                    model: listViewId.count
                    Item {
                        width: spacingWidth[index]; height: delegeRectId.height
                        Rectangle {
                            anchors.right: parent.right
                            width: 1; height: parent.height
                            color: "gray"
                        }
                    }
                }
            }
        }
    }
}
