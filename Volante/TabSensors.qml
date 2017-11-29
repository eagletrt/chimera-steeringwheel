import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: sensori
    color: "#000000"
    anchors.fill: parent

    property var appsStatus: CarStatus.APPSStatus
    property var bseStatus: CarStatus.BSEStatus
    property var steerStatus: CarStatus.STEERStatus
    property var ledStates: ['DEFAULT', 'NO'];

    function connect() {
        console.log("Tab connessa - Sensors");
        mainwindow.btnClicked.connect(btnClickedHandler);

        //start 30ms refreshLoop
        CAN.startSensorsUpdate();
    }

    function disconnect() {
        console.log("Tab disconnessa - Sensors");
        mainwindow.btnClicked.disconnect(btnClickedHandler);

        //stop 30ms refreshLoop
        CAN.stopSensorsUpdate();
    }

    onAppsStatusChanged:{
//        console.log("APPS Changed:");
//        console.log(appsStatus);
    }

    onBseStatusChanged:{
//        console.log("BSE Changed:");
//        console.log(bseStatus);
    }

    onSteerStatusChanged:{
//        console.log("STEER Changed:");
//        console.log(steerStatus);
    }

    function bit_test(num, bit){
        return ((num>>bit) % 2 != 0)
    }

    function btnClickedHandler(btnID) {
        //If the car is starded stop requesting data for this tab
        if (btnID == 1) {
            console.log("Pressed 'A' refreshLoop stopped");
            CAN.stopSensorsUpdate();
        }
    }

    GridLayout {
        id: grid4
        width: parent.width-10
        height: parent.height-10
        anchors.centerIn: parent
        columns: 3
        rows: 3
        rowSpacing: 0

        Rectangle {
            id: nameApps
            Layout.preferredWidth: parent.width*1/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Text {
                text: "APPS:"
                font.family: "Stencil"
                font.pointSize: 11
                color: "white"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: barApps
            Layout.preferredWidth: parent.width*3/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Rectangle {
                id: apps
                width: parent.width
                height: parent.height/3
                anchors.centerIn: parent
                border.width: 1
                border.color: "white"
                color: menu.color

                Rectangle {
                    id: acceleratore
                    width: (appsStatus[0] / 100) * (apps.width-2)
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "green"
                }
            }
        }

        Rectangle {
            id: errorsApps
            Layout.preferredWidth: parent.width*4/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Row {
                anchors.centerIn: parent
                spacing: 15

                LED  {
                    id: errorApps1
                    width: errorsApps.width/8
                    height: errorApps1.width
                    state: ledStates[appsStatus[1]]
                }

                LED {
                    id: errorApps2
                    width: errorApps1.width
                    height: errorApps2.width
                    state: ledStates[appsStatus[2]]
                }

                LED {
                    id: errorApps3
                    width: errorApps1.width
                    height: errorApps3.width
                    state: ledStates[appsStatus[3]]
                }

                LED {
                    id: errorApps4
                    width: errorApps1.width
                    height: errorApps4.width
                    state: ledStates[appsStatus[4]]
                }

                LED {
                    id: errorApps5
                    width: errorApps1.width
                    height: errorApps5.width
                    state: ledStates[appsStatus[5]]
                }
            }
        }

        Rectangle {
            id: nameBse
            Layout.preferredWidth: parent.width*1/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Text {
                text: "BSE:"
                font.family: "Stencil"
                font.pointSize: 12
                color: "white"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: barBse
            Layout.preferredWidth: parent.width*3/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Rectangle {
                id: bse
                width: parent.width
                height: parent.height/3
                border.width: 1
                border.color: "white"
                anchors.centerIn: parent
                color: menu.color

                Rectangle {
                    id: freno
                    width: (bseStatus[0] / 100) * (bse.width-2)
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "red"
                }
            }
        }

        Rectangle {
            id: errorsBse
            Layout.preferredWidth: parent.width*4/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Row {
                anchors.centerIn: parent
                spacing: 15

                LED {
                    id: errorBse1
                    width: errorsBse.width/8
                    height: errorBse1.width
                    state: ledStates[bseStatus[1]]
                }

                LED {
                    id: errorBse2
                    width: errorBse1.width
                    height: errorBse2.width
                    state: ledStates[bseStatus[2]]
                }

                LED {
                    id: errorBse3
                    width: errorBse1.width
                    height: errorBse3.width
                    state: ledStates[bseStatus[3]]
                }

                LED {
                    id: errorBse4
                    width: errorBse1.width
                    height: errorBse4.width
                    state: ledStates[bseStatus[4]]
                }

                //placeholder that centers the buttons
                Rectangle {
                    id: errorBse5
                    width: errorBse1.width
                    height: errorBse5.width
                    color: menu.color
                    radius: errorBse5.width/2
                }
            }
        }

        Rectangle {
            id: nameSteer
            Layout.preferredWidth: parent.width*1/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Text {
                id: textStreet
                text: "Steer:"
                font.family: "Stencil"
                font.pointSize: 10
                color: "white"
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: barSteer
            Layout.preferredWidth: parent.width*3/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Rectangle {
                id: steerDx
                width: parent.width
                height: parent.height/3
                border.width: 1
                border.color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: menu.color

                Rectangle {
                    id: sterzoDx
                    width: 0
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color: "blue"
                }
            }

            Rectangle {
                id: steerSx
                width: (steerStatus[0] / 100) * (parent.width)//parent.width/2
                height: parent.height/3
                border.width: 1
                border.color: "white"
                anchors.verticalCenter: parent.verticalCenter
                color: menu.color

                Rectangle {
                    id: sterzoSx
                    width: 0
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "steelblue"
                }
            }
        }

        Rectangle {
            id: errorsSteer
            Layout.preferredWidth: parent.width*4/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: menu.color

            Row {
                anchors.centerIn: parent
                spacing: 15

                LED {
                    id: errorSteer1
                    width: errorsSteer.width/8
                    height: errorSteer1.width
                    state: ledStates[steerStatus[1]]
                }

                //placeholders that center the button
                Rectangle {
                    id: errorSteer2
                    width: errorSteer1.width
                    height: errorSteer2.width
                    color: menu.color
                    radius: errorSteer2.width/2
                }

                Rectangle {
                    id: errorSteer3
                    width: errorSteer1.width
                    height: errorSteer3.width
                    color: menu.color
                    radius: errorSteer3.width/2
                }

                Rectangle {
                    id: errorSteer4
                    width: errorSteer1.width
                    height: errorSteer4.width
                    color: menu.color
                    radius: errorSteer4.width/2
                }

                Rectangle {
                    id: errorSteer5
                    width: errorSteer1.width
                    height: errorSteer5.width
                    color: menu.color
                    radius: errorSteer5.width/2
                }
            }
        }
    }

}
