import QtQuick 2.5
import QtQuick.Window 2.2
import "./content/MenuBar"

Window {
    visible: true
    width: 1024
    height: 600
    title: qsTr("")

    Column {
        MenuBar {}
    }
}
