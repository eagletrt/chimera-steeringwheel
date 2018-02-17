import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.2

Rectangle {
    id: root
    color: "#000000"
    anchors.fill: parent

    property var choiceButtonSelected: 0
    property var mBtnSetText: "SET"
    property var mHelpSetText: "Set the range for Actuator [MIN, MAX]"

    property var setPendingFlag: CAN.actuatorRangePendingFlag 

    function delay(duration) { // In milliseconds
        var timeStart = new Date().getTime();
        
        while (new Date().getTime() - timeStart < duration) {
            // Do nothing
        }
                    
        // Duration has passed
    }


    ListModel {
        id: sensors

        // The "m" before the ListElement proerty stands for "model",
        // and it's used to differenciate it from the actual delegate property
        // to be binded and thus changed

        ListElement {
            mText: "APPS"
            mColor: "green"
            mValue: 50
            mErrorLEDCount: 5
            mSelected: 0
        }

        ListElement {
            mText: "BSE"
            mColor: "red"
            mValue: 60
            mErrorLEDCount: 4
            mSelected: 0
        }

        ListElement {
            mText: "STEER"
            mColor: "grey"
            mValue: 20
            mErrorLEDCount: 1
            mSelected: 0
        }

    }

    onSetPendingFlagChanged: function() {
        console.log("Cleared");
        root.mBtnSetText = "SET";
    }

    property var btnClickable: false
    property var isStarted: false
    property var sensorSelectedIndex: -1

    function connect() {
        console.log("Tab connessa - Sensors");
        menu.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
        console.log("Tab disconnessa - Sensors");
        menu.btnClicked.disconnect(btnClickedHandler);
    }

    function unSelectSensors() {
        if (sensorSelectedIndex != -1) {
            sensors.setProperty(sensorSelectedIndex, "mSelected", 0);
        } 
    }

    function selectSensor(index) {
        if (sensorSelectedIndex != -1) {
            sensors.setProperty(sensorSelectedIndex, "mSelected", 0);
        } 

        index = index % 3;

        sensors.setProperty(index, "mSelected", 1);

        sensorSelectedIndex = index;
    }

    function btnClickedHandler(btnID) {
        if (btnID == 0) {
            if (tabView.stepIntoTab && !choiceButtonSelected) {
                // We are into the tab, get out!
                btnClickable = false;
                isStarted = false;

                // Remove highlight from current selected sensor item
                unSelectSensors();

                mainwindow.canSwitchPage = true;
                tabView.stepIntoTab = false;
            }

            if (choiceButtonSelected) {
                choiceButtonSelected = 0;
            }
        }

        if (btnID == 1) {
            if (tabView.stepIntoTab && !choiceButtonSelected)  {
                // Enable buttons for current sensors! 
                choiceButtonSelected = 1
            } 
        }

        if (btnID == 2) {
            // Step into this tab and change the behaviour of btnID
            if (!tabView.stepIntoTab) {
                // Set the button clickable
                btnClickable = true;

                // Select the first entry of the SensorsList 
                selectSensor(0);

                // Prevent the button 0 to switch to Racing Page!
                tabView.stepIntoTab = true;
                mainwindow.canSwitchPage = false;

            } else {
                if (!choiceButtonSelected) {
                    // Loop through sensors
                    selectSensor(sensorSelectedIndex + 1);
                } else {
                    // SET RANGES for the sensorSelectedIndex
                    // DEBUG: for now only to sensorSelectedIndex = 0 (APPS)
                    if (sensorSelectedIndex == 0) {
                        root.mBtnSetText = "Setting..."
                        CAN.setActuatorsRange(0,0);
                    }
                }
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: sensorListView
            width: parent.width
            Layout.preferredHeight: parent.height * 0.75
            model: sensors
            delegate: SensorStatus {
                        text: mText
                        barColor: mColor
                        barValue: mValue
                        errorLEDCount: mErrorLEDCount
                        selected: mSelected
                        height: sensorListView.height / 3 
                        width: parent.width
                    }
        }

        Rectangle {
            // If we need this row to be a little bit taller, 
            // we can edit this prefered height
            //Layout.preferredHeight: root.height / 2
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height / 4
            color: menu.color

            GridLayout {
                anchors.fill: parent
                rows: 1
                columns: 2

                Text {
                    text: mHelpSetText
                    Layout.fillHeight: true
                    Layout.preferredWidth: parent.width * 0.60
                    color: "white"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 12
                }

                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    ChoiceButton {
                        width: 150
                        height: 40
                        btnColor: "green" 
                        btnText: mBtnSetText 
                        selected: choiceButtonSelected && !setPendingFlag
                    }
                }

            }
        }
    }
}

/*

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

        Rectangle {
            Layout.preferredWidth: parent.width 
            Layout.preferredHeight: parent.height / 4
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "red"
        }
    }
}
*/
