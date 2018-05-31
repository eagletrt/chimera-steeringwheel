import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
  width: 480
  height: 272
  color: "black"
  id: frame

  Text {
    id: mainTime
    x: 161
    y: 2
    font.pointSize: 26
    text: "00:00:00"
    color: "white"
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
  StatusFrame{

  }

  HVFrame{

  }

  LVFrame{

  }
}
