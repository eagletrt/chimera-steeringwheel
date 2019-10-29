import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    color: "#000000"

    state: "DEFAULT"

    FontLoader {id:blackops; source: "../lib/blops.ttf"}

    property var text
    
    Rectangle{
        id: row
        color: "transparent"
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        Rectangle{
            id: led
            color: "transparent"
            radius: 100
            anchors.centerIn: parent
            height: parent.height-10
            width: parent.height-10
        }
        
        Text {
            id: sensor
            text: root.text
            anchors.centerIn: parent
            font.family: blackops.name
            font.pointSize: 6
            color: "lightgrey"
        }
    }

    states: [
        State {
            name: "OFFLINE"
            PropertyChanges {
                target: led
                color: "red"
            }
        },
        State {
            name: "ONLINE"
            PropertyChanges {
                target: led
                color: "green"
            }
        },
        State {
            name: "DEFAULT"
            PropertyChanges {
                target: led;
                color: "transparent";
            }   
            PropertyChanges {
                target: sensor;
                color: "lightgrey";
            }
        },     
        State {
            name: "SELECTED"
            PropertyChanges {
                target: led;
                border.color: "green"
                color: "trasnparent";
            }   
            PropertyChanges {
                target: sensor;
                color: "green";
            }
        }
    ]
}
