import QtQuick 2.7

Rectangle {

    property int hvTemp: CAN.hvTemp;
    property int hvVolt: CAN.hvVolt;
    property int lvTemp: CAN.lvTemp;
    property int lvVolt: CAN.lvVolt;

    property int velocity: CarStatus.velocity

    color: "transparent"

    Text {
        id: texthvTemp
        text: CAN.hvTemp +  " °C"
        font.pointSize: 12
        y: 40
        color: "white"
    }

    Text {
        id: texthvVolt
        text: CAN.hvVolt +  " V"
        font.pointSize: 12
        y: 60
        color: "white"
    }

    Text {
        id: textlvTemp
        text: CAN.lvTemp + " °C"
        font.pointSize: 12
        x: 327
        y: 40
        color: "white"
    }

    Text {
        id: textlvVolt
        text: CAN.lvVolt + " V"
        font.pointSize: 12
        x: 327
        y: 60
        color: "white"
    }

    Item{

      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: -125
      anchors.horizontalCenterOffset: -162

      Image {
        id: t1
        objectName: "t1"
        source: "img/t1.png"
        opacity: 1
      }

      Image {
        id: t2
        objectName: "t2"
        source: "img/t2.png"
        opacity: 1
      }

      Image {
        id: t3
        objectName: "t3"
        source: "img/t3.png"
        opacity: 1
      }

      Image {
        id: t4
        objectName: "t4"
        source: "img/t4.png"
        opacity: 1
      }

      Image {
        id: t5
        objectName: "t5"
        source: "img/t5.png"
        opacity: 1
      }

      Image {
        id: t6
        objectName: "t6"
        source: "img/t6.png"
        opacity: 1
      }

      Image {
        id: t7
        objectName: "t7"
        source: "img/t7.png"
        opacity: 1
      }

      Image {
        id: t8
        objectName: "t8"
        source: "img/t8.png"
        opacity: 1
      }

      Image {
        id: t9
        objectName: "t9"
        source: "img/t9.png"
        opacity: 1
      }

      Image {
        id: t10
        objectName: "t10"
        source: "img/t10.png"
        opacity: 1
      }

    }

    Text {
        id: textVelocity
        text: velocity
        font.pointSize: 70
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -5
        color: "white"
    }

    Text {
        text: "kmh"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 40
        color: "white"
    }

    Item{
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: -109
      anchors.horizontalCenterOffset: -206


      Image {
        id: b1
        objectName: "b1"
        source: "img/b1.png"
        opacity: 1
      }

      Image {
        id: b2
        objectName: "b2"
        source: "img/b2.png"
        opacity: 1
      }

      Image {
        id: b3
        objectName: "b3"
        source: "img/b3.png"
        opacity: 1
      }

      Image {
        id: b4
        objectName: "b4"
        source: "img/b4.png"
        opacity: 1
      }

      Image {
        id: b5
        objectName: "b5"
        source: "img/b5.png"
        opacity: 1
      }

      Image {
        id: b6
        objectName: "b6"
        source: "img/b6.png"
        opacity: 1
      }

      Image {
        id: b7
        objectName: "b7"
        source: "img/b7.png"
        opacity: 1
      }

      Image {
        id: b8
        objectName: "b8"
        source: "img/b8.png"
        opacity: 1
      }

      Image {
        id: b9
        objectName: "b9"
        source: "img/b9.png"
        opacity: 1
      }

      Image {
        id: b10
        objectName: "b10"
        source: "img/b10.png"
        opacity: 1
      }

    }
}
