import QtQuick 2.1

Rectangle {
    property bool   on: false
    property string btMesg: ""
    property string btText: ""
    property string textColor: "#ffffff"
    property string onTextColor: textColor
    property string offTextColor: textColor
    property real   fontSize: 20
    property string buttonColor: "#00000000"
    property string onColor: buttonColor
    property string offColor: buttonColor
    property string btIcon: ""
    property string onIcon: btIcon
    property string offIcon: btIcon

    width: 80; height: 60
    color: on?onColor:offColor
    focus : true
    signal clicked()
    signal clickedWithMesg(string mesg)
    signal pressed()
    signal release()

    function setOnOff(onOff) {
        on = onOff
    }

    function getOnOff() {
        return on
    }

    Image {
        anchors.centerIn: parent
        source: on?onIcon:offIcon
    }
    Text {
        anchors.centerIn: parent
        text: btText
        color: on?onTextColor:offTextColor
        font.pixelSize: fontSize
    }

    MouseArea{
        id : mouseArea
        anchors.fill: parent
        onClicked: {
            parent.clicked()
            parent.clickedWithMesg(btMesg)
        }
        onPressed: {
            parent.pressed(btMesg)
        }
        onReleased: {
            parent.release()
        }
    }
}
