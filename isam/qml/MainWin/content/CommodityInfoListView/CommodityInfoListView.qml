import QtQuick 2.5

Rectangle {
    property variant spacingWidth: [1*width/20, 3*width/20, 4*width/20, 1*width/20, 1.5*width/20,
                                    1.5*width/20, 2*width/20, 1.5*width/20, 4.5*width/20]
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
            color: "#f0f0f0"
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
                            color: "#d7d7d7"
                        }
                    }
                }
            }
        }
        delegate:
        Rectangle {
            id: delegeRectId
            width: listViewId.width; height: listViewId.height/11
            color: index%2 === 0 ? "white" : "#eeeeee"

            Rectangle {
                width: parent.width; height: 1
                color: "#d7d7d7"
            }

            Row {
                Repeater {
                    model: listViewId.count
                    Item {
                        width: spacingWidth[index]; height: delegeRectId.height
                        Rectangle {
                            anchors.right: parent.right
                            width: 1; height: parent.height
                            color: "#d7d7d7"
                        }
                    }
                }
            }
        }
    }
}
