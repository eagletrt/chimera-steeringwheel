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
            mtext: qsTr("hv")
            mindex:0
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("lv")
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
            mtext: qsTr("imugy")
            mindex:3
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("imuax")
            mindex:4
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("frntw")
            mindex:5
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("str")
            mindex:6
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("thr")
            mindex:7
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("brk")
            mindex:8
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("DB")
            mindex:9
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("mqtt")
            mindex:10
            mselected: 0
            mactivated: 0
        }
        ListElement{
            mtext: qsTr("")
            mindex:11
            mselected: 0
            mactivated: 0
        }
    }
}
