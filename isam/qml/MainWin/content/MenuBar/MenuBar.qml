import QtQuick 2.0
import "../../../Common/Button"

Rectangle {
    id: rootId
    width: parent.width; height: parent.height
    color: themesModel.backgroundColor

    Row {
        spacing: 20
        BaseButton {
            width: rootId.width/10; height: rootId.height
            color: "red"
            btnText: "xxx"
        }

        BaseButton {
            width: rootId.width/10; height: rootId.height
            color: "red"
            btnText: "xxx"
        }

        BaseButton {
            width: rootId.width/10; height: rootId.height
            color: "red"
            btnText: "xxx"
        }

        BaseButton {
            width: rootId.width/10; height: rootId.height
            color: "red"
            btnText: "xxx"
        }
    }
}
