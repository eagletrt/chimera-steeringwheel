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
    property var ledStates: ['OFFLINE','ONLINE', 'DEFAULT', 'SELECTED']
    property var telemetryLeds: [
    ["HV", 'DEFAULT'],
    ["LV", 'DEFAULT'],
    ["GPS", 'DEFAULT'],
    ["IMUGY", 'DEFAULT'],
    ["IMUAX", 'DEFAULT'],
    ["FRNTW", 'DEFAULT'],
    ["STR", 'DEFAULT'],
    ["THR", 'DEFAULT'],
    ["BRK", 'DEFAULT'],
    ["DB", 'DEFAULT'],
    ["MQTT", 'DEFAULT']
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
            telemetry.setProperty(telemetrySelectedIndex, "mselected", 0);
        }
    }

    function selectTelemetry(index) {
        if (telemetrySelectedIndex != -1) {
            telemetry.setProperty(telemetrySelectedIndex, "mselected", 0);
        }

        index = index % 12;

        telemetry.setProperty(index, "mselected", 1);
        //console.log("-----> SELECT TELEMETRY INDEX" + index);
        telemetrySelectedIndex = index;
    }

    function setTelemetry(index, value) {
        telemetry.setProperty(index, "mactivated",value);
    }

    function isEnabled(index) {
      return telemetry.get(index).mactivated
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
            if(!isEnabled(telemetrySelectedIndex)) {
              if(CarStatus.setTelemetry(telemetrySelectedIndex,1)){
                setTelemetry(telemetrySelectedIndex,1);
              }
            } else {
              if(CarStatus.setTelemetry(telemetrySelectedIndex,0)){
                setTelemetry(telemetrySelectedIndex,0);
              }
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
            model: telemetryLeds
            delegate: TelemetryStatusLED {
                text: modelData[0]
                state: modelData[1]
                height: parent.height/3
                width: parent.width/4
            }
        }
        
    }    
}
