import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id: root
    anchors.fill: parent
    color: "#000000"

    FontLoader {id:blackops; source: "../lib/blops.ttf"}

    property var telemetrySelectedIndex: -1
    property var btnClickable: false

    function connect() {
       // console.log("Tab connessa - Telemetry");
       menu.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
       // console.log("Tab disconnessa - Telemetry");
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

    function enableTelemetry(index) {
      telemetry.setProperty(index, "mactivated", 1);
      //console.log("Tring activating index: " + index);
      //console.log("activated----> " + isActivated(index))
    }

    function disableTelemetry(index) {
      telemetry.setProperty(index, "mactivated", 0);
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
              if(CarStatus.enableTelemetry(telemetrySelectedIndex)){
                enableTelemetry(telemetrySelectedIndex);
              }
            } else {
              if(CarStatus.disableTelemetry(telemetrySelectedIndex)){
                disableTelemetry(telemetrySelectedIndex);
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

    GridView{
        id: grid
        anchors.fill: parent
        cellWidth: root.width/4
        cellHeight: root.height/3
        model: telemetry
        delegate: TelemetryStatus {
            text: mtext
            index: mindex
            selected: mselected
            activated: mactivated
            height: parent.height/3
            width: parent.width/4
        }
    }

    ListModel{
        id: telemetry

        ListElement{
            mtext: qsTr("bms hv")
            mindex:0
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("bms lv")
            mindex:1
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("gps")
            mindex:2
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("imu gyro")
            mindex:3
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("imu axel")
            mindex:4
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("front w e")
            mindex:5
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("steering w e")
            mindex:6
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("throttle")
            mindex:7
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("brake")
            mindex:8
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("Elemento")
            mindex:9
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("Elemento")
            mindex:10
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("Elemento")
            mindex:11
            mselected: 0
            mactivated: 0
        }
    }
}
