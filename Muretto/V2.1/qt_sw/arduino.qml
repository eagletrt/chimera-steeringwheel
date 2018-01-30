import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Rectangle {

    color:"black"
    //opacity:arduino.brightness / 1024;
    width: 900
    height: 400

    RequestTable {
        x:500
        y:60

        model: requestModel

        ListModel {
            id: requestModel
            ListElement {
                request: "Request"
                time: 777
            }
        }
    }

    ResponseTable{
        x:680
        y:60

        model: responseModel

        onClicked:{
            //requestModel.append({"request": "prova", "response": 1,"time":0.5})
        }

        ListModel {
            id: responseModel
            ListElement {
                response: "Response"
                value: 777
            }
        }
    }

    Button {
        id: button
        text: "RESET"
        x:190
        y:60
        onClicked:
        {
            if(led.checked!=false){
                led.checked=false;

            }
            else{
                if(albi.checked!=false){
                    albi.checked=false;
                }
                else{
                    if(relay.checked!=false){
                        relay.checked=false;
                    }
                }
            }
            requestModel.clear();
            responseModel.clear();
        }
    }
    Column {
        x: 108
        y:307
        Text{text:"LED_R";color:"white"}
        Switch {
            id:led
            checked: false
            onCheckedChanged:
            {
                if (checked == true)
                {
                    arduino.turnOn(1);
                    requestModel.append({"request": "TURN_ON_R","time":0.5})
                }
                else
                {
                    arduino.turnOff(1);
                    requestModel.append({"request": "TURN_OFF_R","time":0.5})
                }
            }
        }
    }
    Column {
        x: 216
        y:307
        Text{text:"LED_G";color:"white"}
        Switch {
            id:relay
            checked: false
            onCheckedChanged:
            {
                if (checked == true)
                {
                    arduino.turnOn(2);
                    requestModel.append({"request": "TURN_ON_G","time":0.5})
                }
                else
                {
                    arduino.turnOff(2);
                    requestModel.append({"request": "TURN_OFF_G","time":0.5})
                }
            }
        }
    }
    Column {
        x:324
        y:307
        Text{text:"LED_Y";color:"white"}
        Switch {
            id:albi
            checked: false
            onCheckedChanged:
            {
                if (checked == true)
                {
                    arduino.turnOn(3);
                    requestModel.append({"request": "TURN_ON_Y","time":0.5})
                }
                else
                {
                    arduino.turnOff(3);
                    requestModel.append({"request": "TURN_OFF_Y","time":0.5})
                }
            }
        }
    }

    Dial
    {
       x:10
       y:100
       value:(arduino.brightness-1);
       onValueChanged: {
           //qua tutte le volte che risponde con il valore
           //per alzare il dial viene scritto nella TableView
           responseModel.append({"response": "B:", "value": parseInt(arduino.brightness)})
       }
    }

    Dial
    {
       x:258
       y:100
       value:(arduino.volume-5);
       onValueChanged: {
           //qua tutte le volte che risponde con il valore
           //per alzare il dial viene scritto nella TableView
           responseModel.append({"response": "V:", "value": parseInt(arduino.volume)})
       }
    }

}

