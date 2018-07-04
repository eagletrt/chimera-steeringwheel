import QtQuick 2.7

Rectangle {

   FontLoader {id:blackops; source: "lib/blops.ttf"}

   property int hvTemp: CAN.hvTemp;
   property int hvVolt: CAN.hvVolt;
   property int lvTemp: CAN.lvTemp;
   property int lvVolt: CAN.lvVolt;

   property int velocity: CarStatus.velocity

   color: "transparent"

   Text {
      id: texthvTemp
      text: CAN.hvTemp +  " °C"
      font.family: blackops.name;
      font.pointSize: 7
      y: 100
      color: "white"
   }

   Text {
      id: texthvVolt
      text: CAN.hvVolt +  " V"
      font.family: blackops.name;
      font.pointSize: 7
      y: 120
      color: "white"
   }

   Text {
      id: textlvTemp
      text: CAN.lvTemp + " °C"

      horizontalAlignment: Text.AlignRight;
      font.pointSize: 7
      font.family: blackops.name;
      x: 290
      y: 100
      width: 70
      color: "white"
   }

   Text {
      id: textlvVolt
      text: CAN.lvVolt + " V"
      horizontalAlignment: Text.AlignRight;
      font.pointSize: 7
      font.family: blackops.name;
      x: 290
      y: 120
      width: 70
      color: "white"
   }

   Item{
      property var throttleVal: CAN.throttleVal;
      property int throttleValore: throttleVal;

      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: -125
      anchors.horizontalCenterOffset: -162

      onThrottleValChanged: function(){
         throttleValore = CAN.throttleVal;
         console.log("Throttle Changed: " + throttleValore);
         switch (throttleValore){
            case 0:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 0;
               t5.opacity = 0;
               t4.opacity = 0;
               t3.opacity = 0;
               t2.opacity = 0;
               t1.opacity = 0;
               break;
            case 1:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 0;
               t5.opacity = 0;
               t4.opacity = 0;
               t3.opacity = 0;
               t2.opacity = 0;
               t1.opacity = 1;
               break;
            case 2:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               b6.opacity = 0;
               t5.opacity = 0;
               t4.opacity = 0;
               t3.opacity = 0;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 3:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 0;
               t5.opacity = 0;
               t4.opacity = 0;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 4:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 0;
               t5.opacity = 0;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 5:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 0;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 6:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 0;
               t6.opacity = 1;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 7:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 0;
               t7.opacity = 1;
               t6.opacity = 1;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 8:
               t10.opacity = 0;
               t9.opacity = 0;
               t8.opacity = 1;
               t7.opacity = 1;
               t6.opacity = 1;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 9:
               t10.opacity = 0;
               t9.opacity = 1;
               t8.opacity = 1;
               t7.opacity = 1;
               t6.opacity = 1;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
            case 10:
               t10.opacity = 1;
               t9.opacity = 1;
               t8.opacity = 1;
               t7.opacity = 1;
               t6.opacity = 1;
               t5.opacity = 1;
               t4.opacity = 1;
               t3.opacity = 1;
               t2.opacity = 1;
               t1.opacity = 1;
               break;
         }
      }

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
      font.pointSize: 35
      font.family: blackops.name;
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: -5
      color: "white"
   }

   Text {
      text: "kw"
      font.family: blackops.name;
      font.pointSize: 5
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: 37
      color: "white"
   }

   Item{
      property var brakeVal: CAN.brakeVal;
      property int brakeValore: brakeVal;

      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
      anchors.verticalCenterOffset: -109
      anchors.horizontalCenterOffset: -206

      onBrakeValChanged: function(){
         brakeValore = CAN.brakeVal;
         console.log("Brake Changed: " + brakeValore);
         switch (brakeValore){
            case 0:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 0;
               b4.opacity = 0;
               b3.opacity = 0;
               b2.opacity = 0;
               b1.opacity = 0;
               break;
            case 1:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 0;
               b4.opacity = 0;
               b3.opacity = 0;
               b2.opacity = 0;
               b1.opacity = 1;
               break;
            case 2:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 0;
               b4.opacity = 0;
               b3.opacity = 0;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 3:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 0;
               b4.opacity = 0;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 4:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 0;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 5:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 0;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 6:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 0;
               b6.opacity = 1;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 7:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 0;
               b7.opacity = 1;
               b6.opacity = 1;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 8:
               b10.opacity = 0;
               b9.opacity = 0;
               b8.opacity = 1;
               b7.opacity = 1;
               b6.opacity = 1;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 9:
               b10.opacity = 0;
               b9.opacity = 1;
               b8.opacity = 1;
               b7.opacity = 1;
               b6.opacity = 1;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
            case 10:
               b10.opacity = 1;
               b9.opacity = 1;
               b8.opacity = 1;
               b7.opacity = 1;
               b6.opacity = 1;
               b5.opacity = 1;
               b4.opacity = 1;
               b3.opacity = 1;
               b2.opacity = 1;
               b1.opacity = 1;
               break;
         }
      }

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
