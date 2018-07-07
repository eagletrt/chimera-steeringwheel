import QtQuick 2.7
import QtQuick.Layouts 1.3

Rectangle {
    id: racingPage
    color: "#000000"

    property int loopThroughPresets: -1

    property int currentCharge: 10
    property int currentTemperature: 8

    property int topBarHeight: 50

    property int carIsGo: 0

    signal presetChanged(int presetID)
    signal controlStateChanged(int ctrlIsEnabled, int ctrlIsOn, int warning, int error)

    function disconnect() {
        console.log("Disconnetto! Racing");
        mainwindow.btnPressed.disconnect(btnPressedHandler);
        mainwindow.btnReleased.disconnect(btnReleasedHandler);
        mainwindow.btnClicked.disconnect(btnClickedHandler);

        mainwindow.controlStateChanged.disconnect(controlStateChangedHandler);
        mainwindow.presetChanged.disconnect(presetChangedHandler);
    }

    function connect() {
        console.log("Connetto! Racing");
        mainwindow.btnPressed.connect(btnPressedHandler);
        mainwindow.btnReleased.connect(btnReleasedHandler);
        mainwindow.btnClicked.connect(btnClickedHandler);

        mainwindow.controlStateChanged.connect(controlStateChangedHandler);
        mainwindow.presetChanged.connect(presetChangedHandler);
    }


    function presetChangedHandler(presetID) {
        presetChanged(presetID);
    }


    function controlStateChangedHandler(ctrlIsEnabled, ctrlIsOn, warning, error) {
        controlStateChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
    }

    function btnPressedHandler(btnID) {
        if (btnID == 3) {
            radioStatus.state = 'on';
            StatusFrame.radio.opacity = 1;
            StatusFrame.radio_na.opacity = 0;
        }
    }

    function btnReleasedHandler(btnID) {
        if (btnID == 3) {
            radioStatus.state = 'off';
            StatusFrame.radio.opacity = 0;
            StatusFrame.radio_na.opacity = 1;
        }
    }

    function btnClickedHandler(btnID) {
        /* BUTTONS MAP
         * 0 - 12 top left
         * 1 - 14 bottom left
         * 2 - 26 bottom right
         */
        if (btnID == 0) {
            carIsGo = CarStatus.toggleCarStatus();

            if (carIsGo) {
                console.log("Sent Car Start command");
            } else {
                console.log("Sent Car Stop command");
            }
        }

        if (btnID == 1) {
            console.log("Car is Go == " + carIsGo)
            if (carIsGo) {
                // Stop the car
                carIsGo = CarStatus.stopCar();
            }
        }

        if (btnID == 2) {

        }

        if (btnID == 3) {
           /*
               emit della funziona che ti permette di cambiare
               hv lv throttle brake e velocity

               un altro emit per poter far partire il timer
               che dal tempo di adesso va a 0
               sottraendo il valore di quando è
               stato emesso
           */
        }
    }

    GridLayout {
        id: mainlayout
        rows: 2
        anchors.fill: parent
        flow: GridLayout.TopToBottom


        Rectangle {
            Layout.fillHeight: true
            width: parent.width
            color: "transparent"

            GridLayout {
                id: body
                anchors.fill: parent
                columns: 1 //3

                CentralView {
                    id: centralview
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }
    }
}
