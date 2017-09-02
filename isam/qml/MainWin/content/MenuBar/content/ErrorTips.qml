import QtQuick 2.0
import "../../../../Common/Button"

BaseButton {
    id: tipsLabelId
    visible: salesCommodityEditModel.errorStr !== ""
    anchors.centerIn: parent
    width: 4*parent.width/20; height: 9*parent.height/20
    radius: 5
    color: "#ff8400"
    btnText: salesCommodityEditModel.errorStr

    Timer {
        interval: 2000; running: salesCommodityEditModel.errorStr !== ""; repeat: true
        onTriggered: {
            salesCommodityEditModel.errorStr = ""
            stop()
        }
    }
}

