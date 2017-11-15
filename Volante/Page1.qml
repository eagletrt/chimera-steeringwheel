import QtQuick 2.0

Rectangle {
    id: page1 
    color: "#000000"

    function connect() {
        console.log("Connetto! Page1");
        mainwindow.btnPressed.connect(btnPressedHandler);
        mainwindow.btnReleased.connect(btnReleasedHandler);
        mainwindow.btnClicked.connect(btnClickedHandler);
    }

    function disconnect() {
        console.log("Disconnetto! Page1");
        mainwindow.btnPressed.disconnect(btnPressedHandler);
        mainwindow.btnReleased.disconnect(btnReleasedHandler);
        mainwindow.btnClicked.disconnect(btnClickedHandler);
    }

    function btnPressedHandler(btnID) {
        //console.log("Page1::btnPressed");
    }

    function btnReleasedHandler(btnID) {
        //console.log("Page1::btnReleased");
    }

    function btnClickedHandler(btnID) {
        //console.log("Page1::btnClicked");
    }
}
