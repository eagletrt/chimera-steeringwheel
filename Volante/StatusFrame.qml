import QtQuick 2.0

Item{

  //mainwindow.carStatusChanged.connect(carStatusChangedHandler);

  signal carStatusChanged(int statusID)


  function carStatusChangedHandler(statusID) {
    console.log("Car Status Changed: " + statusID);
    switch (statusID){
      case 0:
        idle.opacity = 1;
        run.opacity = 0;
        break;
      case 1:
        idle.opacity = 0;
        run.opacity = 1
        break;
      case 2: //vanno ancora impostati per la radio, non c'è il val
        radio.opacity = 1;
        radio_na.opacity = 0;
        break;
      case 4:
        radio.opacity = 0;
        radio_na.opacity = 1;
        break;
      }
  }

  Image {
    id: idle
    objectName: "idle"
    source: "img/idle.png"
    opacity: 1
  }

  Image {
    id: run
    objectName: "run"
    source: "img/run.png"
    opacity: 0
  }

  Image {
    id: radio
    objectName: "radio"
    source: "img/radio.png"
    opacity: 0
  }

  Image {
    id: radio_na
    objectName: "radio_na"
    source: "img/radio_na.png"
    opacity: 1
  }

}
