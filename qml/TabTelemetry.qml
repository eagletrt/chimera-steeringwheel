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
    //I used number instead of strings in order to make a more readable code
    property var ledStates: ['0', '1', '2'] //OFFLINE, ONLINE, DEFAULT
    property var telemetryLeds: [
    ["HV", '2'],
    ["LV", '2'],
    ["GPS", '2'],
    ["IMUGY", '2'],
    ["IMUAX", '2'],
    ["FRNTW", '2'],
    ["STR", '2'],
    ["THR", '2'],
    ["BRK", '2'],
    ["DB", '2'],
    ["MQTT", '2']
    ] 
   
    onTelemetrystatusChanged: {
      // console.log("Cambiato lo stato di Telemetry da CAN");
      var newTelemetryLeds = telemetryLeds;

      for (var i=0; i < telemetrystatus.length; i++) {
         newTelemetryLeds[i][1] = ledStates[telemetrystatus[i]];
      }

      telemetryLeds = newTelemetryLeds;
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
        if (telemetrySelectedIndex != -1) {
            telemetryRepeater.itemAt(telemetrySelectedIndex).selected = 0;
        }

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

        if (btnID == 1) {
          if(tabView.stepIntoTab) {
            //console.log(telemetrySelectedIndex);            
            if(CarStatus.setTelemetry(telemetrySelectedIndex)){
              setTelemetry(telemetrySelectedIndex);
              //console.log("Settata " + telemetrySelectedIndex);              
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
    }

    GridLayout{
        id: grid
        columns: 4
        rows: 4         
        columnSpacing: 2
        rowSpacing: 1
        anchors.fill: parent
        
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