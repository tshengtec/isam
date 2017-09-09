import QtQuick 2.0
import "../../../../Common/Text"

Rectangle {
    id: headerItemId
    width: parent.width; height: parent.height
    color: "#f0f0f0"
    Row {
        Repeater {
            model: ["序号", "条形码", "商品名称", "数量", "单价(元)", "折扣(%)", "折后单价(元)", "小计", "备注"]
            Item {
                width: spacingWidth[index]; height: headerItemId.height

                MText {
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
