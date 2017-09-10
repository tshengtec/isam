import QtQuick 2.0
import "../../ProjectCommon/Text"

Column {
    property var payNumberItemHeight: (height - 2*spacing)/3 //private data

    width: parent.width; height: parent.height
    spacing: 5

    TextInputNumber {
        width: parent.width; height: payNumberItemHeight
        leftTitle: "总额"
        rightNumnber: "0.00"
    }

    Row {
        width: parent.width; height: payNumberItemHeight
        spacing: 10

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "现金"
        }

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "微信"
        }
    }

    Row {
        width: parent.width; height: payNumberItemHeight
        spacing: 10

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "合计"
            rightNumberColor: "#ec960b"
        }

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "找零"
            rightNumberColor: "#ec960b"
        }
    }
}
