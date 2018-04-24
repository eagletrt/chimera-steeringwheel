import QtQuick 2.0

Item{

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
