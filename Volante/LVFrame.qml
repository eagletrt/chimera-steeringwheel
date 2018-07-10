import QtQuick 2.0

Item{
   //valore da 0 a 100
   property var lvVolt : CAN.lvVolt;
   property int lvVal : lvVolt;

   onLvVoltChanged: function(){
      if(lvVal<10){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 0;
         lv8.opacity = 0;
         lv7.opacity = 0;
         lv6.opacity = 0;
         lv5.opacity = 0;
         lv4.opacity = 0;
         lv3.opacity = 0;
         lv2.opacity = 1;
      }else if(lvVal>=10 && lvVal<20){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 0;
         lv8.opacity = 0;
         lv7.opacity = 0;
         lv6.opacity = 0;
         lv5.opacity = 0;
         lv4.opacity = 0;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=20 && lvVal<30){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 0;
         lv8.opacity = 0;
         lv7.opacity = 0;
         lv6.opacity = 0;
         lv5.opacity = 0;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=30 && lvVal<40){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 0;
         lv8.opacity = 0;
         lv7.opacity = 0;
         lv6.opacity = 0;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=40 && lvVal<50){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 0;
         lv8.opacity = 0;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=50 && lvVal<60){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 0;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=60 && lvVal<70){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 0;
         lv10.opacity = 1;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=70 && lvVal<80){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 0;
         lv11.opacity = 1;
         lv10.opacity = 1;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=80 && lvVal<90){
         lv14.opacity = 0;
         lv13.opacity = 0;
         lv12.opacity = 1;
         lv11.opacity = 1;
         lv10.opacity = 1;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=90 && lvVal<100){
         lv14.opacity = 0;
         lv13.opacity = 1;
         lv12.opacity = 1;
         lv11.opacity = 1;
         lv10.opacity = 1;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }else if(lvVal>=100){
         lv14.opacity = 1;
         lv13.opacity = 1;
         lv12.opacity = 1;
         lv11.opacity = 1;
         lv10.opacity = 1;
         lv9.opacity = 1;
         lv8.opacity = 1;
         lv7.opacity = 1;
         lv6.opacity = 1;
         lv5.opacity = 1;
         lv4.opacity = 1;
         lv3.opacity = 1;
         lv2.opacity = 1;
      }
   }

Image {
   id: lv
   source: "img/LV.png"
   opacity: 1
}

Image {
   id: lv0
   objectName: "lv0"
   source: "img/lv0.png"
   opacity: 1
}

Image {
   id: lv1
   objectName: "lv1"
   source: "img/lv1.png"
   opacity: 1
}

Image {
   id: lv2
   objectName: "lv2"
   source: "img/lv2.png"
   opacity: 1
}

Image {
   id: lv3
   objectName: "lv3"
   source: "img/lv3.png"
   opacity: 1
}

Image {
   id: lv4
   objectName: "lv4"
   source: "img/lv4.png"
   opacity: 1
}

Image {
   id: lv5
   objectName: "lv5"
   source: "img/lv5.png"
   opacity: 1
}

Image {
   id: lv6
   objectName: "lv6"
   source: "img/lv6.png"
   opacity: 1
}

Image {
   id: lv7
   objectName: "lv7"
   source: "img/lv7.png"
   opacity: 1
}

Image {
   id: lv8
   objectName: "lv8"
   source: "img/lv8.png"
   opacity: 1
}

Image {
   id: lv9
   objectName: "lv9"
   source: "img/lv9.png"
   opacity: 1
}

Image {
   id: lv10
   objectName: "lv10"
   source: "img/lv10.png"
   opacity: 1
}

Image {
   id: lv11
   objectName: "lv11"
   source: "img/lv11.png"
   opacity: 1
}

Image {
   id: lv12
   objectName: "lv12"
   source: "img/lv12.png"
   opacity: 1
}

Image {
   id: lv13
   objectName: "lv13"
   source: "img/lv13.png"
   opacity: 1
}

Image {
   id: lv14
   objectName: "lv14"
   source: "img/lv14.png"
   opacity: 1
}

}
