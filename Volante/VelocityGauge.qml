import QtQuick 2.7

Rectangle {
    width: 180
    height: 180
    color: "transparent"
    anchors.centerIn: parent
    FontLoader {id:blackops; source: "lib/blops.ttf"}

    //property int value: Math.sqrt(acceleratore.width)*6
    property int value: 0

    /*
    Behavior on width {
        NumberAnimation{
            duration: 1
            easing.type: Easing.Linear
            easing.amplitude: 10
        }
    }
    */

    Text {
        text: parent.value
        anchors.centerIn: parent
        color: "white"
        font.family: blackops.name;
        font.pointSize: 70
    }
}
