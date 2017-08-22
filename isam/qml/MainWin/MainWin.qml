import QtQuick 2.5
import QtQuick.Window 2.2
import "./content/MenuBar"

Window {
    id: windowsId
    visible: true
    width: 1024
    height: 600
    title: qsTr("")

    Column {
        MenuBar {
            width: windowsId.width; height: 3*windowsId.height/20
        }
    }
}
