import QtQuick 2.7

Rectangle {
    id: root
    height: parent.height
    border.width: 4
    color: 'transparent'

    property int charge: 0
    property var chargeColors: ['red', '#ffaaaa', 'orange', 'green']
    property var temperatureColors: ['red', 'orange', 'teal', 'blue']
    property var currentChargeColor
    property var temperature

    onChargeChanged: {
        //console.log("New Charge: " + charge);
        currentChargeColor = getColorByCharge(charge);
    }

    function getColorByCharge(chargeLevel) {
        var colorIndex = parseInt(chargeLevel / 4);

        if (temperature) {
            return temperatureColors[colorIndex];
        }
        return chargeColors[colorIndex];
    }

    Column {
        id: column  

        width: root.width - 8
        height: root.height - 8 
        x: 4
        y: 4

        Repeater {
            model: 16
            Rectangle {
                height: column.height / 16 
                width: column.width 
                border.width: 2
                //color: "red"
                color: index < 15 - charge ? 'transparent' : currentChargeColor 
            }
        }

    }

    Rectangle {
        border.width: 7
        visible: charge == -1
        anchors.fill: parent
        color: "red"

        Text {
            anchors.centerIn: parent
            text: "finio"
            color: "white"
        }
    }
}
