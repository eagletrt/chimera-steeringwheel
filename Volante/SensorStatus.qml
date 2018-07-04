import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root

    property var text
    property var barColor
    property var barValue
    property var errorLEDCount
    property var selected

    FontLoader {id:blackops; source: "lib/blops.ttf"}

    color: root.selected == 1 ? "green" : menu.color


    RowLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            Layout.preferredWidth: parent.width*1/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            Text {
                text: root.text
                font.family: blackops.name;
                font.pointSize: 6
                color: "white"
                anchors.centerIn: parent
            }
        }

        Rectangle {
            Layout.preferredWidth: parent.width*3/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            Rectangle {
                width: parent.width
                height: parent.height/3
                anchors.centerIn: parent
                border.width: 1
                border.color: "white"
                color: menu.color

                Rectangle {
                    width: root.barValue
                    height: parent.height-2
                    anchors.left: parent.left
                    anchors.leftMargin: 1
                    anchors.verticalCenter: parent.verticalCenter
                    color: root.barColor
                }
            }
        }

        Rectangle {
            id: errorsApps
            Layout.preferredWidth: parent.width*4/8
            Layout.preferredHeight: parent.height/3
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            RowLayout {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 10

                Repeater {
                    model: root.errorLEDCount
                    delegate: Rectangle {
                        anchors.verticalCenter: parent.verticalCenter
                        width: 25
                        height: 25
                        color: "lightgray"
                        radius: 25 / 2
                    }
                }
            }
        }
    }

}
