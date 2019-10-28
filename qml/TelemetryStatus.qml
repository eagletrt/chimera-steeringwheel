import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle{
    id: root
    color: "transparent"

    property var text
    property var selected
    property var index

    FontLoader {id:blackops; source: "../lib/blops.ttf"}

    border.color: root.selected == 1 ? "green" : "#000000"
    radius: root.selected == 1 ? "20" : "0"

    ColumnLayout{
        spacing: 0
        anchors.fill: parent

        Rectangle{
            color: "transparent"
            width: parent.width
            height: parent.height/2

            Rectangle{
                color: selected == 1 ? "green" : "lightgrey"
                radius: 100
                anchors.centerIn: parent
                height: parent.height
                width: parent.height
            }
        }

        Rectangle{
            color: "transparent"
            width: parent.width
            height: parent.height/2

            Text {
                text: root.text
                anchors.centerIn: parent
                font.family: blackops.name
                font.pointSize: 4.5
                color: "#ffffff"
            }
        }
    }

}
