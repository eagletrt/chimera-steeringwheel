import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id: root
    anchors.fill: parent
    color: "#000000"

    property var telemetrySelectedIndex: -1
    property var btnClickable: false
    property var telemetrystatus: CarStatus.TelemetryStatus
    
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
      if(telemetryRepeater.itemAt(index).state == 2){
         telemetryRepeater.itemAt(index).state = 0;
      }else{
         telemetryRepeater.itemAt(index).state == 0 ? telemetryRepeater.itemAt(index).state = 1 : telemetryRepeater.itemAt(index).state = 0;
      }      
      //console.log(telemetryRepeater.itemAt(index).state);
    }

    onTelemetrystatusChanged: {
      var newTelemetryStatus = telemetryLeds;

      newTelemetryStatus[0] [1] = telemetrystatus[0] 
      newTelemetryStatus[1] [1] = telemetrystatus[1] 
      newTelemetryStatus[2] [1] = telemetrystatus[2] 
      newTelemetryStatus[3] [1] = telemetrystatus[3] 
      newTelemetryStatus[4] [1] = telemetrystatus[4] 
      newTelemetryStatus[5] [1] = telemetrystatus[5] 
      newTelemetryStatus[6] [1] = telemetrystatus[6] 
      newTelemetryStatus[7] [1] = telemetrystatus[7] 
      newTelemetryStatus[8] [1] = telemetrystatus[8] 
      newTelemetryStatus[9] [1] = telemetrystatus[9] 
      newTelemetryStatus[10][1] = telemetrystatus[10]

      telemetryLeds = newTelemetryStatus;
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

    property var telemetryLeds: [ //0 OFFLINE, 1 ONLINE, 2 DEFAULT
    ["HV"   , '2'],
    ["LV"   , '2'],
    ["GPS"  , '2'],
    ["IMUGY", '2'],
    ["IMUAX", '2'],
    ["FRNTW", '2'],
    ["STR"  , '2'],
    ["THR"  , '2'],
    ["BRK"  , '2'],
    ["DB"   , '2'],
    ["MQTT" , '2']
    ] 

    Grid{
        id: grid
        columns: 4
        rows: 3       
        columnSpacing: 2
        rowSpacing: 1
        width: parent.width
        height: parent.height - 5
        anchors.top: parent.top
        
          Repeater{
              id: telemetryRepeater
              model: telemetryLeds
              TelemetryStatusLED {
                  text: modelData[0]
                  state: modelData[1]
                  selected: 0
                  height: parent.height/3
                  width: parent.width/4
              }
          }
        
    }
}