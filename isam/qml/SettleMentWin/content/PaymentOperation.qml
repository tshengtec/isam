import QtQuick 2.0

Rectangle {
    id: paymentOperation
    width: parent.width; height: parent.height
    color: "#00000000"

    Column {
        spacing: 10

        ShadowButton {
            width: 0.05*paymentOperation.width; height: 0.2*paymentOperation.height
            color: "#ec960b"
            title: "50"
            titleColor: "white"
        }

        ShadowButton {
            width: 0.05*paymentOperation.width; height: 0.2*paymentOperation.height
            color: "#ec960b"
            title: "50"
            titleColor: "white"
        }

        ShadowButton {
            width: 0.05*paymentOperation.width; height: 0.2*paymentOperation.height
            color: "#ec960b"
            title: "50"
            titleColor: "white"
        }

        ShadowButton {
            width: 0.05*paymentOperation.width; height: 0.2*paymentOperation.height
            color: "#ec960b"
            title: "50"
            titleColor: "white"
        }
    }
}
