import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: menu
    color: "#000000"

    signal btnPressed(int btnID)
    signal btnReleased(int btnID)
    signal btnClicked(int btnID)


    function connect() {
        console.log("Connetto! Menu");
        mainwindow.btnPressed.connect(btnPressedHandler);
        mainwindow.btnReleased.connect(btnReleasedHandler);
        mainwindow.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
        console.log("Disconnetto! Menu");
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

    TabView {
        id: tabView
        anchors.fill: parent
        tabPosition: Qt.BottomEdge
        property var stepIntoTab: false

        Connections {
            target: menu
            onBtnClicked: {
                if (btnID == 0) {
                    //console.log("Cliccato btn 1");
                    if (!tabView.stepIntoTab) {
                        if (tabView.getTab(tabView.currentIndex).children[0].disconnect) {
                            tabView.getTab(tabView.currentIndex).children[0].disconnect();
                        }

                        if (tabView.currentIndex == 5) {
                            tabView.currentIndex = 0;
                        } else {
                            tabView.currentIndex++;
                        }

                       if (tabView.getTab(tabView.currentIndex).children[0].connect) {
                            tabView.getTab(tabView.currentIndex).children[0].connect();
                       }
                    }
                }
/*
                if (btnID == 1) {
                    if (!tabView.stepIntoTab) {
                        mainwindow.changePage();
                    }
                }
*/
            }
        }

        Tab {
            //title: "Status"
            TabStatus {
            }
       }

        Tab {
            //title: "Inverter"
            TabInverter {
            }
        }

        Tab {
            //title: "Racing"
            RacingPage {
            }
        }

        Tab {
            //title: "Errors"
			      TabErrors {
			      }
        }

        Tab {
            //title: "Sensors"
            TabSensors {

            }
        }

        Tab {
            //title: "Battery"
            TabBattery {
            }
        }

        style: TabViewStyle {
            frameOverlap: 0
            tab: Rectangle {
                color: styleData.selected ? "yellow" : "blue"
                border.color:  "black"
                border.width: 1
                implicitWidth: tabView.width/6
                implicitHeight:  7//menu.height/6
                y: 0
                Text {
                    id: text
                    font.family: "Stencil"
                    font.pointSize: 10
                    anchors.centerIn: parent
                    text: styleData.title
                    color: "black"//styleData.selected ? "white" : "black"
                }
            }
        }

    }
}
