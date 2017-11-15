import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: sensori
    color: "#000000"
    anchors.fill: parent

    function connect() {
        console.log("Tab connessa - Sensors");
    }

    function disconnect() {
        console.log("Tab disconnessa - Sensors");
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
                    width: 0
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "green"

                    Component.onCompleted: {
                        forceActiveFocus()
                    }

                    Keys.onPressed: {
                        if (event.key == Qt.Key_Z){
                            acceleratore.width = apps.width-2
                        }
                    }

                    Keys.onReleased: {
                        if (event.key == Qt.Key_Z){
                            acceleratore.width = 0
                        }
                    }

                    Behavior on width {
                        NumberAnimation{
                            duration: 500
                            easing.type: Easing.Linear
                            easing.amplitude: 1000
                        }
                    }
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

                Rectangle {
                    id: errorApps1
                    width: errorsApps.width/8
                    height: errorApps1.width
                    color: "lightgray"
                    radius: errorApps1.width/2
                }

                Rectangle {
                    id: errorApps2
                    width: errorApps1.width
                    height: errorApps2.width
                    color: "lightgray"
                    radius: errorApps2.width/2
                }

                Rectangle {
                    id: errorApps3
                    width: errorApps1.width
                    height: errorApps3.width
                    color: "lightgray"
                    radius: errorApps3.width/2
                }

                Rectangle {
                    id: errorApps4
                    width: errorApps1.width
                    height: errorApps4.width
                    color: "lightgray"
                    radius: errorApps4.width/2
                }

                Rectangle {
                    id: errorApps5
                    width: errorApps1.width
                    height: errorApps5.width
                    color: "lightgray"
                    radius: errorApps5.width/2
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
                    width: 0
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: "red"

                    Component.onCompleted: {
                        forceActiveFocus()
                    }

                    Keys.onPressed: {
                        if (event.key == Qt.Key_X){
                            freno.width = bse.width-2
                        }
                    }

                    Keys.onReleased: {
                        if (event.key == Qt.Key_X){
                            freno.width = 0
                        }
                    }

                    Behavior on width {
                        NumberAnimation{
                            duration: 250
                            easing.type: Easing.Linear
                            easing.amplitude: 1000
                        }
                    }
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

                Rectangle {
                    id: errorBse1
                    width: errorsBse.width/8
                    height: errorBse1.width
                    color: "lightgray"
                    radius: errorBse1.width/2
                }

                Rectangle {
                    id: errorBse2
                    width: errorBse1.width
                    height: errorBse2.width
                    color: "lightgray"
                    radius: errorBse2.width/2
                }

                Rectangle {
                    id: errorBse3
                    width: errorBse1.width
                    height: errorBse3.width
                    color: "lightgray"
                    radius: errorBse3.width/2
                }

                Rectangle {
                    id: errorBse4
                    width: errorBse1.width
                    height: errorBse4.width
                    color: "lightgray"
                    radius: errorBse4.width/2
                }

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

                    Component.onCompleted: {
                        forceActiveFocus()
                    }

                    Keys.onPressed: {
                        if (event.key == Qt.Key_D){
                            sterzoDx.width = steerDx.width-1
                        }
                    }

                    Keys.onReleased: {
                        if (event.key == Qt.Key_D){
                            sterzoDx.width = 0
                        }
                    }

                    Behavior on width {
                        NumberAnimation{
                            duration: 250
                            easing.type: Easing.Linear
                            easing.amplitude: 1000
                        }
                    }
                }
            }

            Rectangle {
                id: steerSx
                width: parent.width/2
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

                    Component.onCompleted: {
                        forceActiveFocus()
                    }

                    Keys.onPressed: {
                        if (event.key == Qt.Key_A){
                            sterzoSx.width = steerSx.width-2
                        }
                    }

                    Keys.onReleased: {
                        if (event.key == Qt.Key_A){
                            sterzoSx.width = 0
                        }
                    }

                    Behavior on width {
                        NumberAnimation{
                            duration: 250
                            easing.type: Easing.Linear
                            easing.amplitude: 1000
                        }
                    }
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

                Rectangle {
                    id: errorSteer1
                    width: errorsSteer.width/8
                    height: errorSteer1.width
                    color: "lightgray"
                    radius: errorSteer1.width/2
                }

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
