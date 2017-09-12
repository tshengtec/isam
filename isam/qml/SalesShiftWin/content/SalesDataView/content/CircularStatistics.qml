import QtQuick 2.0

Rectangle {
    property var moneyPay: 0.00
    property var weChatPay: 0.00
    property var aliPay: 0.00
    property var totalPay: moneyPay + weChatPay + aliPay
    width: parent.width; height: parent.height
    radius: width/2


    Canvas {
        id:canvas
        property point centrePoint: Qt.point(parent.radius, parent.radius)
        property var circle: 3.1415926*2
        property var moneyPayRate: moneyPay/totalPay // 0.00 - 0.10
        property var weChatPayRate: weChatPay/totalPay
        property var aliPayRate: aliPay/totalPay
        anchors.fill: parent
        onPaint:{
            var ctx = canvas.getContext('2d');
            ctx.lineWidth = 20;

            ctx.beginPath();
            ctx.strokeStyle = "#f59c0c"
            ctx.arc(centrePoint.x, centrePoint.y, centrePoint.x - 10,
                    0, moneyPayRate*circle)
            ctx.stroke()

            ctx.beginPath();
            ctx.strokeStyle = "#31ce4b"
            ctx.arc(centrePoint.x, centrePoint.y, centrePoint.x - 10,
                    moneyPayRate*circle, moneyPayRate*circle+weChatPayRate*circle)
            ctx.stroke()

            ctx.beginPath();
            ctx.strokeStyle = "#17a1de"
            ctx.arc(centrePoint.x, centrePoint.y, centrePoint.x - 10,
                    moneyPayRate*circle+weChatPayRate*circle, moneyPayRate*circle+weChatPayRate*circle + aliPayRate*circle)
            ctx.stroke()
        }
    }
}
