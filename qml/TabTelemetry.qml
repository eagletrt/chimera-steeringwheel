import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id: root
    anchors.fill: parent
    color: "#000000"

    Component{
        id: telemetryDelegate

        ColumnLayout{
            spacing: 0
            width: root.width/4
            height: root.height/3

            Rectangle{
                color: "transparent"
                width: parent.width
                height: parent.height/2

                Rectangle{
                    color: "lightgrey"
                    radius: 100
                    anchors.centerIn: parent
                    height: parent.height
                    width: parent.height //makes it a circle
                }
            }

            Rectangle{
                color: "transparent"
                width: parent.width
                height: parent.height/2

                Text {
                    text: name
                    anchors.centerIn: parent
                    color: "#ffffff"
                }
            }
        }
    }

    ListModel{
        id: telemetry

        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
        ListElement{
            name: qsTr("Elemento")
        }
    }

    GridView{
        anchors.fill: parent
        cellWidth: root.width/4
        cellHeight: root.height/3
        model: telemetry
        delegate: telemetryDelegate
    }
}
