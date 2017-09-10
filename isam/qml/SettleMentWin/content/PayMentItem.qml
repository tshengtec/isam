import QtQuick 2.0

Rectangle {
    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        anchors.centerIn: parent
        width: parent.width - 0.2*parent.width; height: 0.85*parent.height

        Row {
            width: parent.width; height: 0.4*parent.height

            EditPayNumber {
                width: 0.65*parent.width; height: parent.height
            }

            Item { width: 0.01*parent.width; height: parent.height }

            PayTypeSelection {
                width: 0.45*parent.width; height: parent.height

            }
        }

        Item { width: parent.width; height: 0.05*parent.height }

        Row {
            width: parent.width; height: 0.55*parent.height

            QuickSelectMoney {
                width: 0.5*parent.width; height: parent.height
            }
        }
//        PaymentOperation {
//        }
    }
}
