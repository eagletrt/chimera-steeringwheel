import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
  width: 480
  height: 272
  color: "black"
  id: border

  Text {
      id: mainTime
      x:175
      y:15
      font.pointSize: 22
      text: "00:00:00"
      color: "white"
  }

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
    Image {
      id: hv
      source: "img/HV.png"
      opacity: 1
    }
    Image {
      id: lv
      source: "img/LV.png"
      opacity: 1
    }
  }
  Rectangle {
      width: 370
      height: 220
      x: 55
      y: 52

      id: mainwindow

      property var itemOnTop: 1;
      property var canSwitchPage: true

      // Buttons signals
      signal btnPressed(int btnID)
      signal btnReleased(int btnID)
      signal btnClicked(int btnID)

      // CAN Signals
      signal carStatusChanged(int statusID)
      signal presetChanged(int presetID)
      signal controlStateChanged(int ctrlIsEnabled, int ctrlIsOn, int warning, int error);
      signal hvStatusChanged(int invRight, int invLeft, int preCharge)

      function changePage() {
          if (canSwitchPage) {
              if (itemOnTop == 1) {
                  /*Cazzo mene io non switcho
                  stack.push(page2);
                  itemOnTop = 2;
                  */
              } else {
                  stack.push(page1);
                  itemOnTop = 1;
              }
          }
      }

      Connections {
          target: Buttons
          onBtnClicked: {
              mainwindow.btnClicked(btnID);
          }
          onBtnPressed: {
              mainwindow.btnPressed(btnID);
          }
          onBtnReleased: {
              mainwindow.btnReleased(btnID);
          }
      }

      Connections {
          target: CarStatus
          onCarStatusChanged: {
              mainwindow.carStatusChanged(statusID);
          }
          onExecModeChanged: {
              mainwindow.controlStateChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
          }
      }

      StackView {
          anchors.fill: parent
          id: stack

          property Item previusItem

          Component.onCompleted: {
              this.push(page1);
              //mainwindow.btnClicked.connect(changePage)
          }

          onCurrentItemChanged: {
              if (previusItem) {
                  if (previusItem.disconnect) {
                      previusItem.disconnect();
                  }
              }

              if (currentItem.connect) {
                  currentItem.connect();
              }

              previusItem = currentItem;
          }

          Component {
              id: page1
              MenuPage {
              }
          }
      }
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

	Image {
	id: hv15
	objectName: "hv15"
	source: "img/hv15.png"
	opacity: 0
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

	Image {
	id: lv15
	objectName: "lv15"
	source: "img/lv15.png"
	opacity: 0
	}

}
