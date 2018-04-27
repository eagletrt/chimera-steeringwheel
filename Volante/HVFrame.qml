import QtQuick 2.0

Item{

property var hvVolt : CAN.hvVolt;
property int hvVal : (hvVolt * 12 / 120) + 0.5 + 2;

onHvVoltChanged: function(){
  switch (hvVal){
    case 14:
      break;
    case 13:
      hv14.opacity = 0;
      break;
    case 12:
      hv14.opacity = 0;
      hv13.opacity = 0;
      break;
    case 11:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      break;
    case 10:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      break;
    case 9:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      break;
    case 8:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      break;
    case 7:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      break;
    case 6:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      hv7.opacity = 0;
      break;
    case 5:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      hv7.opacity = 0;
      hv6.opacity = 0;
      break;
    case 4:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      hv7.opacity = 0;
      hv6.opacity = 0;
      hv5.opacity = 0;
      break;
    case 3:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      hv7.opacity = 0;
      hv6.opacity = 0;
      hv5.opacity = 0;
      hv4.opacity = 0;
      break;
    case 2:
      hv14.opacity = 0;
      hv13.opacity = 0;
      hv12.opacity = 0;
      hv11.opacity = 0;
      hv10.opacity = 0;
      hv9.opacity = 0;
      hv8.opacity = 0;
      hv7.opacity = 0;
      hv6.opacity = 0;
      hv5.opacity = 0;
      hv4.opacity = 0;
      hv3.opacity = 0;
      break;
  }
}

  Image {
    id: hv
    source: "img/HV.png"
    opacity: 1
  }

  Image {
  	id: hv1
  	objectName: "hv1"
  	source: "img/hv1.png"
  	opacity: 1
	}

	Image {
  	id: hv2
  	objectName: "hv2"
  	source: "img/hv2.png"
  	opacity: 1
	}

	Image {
  	id: hv3
  	objectName: "hv3"
  	source: "img/hv3.png"
  	opacity: 1
	}

	Image {
  	id: hv4
  	objectName: "hv4"
  	source: "img/hv4.png"
  	opacity: 1
	}

	Image {
  	id: hv5
  	objectName: "hv5"
  	source: "img/hv5.png"
  	opacity: 1
	}

	Image {
  	id: hv6
  	objectName: "hv6"
  	source: "img/hv6.png"
  	opacity: 1
	}

	Image {
  	id: hv7
  	objectName: "hv7"
  	source: "img/hv7.png"
  	opacity: 1
	}

	Image {
  	id: hv8
  	objectName: "hv8"
  	source: "img/hv8.png"
  	opacity: 1
	}

	Image {
  	id: hv9
  	objectName: "hv9"
  	source: "img/hv9.png"
  	opacity: 1
	}

	Image {
  	id: hv10
  	objectName: "hv10"
  	source: "img/hv10.png"
  	opacity: 1
	}

	Image {
  	id: hv11
  	objectName: "hv11"
  	source: "img/hv11.png"
  	opacity: 1
	}

	Image {
  	id: hv12
  	objectName: "hv12"
  	source: "img/hv12.png"
  	opacity: 1
	}

	Image {
  	id: hv13
  	objectName: "hv13"
  	source: "img/hv13.png"
  	opacity: 1
	}

	Image {
  	id: hv14
  	objectName: "hv14"
  	source: "img/hv14.png"
  	opacity: 1
	}

}
