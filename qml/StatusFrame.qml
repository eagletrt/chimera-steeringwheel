import QtQuick 2.0

Item{
   id: statusframe

   property var carStatus : CarStatus.carStatus;
   property var telemetryenabledstatus: CarStatus.TelemetryEnabledStatus;
   property int statusID: carStatus;

   onCarStatusChanged: function() {
      statusID = CarStatus.carStatus;
      // console.log("Car Status Changed: " + statusID);
      switch (statusID){
         case 0:
            idle.opacity = 1;
            run.opacity = 0;
            setup.opacity = 0;
            stop.opacity = 0;
            break;
         case 1:
            idle.opacity = 0;
            run.opacity = 0;
            setup.opacity = 1;
            stop.opacity = 0;
            break;
         case 2:
            idle.opacity = 0;
            run.opacity = 1;
            setup.opacity = 0;
            stop.opacity = 0;
            break;
         case 3:
            idle.opacity = 0;
            run.opacity = 0;
            setup.opacity = 0;
            stop.opacity = 1;
            break;
      }
   }

   onTelemetryenabledstatusChanged: {  
      switch(telemetryenabledstatus){
         case 0: 
            radio.opacity = 0;
            radio_na = 1;
            break;
         case 1:
            radio.opacity = 1;
            radio_na = 0;
            break;
         case 2:
            console.log("LAMPEGGIA");
            //radio.transitions.star
            
            radio.state = "ACTIVE";
            radio_na.state = "INACTIVE";
            //radio.state = "INACTIVE";
            break;
      }
   }

   Image {
      id: idle
      objectName: "idle"
      source: "../img/idle.png"
      opacity: 1
   }

   Image {
      id: run
      objectName: "run"
      source: "../img/run.png"
      opacity: 0
   }

   Image {
      id: stop
      objectName: "stop"
      source: "../img/stop.png"
      opacity: 0
   }

   Image {
      id: setup
      objectName: "setup"
      source: "../img/setup.png"
      opacity: 0
   }
   Image {
      id: radio
      objectName: "radio"
      source: "../img/radio.png"
      opacity: 0
   }

   Image {
      id: radio_na
      objectName: "radio_na"
      source: "../img/radio_na.png"
      opacity: 1
   }

   states: [
        State {
            name: "ACTIVE"
            PropertyChanges { target: radio; opacity: 1}
            PropertyChanges { target: radio_na; opacity: 1}            
        },
        State {
            name: "INACTIVE"
            PropertyChanges { target: radio; opacity: 0}
            PropertyChanges { target: radio_na; opacity: 0}
        }
   ]
   transitions: [
        Transition {
            from: "ACTIVE"
            to: "INACTIVE"
            ColorAnimation { target: radio; duration: 100}
            ColorAnimation { target: radio_na; duration: 100}
        },
        Transition {
            from: "INACTIVE"
            to: "ACTIVE"
            ColorAnimation { target: radio; duration: 100}
            ColorAnimation { target: radio_na; duration: 100}
        }
   ]

}
