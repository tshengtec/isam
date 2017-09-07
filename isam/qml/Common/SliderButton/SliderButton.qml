import QtQuick 2.1

Rectangle {
    property bool onOff: false
    property bool useAnimation: true

    width: 194
    height: 46
    radius: height/2
    color: "#5b79f5"

    onOnOffChanged: {
            sliderBtAnimation.stop()
            if (onOff)
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


}
