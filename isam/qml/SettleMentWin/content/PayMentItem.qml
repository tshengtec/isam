import QtQuick 2.0
import MyModels 1.0

Rectangle {
    id: paymentItem
    signal paymented()

    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        anchors.centerIn: parent
        width: parent.width - 0.2*parent.width; height: 0.85*parent.height

        Row {
            width: parent.width; height: 0.4*parent.height

            EditPayNumber {
                id: editPayNumber
                width: 0.65*parent.width; height: parent.height
                amountMoney: salesCommodityListModel.amountMoney

            }

            Item { width: 0.01*parent.width; height: parent.height }

            PayTypeSelection {
                width: 0.45*parent.width; height: parent.height

            }
        }

        Item { width: parent.width; height: 0.05*parent.height }

        Row {
            width: parent.width; height: 0.55*parent.height
            spacing: 10

            QuickSelectMoney {
                width: 0.5*parent.width; height: parent.height
                onClicked: editPayNumber.inputKeyBoard = money
            }

            PaymentOperation {
                width: 0.5*parent.width - 10; height: parent.height
                onPaymented: paymentItem.paymented()
            }
        }
    }

    SalesCommodityListModel {
        id: salesCommodityListModel
    }

    //data
    SalesCommodityEditModel {
        id: salesCommodityEditModel
    }
}
