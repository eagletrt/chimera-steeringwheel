import QtQuick 2.7
import QtQuick.Layouts 1.3

Rectangle {
    color: "transparent"

    Connections {
        target: racingPage
        onControlStateChanged: {
            console.log("CtrlStateChanged");

            if (ctrlIsEnabled == 1) {
                ctrlLED.enabled = true
            } else {
                ctrlLED.enabled = false
            }

            // When the user chooses not to abilitate the Ctrl
            if (ctrlIsOn == 1) {
                ctrlLED.active = true
            } else {
                ctrlLED.active = false
            }

            if (warning) {
                warnLED.state = 'on';
            } else {
                console.log("Setting warning to off");
                warnLED.state = 'off';
            }

            if (error) {
                errLED.state = 'on';
            } else {
                errLED.state = 'off';
            }
        }
    }


    GridLayout {
        anchors.fill: parent
        columns: 4

        CtrlLabelLED {
            id: ctrlLED
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
            enabled: false
            active: false
        }

        LabelLED {
            id: warnLED
            Layout.fillWidth: true
            Layout.fillHeight: true
            ledColor: "yellow"
            text: "WARN"
            state: "off"
        }

        LabelLED {
            id: errLED
            Layout.fillWidth: true
            Layout.fillHeight: true
            ledColor: "red"
            text: "ERR"
            state: "off"
        }
    }
}
