import QtQuick 2.0
import "../../ProjectCommon/Text"

Column {
    property var payNumberItemHeight: (height - 2*spacing)/3 //private data
    property string amountMoney: "0.00"
    property var objList: [cashTextInput, wxpayTextInput, alipayTextInput]
    property bool cash: true
    property bool alipay: false
    property bool wxpay: false

    width: parent.width; height: parent.height
    spacing: 5

    TextInputNumber {
        width: parent.width; height: payNumberItemHeight
        leftTitle: "总额"
        enable: false
        rightNumnber: amountMoney
    }

    Row {
        width: parent.width; height: payNumberItemHeight
        spacing: 10

        TextInputNumber {
            id: cashTextInput
            width: checkLength(cash, wxpay, alipay) ? parent.width : parent.width/2 - 5;
            height: parent.height
            leftTitle: "现金"
            visible: cash
        }

        TextInputNumber {
            id: wxpayTextInput
            width: checkLength(cash, wxpay, alipay) ? parent.width : parent.width/2 - 5;
            height: parent.height
            leftTitle: "微信"
            visible: wxpay
        }

        TextInputNumber {
            id: alipayTextInput
            width: checkLength(cash, wxpay, alipay) ? parent.width : parent.width/2 - 5;
            height: parent.height
            leftTitle: "支付宝"
            visible: alipay
        }
    }

    Row {
        width: parent.width; height: payNumberItemHeight
        spacing: 10

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "合计"
            rightNumberColor: "#ec960b"
            enable: false
            rightNumnber: toDot2(checkTotal(cash, wxpay, alipay))
        }

        TextInputNumber {
            width: parent.width/2 - 5; height: parent.height
            leftTitle: "找零"
            rightNumberColor: "#ec960b"
            enable: false
            rightNumnber: toDot2(checkTotal(cash, wxpay, alipay) - Number(amountMoney))
        }
    }

    function addText(addText) {
        for (var i = 0; i < objList.length; i++) {
            if (objList[i].textInputFocus) {
                objList[i].addText(addText)
                break
            }
        }
    }


    function subText() {
        for (var i = 0; i < objList.length; i++) {
            if (objList[i].textInputFocus) {
                objList[i].subText()
                break
            }
        }
    }

    function checkLength(cash, wxpay, alipay) {
        var temp = 0
        if (cash)
            temp++
        if (wxpay)
            temp++
        if (alipay)
            temp++

        if (temp === 2)
            return false
        else
            return true
    }

    function checkTotal(cash, wxpay, alipay) {
        var total = 0;
        if (cash)
            total += Number(cashTextInput.rightNumnber)
        if (wxpay)
            total += Number(wxpayTextInput.rightNumnber)
        if (alipay)
            total += Number(alipayTextInput.rightNumnber)
        return total
    }

    function init() {
        cashTextInput.rightNumnber = "0.00"
        wxpayTextInput.rightNumnber = "0.00"
        alipayTextInput.rightNumnber = "0.00"
    }

    //保留3位小数，如：3, 在3后面补上00.即3.00
    function toDot2(value) {
        var fvalue = parseFloat(value);
        if (isNaN(fvalue)) {
            return false;
        }

        var fvalue = Math.round(value*100)/100;
        var fvaluestr = fvalue.toString();
        var resolution = fvaluestr.indexOf('.');

        if (resolution < 0) {
            resolution = fvaluestr.length;
            fvaluestr += '.';
        }
        while (fvaluestr.length <= resolution + 2) {
            fvaluestr += '0';
        }
        return fvaluestr;
    }
}
