import QtQuick 2.7
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    color: "transparent"

    property int currentPreset: CarStatus.preset
    property var presets: [
        [1, 1],
        [2, 0],
        [3, 0],
        [4, 0],
        [5, 0],
        [6, 0],
        [7, 0],
        [8, 0],
    ]

    /*
    Connections {
        target: racingPage
        onPresetChanged: {
            currentPreset = presetID;
        }
    }
    */

    GridLayout {
        anchors.fill: parent
        columns: 8
        columnSpacing: 5

        Repeater {
            model: presets
            Preset {
                index: modelData[0]
                currentIndex: currentPreset
                Layout.fillHeight: true
                Layout.fillWidth: true
            } 
        }
    }
}