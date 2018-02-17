import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    radius: 8
    anchors.centerIn: parent

    property var btnText
    property var btnColor
    property var selected 

    color: root.selected ? root.btnColor : "#333"

    Text {
        anchors.centerIn: parent
        color: "white"
        text: root.btnText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

