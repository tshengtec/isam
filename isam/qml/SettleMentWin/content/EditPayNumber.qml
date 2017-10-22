import QtQuick 2.0
import "../../ProjectCommon/Text"

Column {
    property var payNumberItemHeight: (height - 2*spacing)/3 //private data
    property string amountMoney: "0.00"
    property string inputKeyBoard: ""

    width: parent.width; height: parent.height
    spacing: 5

    onInputKeyBoardChanged: {
        console.log(cashTextInput.textInputFocus, ">>>>>")
        if (cashTextInput.textInputFocus) {
            cashTextInput.addText = inputKeyBoard
            inputKeyBoard = ""
            console.log(inputKeyBoard, cashTextInput.rightNumnber)
        }
    }

    TextInputNumber {
        width: parent.width; height: payNumberItemHeight
        leftTitle: "总额"
        enable: false
        rightNumnber: amountMoney
    }

    Row {
        width: parent.width; height: payNumberItemHeight
        spacing: 10

        TextInputNumber {
            id: cashTextInput
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
