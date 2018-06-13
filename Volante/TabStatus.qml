import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    property var btnClickable: false
    property var isStarted: false
    property var canstatus: CarStatus.CANStatus
    property var ledStates: ['NO', 'OK', 'DEFAULT']
    property var canLeds: [
        ["InvRight", 'CAN_DEFAULT'],
        ["InvLeft", 'CAN_DEFAULT'],
        ["PyFront", 'CAN_DEFAULT'],
        ["PyRear", 'CAN_DEFAULT'],
        ["BMS HV", 'CAN_DEFAULT'],
        ["BMS LV", 'CAN_DEFAULT'],
    ]

    onCanstatusChanged: {
        console.log("Cambiato il CAN Status da Centralina");
        var newCanLeds = canLeds;

        for (var i=0; i < canstatus.length; i++) {
            newCanLeds[i][1] = ledStates[canstatus[i]];
        }

        canLeds = newCanLeds;
    }

    function connect() {
        console.log("Tab connessa - Status");
        mainwindow.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
        console.log("Tab disconnessa - Status");
        mainwindow.btnClicked.disconnect(btnClickedHandler);
    }

    function btnClickedHandler(btnID) {
        if (btnID == 2) {
            // Step into this tab and change the behaviour of btnID
            if (!tabView.stepIntoTab) {
                // Set the button clickable
                btnClickable = true;

                // Prevent the button 0 to switch to Racing Page!
                tabView.stepIntoTab = true;
                mainwindow.canSwitchPage = false;

            } else {
                if (!isStarted) {
                    // Set ok to the update!
                    isStarted = true;
                    console.log("Set communication OK");
                    CAN.checkCANCommunication(true);
                }

                // Set the button again to be not clickable
                btnClickable = false;

                // Restore Button 0 initial handler
                mainwindow.canSwitchPage = true;
                tabView.stepIntoTab = false;
            }
        }

        if (btnID == 1) {
            if (tabView.stepIntoTab) {
                // Ask again!
                console.log("CheckCANCommunication");
                CAN.checkCANCommunication(false);

            }
        }

        if (btnID == 0) {
            if (!mainwindow.canSwitchPage) {
               // Set
               // do something
            }
        }
    }

    Component.onCompleted: {
        // First tab, connect it!
        connect();
    }

    Rectangle {
        id: status
        color: menu.color
        anchors.fill: parent

        GridLayout {
            id: grid1
            columns: 2
            rows: 4
            anchors.fill: parent
            columnSpacing: 0
            rowSpacing: 0

            Repeater {
                model: canLeds
                delegate: CANStatusLED {
                    text: modelData[0]
                    state: modelData[1]
                    Layout.preferredWidth: status.width / 2
                    Layout.preferredHeight: status.height / 4
                }
            }

            Rectangle {
                Layout.preferredWidth: status.width / 2
                Layout.preferredHeight: status.height / 4
                color: "#000000"

                Button {
                    state: root.btnClickable ? 'SELECTED' : 'IDLE'
                    activeColor: "blue"
                    text: "ASK AGAIN"
                }
            }


            Rectangle {
                Layout.preferredWidth: status.width / 2
                Layout.preferredHeight: status.height / 4
                color: "#000000"

                Button {
                    state: root.btnClickable & !isStarted ? 'SELECTED' : 'IDLE'
                    activeColor: "green"
                    text: "START"
                }
            }
        }
    }
}
