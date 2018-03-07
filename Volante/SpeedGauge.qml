import QtQuick 2.7

Rectangle {

    property int hvTemp: CAN.hvTemp;
    property int hvVolt: CAN.hvVolt;
    property int lvTemp: CAN.lvTemp ;
    property int lvVolt: CAN.lvVolt;

    property int velocity: CarStatus.velocity

    onVelocityChanged: {
        console.log("Cambio di velocità!");
        console.log(velocity);

        textVelocity.text = "" + velocity
    }

    onHvTempChanged: {
        console.log("Cambio Temperatura HV!");
        console.log(hvTemp);

        texthvTemp.text = "" + hvTemp + " C"
    }

    onLvTempChanged: {
        console.log("Cambio Temperatura LV!");
        console.log(lvTemp);

        textlvTemp.text = "" + lvTemp + " C"
    }

    onHvVoltChanged: {
        console.log("Cambio voltaggio HV!");
        console.log(hvVolt);

        texthvVolt.text = "" + hvVolt + " V"
    }

    onLvVoltChanged: {
      console.log("Cambio voltaggio LV!");
      console.log(lvVolt);

      textlvVolt.text = "" + lvVolt + " V"
    }

    color: "transparent"

    Text {
        id: texthvTemp
        text: "HV_Temp"
        y: 25
        color: "white"
    }

    Text {
        id: texthvVolt
        font.pointSize: 12
        text: "HV_Volt"
        y: 50
        color: "white"
    }

    Text {
        id: textlvTemp
        text: "LV_Temp"
        x: 250
        y: 25
        color: "white"
    }

    Text {
        id: textlvVolt
        font.pointSize: 12
        text: "LV_Volt"
        x: 250
        y: 50
        color: "white"
    }

    Text {
        id: textVelocity
        text: "0"
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
