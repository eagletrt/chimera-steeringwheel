import QtQuick 2.7
import QtQuick.Layouts 1.3 

Rectangle {
    id: root
    color: "transparent"

    GridLayout {
        anchors.fill: parent
        flow: GridLayout.TopToBottom
        Layout.margins: 0

        StatusLED {
            id: statusleds
            height: 40
            Layout.fillWidth: true
        }

        SpeedGauge {
            id: speedgauge
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width
        }

        Presets {
            height: 35
            Layout.fillWidth: true
        }
    }
}

/*
Rectangle {
            id: centralview
            color: "transparent"
            width: body.width - batterytemp.width * 2 
            height: parent.height
            x: batterytemp.width

            Rectangle {
                id: presets1
                width: 50
                height: body.height
                color: "black"
                */

