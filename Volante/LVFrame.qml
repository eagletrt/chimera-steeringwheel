import QtQuick 2.0

Item{

property var lvVolt : CAN.lvVolt;
property int lvVal : (lvVolt * 12 / 120) + 0.5 + 2;

onLvVoltChanged: function(){
  switch (lvVal){
    case 14:
      break;
    case 13:
      lv14.opacity = 0;
      break;
    case 12:
      lv14.opacity = 0;
      lv13.opacity = 0;
      break;
    case 11:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      break;
    case 10:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      break;
    case 9:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      lv10.opacity = 0;
      break;
    case 8:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      lv10.opacity = 0;
      lv9.opacity = 0;
      break;
    case 7:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      lv10.opacity = 0;
      lv9.opacity = 0;
      lv8.opacity = 0;
      break;
    case 6:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      lv10.opacity = 0;
      lv9.opacity = 0;
      lv8.opacity = 0;
      lv7.opacity = 0;
      break;
    case 5:
      lv14.opacity = 0;
      lv13.opacity = 0;
      lv12.opacity = 0;
      lv11.opacity = 0;
      lv10.opacity = 0;
      lv9.opacity = 0;
      lv8.opacity = 0;
      lv7.opacity = 0;
      lv6.opacity = 0;
      break;
    case 4:
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
      break;
    case 3:
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
      break;
    case 2:
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
      break;
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
