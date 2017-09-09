import QtQuick 2.1
import "../Text"

Rectangle {
    property bool onOff: true
    property string contentText: ""

//    width: parent.width
//    height: parent.height
    radius: height/2
    color: "#5b79f5"

    onOnOffChanged: {
            sliderBtAnimation.stop()
            if (!onOff)
                sliderBtAnimation.to = width - sliderBt.width
            else
                sliderBtAnimation.to = 0
            sliderBtAnimation.start()
    }

    NumberAnimation {
        id: sliderBtAnimation;
        target: sliderBt;
        properties: "x";
        to:0;
        duration: 200 ;
        easing.type: Easing.InOutQuad
        Component.onCompleted: { onOff = !onOff; onOff = !onOff }
    }

    Item {
        id: sliderBt
        anchors.verticalCenter: parent.verticalCenter
        width: parent.height; height: width

        Rectangle {
            anchors.centerIn: parent
            width: 0.9*parent.height; height: width
            radius: width/2

        }

        MouseArea {
            anchors.fill: parent
            onClicked: onOff = !onOff
        }
    }

    MText {
        x: onOff ? parent.height + 5 : 5
//        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 0.5*parent.height
        color: "white"
        text: contentText
    }
}
