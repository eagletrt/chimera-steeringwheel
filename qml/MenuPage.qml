import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Rectangle {
  id: menu
  color: "#000000"
  property var steeringWheelPopup: CarStatus.SteeringWheelPopup;
  property var animationDuration: 2500;
  signal btnPressed(int btnID)
  signal btnReleased(int btnID)
  signal btnClicked(int btnID)

  FontLoader {id:blackops; source: "../lib/blops.ttf"}


  function connect() {
    mainwindow.btnPressed.connect(btnPressedHandler);
    mainwindow.btnReleased.connect(btnReleasedHandler);
    mainwindow.btnClicked.connect(btnClickedHandler);
  }

  function disconnect() {
    mainwindow.btnPressed.disconnect(btnPressedHandler);
    mainwindow.btnReleased.disconnect(btnReleasedHandler);
    mainwindow.btnClicked.disconnect(btnClickedHandler);

    // Disconnect current tab, prevent erroneous btn click handling
    var currentTab = tabView.getTab(0);

    if (currentTab && currentTab.children[0].disconnect) {
      currentTab.children[0].disconnect();
    }
  }

  function btnPressedHandler(btnID) {
    menu.btnPressed(btnID);
  }

  function btnReleasedHandler(btnID) {
    menu.btnReleased(btnID);
  }

  function btnClickedHandler(btnID) {
    menu.btnClicked(btnID);
  }

  onSteeringWheelPopupChanged: {
    popup.visible = true;
    tabView.visible = false;
    popupAnimation.start(); 
  }

  ParallelAnimation {
         id: popupAnimation
         running: false
         PropertyAnimation {
            target: popup; 
            properties: "visible"; 
            from: true;
            to: false; 
            duration: animationDuration
         }
         PropertyAnimation {
            target: tabView; 
            properties: "visible"; 
            from: false;
            to: true; 
            duration: animationDuration
         }
    }


  //This will popup messages over the Tabview
  Rectangle {
    id: popup
    anchors.fill: parent
    color: "transparent"
    visible: false

    Text {
      text: qsTr(steeringWheelPopup)
      anchors.centerIn: parent
      font.family: blackops.name
      font.pointSize: 20
      color: "#ffffff"
    }
  }

  TabView {
    id: tabView
    anchors.fill: parent
    tabPosition: Qt.BottomEdge
    property var stepIntoTab: false
    visible: true

    Connections {
      target: menu
      onBtnClicked: {
        if (btnID == 4 && !popup.visible) {
          if (!tabView.stepIntoTab) {
            if (tabView.getTab(tabView.currentIndex).children[0].disconnect) {
              tabView.getTab(tabView.currentIndex).children[0].disconnect();
            }

            if (tabView.currentIndex == 0) {
              tabView.currentIndex = 6;
            } else {
              tabView.currentIndex--;
            }

            if (tabView.getTab(tabView.currentIndex).children[0].connect) {
              tabView.getTab(tabView.currentIndex).children[0].connect();
            }
          }
        }
        if (btnID == 5 && !popup.visible) {
          if (!tabView.stepIntoTab) {
            if (tabView.getTab(tabView.currentIndex).children[0].disconnect) {
              tabView.getTab(tabView.currentIndex).children[0].disconnect();
            }

            if (tabView.currentIndex == 6) {
              tabView.currentIndex = 0;
            } else {
              tabView.currentIndex++;
            }

            if (tabView.getTab(tabView.currentIndex).children[0].connect) {
              tabView.getTab(tabView.currentIndex).children[0].connect();
            }
          }
        }
      }
    }

    Tab {
      TabErrors {
      }
    }
    Tab {
      TabStatus {
      }
    }
    Tab {
      TabSensors {
      }
    }
    Tab {
      TabInverter {
      }
    }
   Tab {
      RacingPage {
      }
    }
    Tab {
      TabBattery {
      }
    }
    Tab{
      TabTelemetry{
      }
    }
    
    style: TabViewStyle {
      frameOverlap: 0
      tab: Rectangle {
        color: styleData.selected ? "lightgray" : "black" //#2266FF
        border.color: styleData.selected ? "black" : "lightgray"
        border.width:  0.5
        implicitWidth: tabView.width/7
        implicitHeight:  5
        y: 0
        Text {
          id: text
          font.pointSize: 5
          anchors.centerIn: parent
          text: styleData.title
          color: "black"
        }
      }
    }
  }
}
