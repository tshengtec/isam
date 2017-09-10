import QtQuick 2.0

Item {
    id: quickSelectMoney

    signal clicked(string money)

    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent
        spacing: 10

        Column {
            width: 0.25*parent.width; height: parent.height
            spacing: 10

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                color: "#ec960b"
                title: "50"
                titleColor: "white"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                color: "#ec960b"
                title: "100"
                titleColor: "white"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                color: "#ec960b"
                title: "200"
                titleColor: "white"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                color: "#ec960b"
                title: "300"
                titleColor: "white"
                onClicked: quickSelectMoney.clicked(title)
            }
        }

        Column {
            width: (parent.width - 0.25*parent.width-10)/3; height: parent.height
            spacing: 10

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "1"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "4"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "7"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "0"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }
        }

        Column {
            width: (parent.width - 0.25*parent.width - 10)/3; height: parent.height
            spacing: 10

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "2"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "5"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "8"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "00"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }
        }

        Column {
            width: (parent.width - 0.25*parent.width-10)/3; height: parent.height
            spacing: 10

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "3"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "6"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "9"
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }

            ShadowButton {
                width: parent.width; height: (parent.height - 30)/4
                title: "."
                titleColor: "black"
                onClicked: quickSelectMoney.clicked(title)
            }
        }

    }
}
