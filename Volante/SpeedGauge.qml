import QtQuick 2.7

Rectangle {

    property int hvTemp: CAN.hvTemp;
    property int hvVolt: CAN.hvVolt;
    property int lvTemp: CAN.lvTemp;
    property int lvVolt: CAN.lvVolt;

    property int velocity: CarStatus.velocity

    color: "transparent"

    Text {
        id: texthvTemp
        text: CAN.hvTemp +  " °C"
        x: 7
        y: 25
        color: "white"
    }

    Text {
        id: texthvVolt
        font.pointSize: 12
        text: CAN.hvVolt +  " V"
        y: 50
        color: "white"
    }

    Text {
        id: textlvTemp
        text: CAN.lvTemp + " °C"
        x: 327
        y: 25
        color: "white"
    }

    Text {
        id: textlvVolt
        font.pointSize: 12
        text: CAN.lvVolt + " V"
        x: 320
        y: 50
        color: "white"
    }

    Text {
        id: textVelocity
        text: velocity
        font.pointSize: 70
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -5
        color: "white"
    }

    Text {
        text: "kmh"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 50
        color: "white"
    }
}
