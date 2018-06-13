import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    color: "#000000"
    property var text
    property var selected


    onSelectedChanged: {
        if (root.selected) {
            //root.color = "#dddddd";
            //root.opacity = 0.5
            button.state = "RESET"//START
        } else {
            root.color = "#000000";

            button.state = "NORMAL"
        }
    }

    state: "DEFAULT"

    states: [
        State {
            name: "OK"
            PropertyChanges {
                target: led
                color: "green"
            }
        },
        State {
            name: "NO"
            PropertyChanges {
                target: led
                color: "red"
            }
        },
        State {
            name: "DEFAULT"
            PropertyChanges {
                target: led
                color: "lightgrey"
            }
        }
    ]

    Row {
        id: row
        anchors.fill: parent
        spacing: 0

        Rectangle {
            width: root.width * 1/2
            height: root.height
            color: "transparent"

            Text {
                anchors.centerIn: parent
                text: root.text
                font.pixelSize: 15
                color: "white"
            }
        }

        Rectangle {
            color: "transparent"
            width: root.width * 1/4
            height: root.height

            Rectangle {
                id: led
                anchors.centerIn: parent
                width: 40
                height: 40
                radius: 40
            }
        }

        Rectangle {
            color: "transparent"
            width: root.width * 1/4
            height: root.height

            Rectangle {
                id: button

                states: [
                    State {
                        name: "RESET"
                        PropertyChanges {
                            target: button
                            color: "grey"
                        }
                        PropertyChanges {
                            target: text
                            text: "Reset"
                        }
                    },
                    State {
                        name: "NORMAL"
                        PropertyChanges {
                            target: button
                            color: "transparent"
                        }
                        PropertyChanges {
                            target: text
                            color: "transparent"
                        }
                    }
                ]
                anchors.centerIn: parent
                width: parent.width - 30
                height: parent.height - 30
                color: "#888888"
                radius: 8

                Text {
                    id: text
                    anchors.centerIn: parent
                    text: "RESET"
                    color: "white"
                }
            }
        }
    }
}
