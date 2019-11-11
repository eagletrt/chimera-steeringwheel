import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id: root
    anchors.fill: parent
    color: "#000000"

    FontLoader {id:blackops; source: "../lib/blops.ttf"}

    property var telemetrySelectedIndex: -1
    property var btnClickable: false
    property var telemetrystatus: CarStatus.TelemetryStatus
    property var firstCheck: true //When the tab is opened for the first time, it tries to load the telemetry repeater but isn't already filled.
                                  //So, this variable is used in order to avoid errors the first time the window is opened. Better ideas required :)
    property var ledStates: ['0', '1', '2'] //OFFLINE, ONLINE, DEFAULT
    property var telemetryLeds: [
    ["HV", telemetrystatus[0]],
    ["LV", telemetrystatus[1]],
    ["GPS", telemetrystatus[2]],
    ["IMUGY", telemetrystatus[3]],
    ["IMUAX", telemetrystatus[4]],
    ["FRNTW", telemetrystatus[5]],
    ["STR", telemetrystatus[6]],
    ["THR", telemetrystatus[7]],
    ["BRK", telemetrystatus[8]],
    ["DB", telemetrystatus[9]],
    ["MQTT", telemetrystatus[10]]
    ] 
   
    onTelemetrystatusChanged: {
       if(!firstCheck) {
         for(var i = 0; i < telemetrystatus.length; i++){
            telemetryRepeater.itemAt(i).state = telemetrystatus[i];
         } 
       } else {
          firstCheck = false;
       }
    }

    function connect() {
       menu.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
       menu.btnClicked.disconnect(btnClickedHandler);
    }

    function unSelectTelemetry() {
        if (telemetrySelectedIndex != -1) {
            telemetryRepeater.itemAt(telemetrySelectedIndex).selected = 0;
        }
    }

    function selectTelemetry(index) {
        unSelectTelemetry();

        index = index % 11; //In order to change this, remember to change the
                            //value in CarStatus::setTelemetry too

        //console.log("-----> SELECT TELEMETRY INDEX" + index);

        telemetryRepeater.itemAt(index).selected = 1;
        telemetrySelectedIndex = index;
    }

    function setTelemetry(index) {
      telemetryRepeater.itemAt(index).state = (telemetryRepeater.itemAt(index).state + 1) % 3;
      //console.log(telemetryRepeater.itemAt(index).state);
    }

    function btnClickedHandler(btnID) {
        if (btnID == 0) {
           if (tabView.stepIntoTab) {
              mainwindow.canSwitchPage = true;
              tabView.stepIntoTab = false;
              unSelectTelemetry();
           }
        }

        //Change status of the selected item
        if (btnID == 1) {
          if(tabView.stepIntoTab) {
            //If status of the selected item changed then change qml interface too             
            if(CarStatus.setTelemetry(telemetrySelectedIndex)){
              setTelemetry(telemetrySelectedIndex);           
            }
          }            
        }           
        
        if (btnID == 2) {
           // Step into this tab and change the behaviour of btnID
           if (!tabView.stepIntoTab) {
              // Set the button clickable
              btnClickable = true;

              // Select the first entry of the SensorsList
              selectTelemetry(0);
              // Prevent the button 0 to switch to Racing Page!
              tabView.stepIntoTab = true;
              mainwindow.canSwitchPage = false;

           } else {
              // Loop through sensors
              selectTelemetry(telemetrySelectedIndex + 1);
           }
        }

        //Enable/Disable sendTelemetry
        if (btnID == 3){
           CAN.asktelemetry();           
        }
    }

    GridLayout{
        id: grid
        columns: 4
        rows: 4         
        columnSpacing: 2
        rowSpacing: 1
        width: parent.width
        height: parent.height - 5
        anchors.top: parent.top
        
          Repeater{
              id: telemetryRepeater
              model: telemetryLeds
              delegate: TelemetryStatusLED {
                  text: modelData[0]
                  state: modelData[1]
                  selected: 0
                  height: parent.height/3
                  width: parent.width/4
              }
          }
        
    }
}