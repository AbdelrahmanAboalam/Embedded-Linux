import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image{
        id: name
        width: 100
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "file:///home/aboalam/yocto/meta-Aboalam/recipes-packages/packages/files/images.png"

    }

    Rectangle {
        height: 150
        width: 150
        color: "red"
        anchors.centerIn: parent

        Text {
            id: textID
            color: "white"
            anchors.centerIn: parent
            font.pointSize: 60
        }
    }

    Connections {
        target: ITI
        function onCppToQML(value) {
            textID.text = value;
        }
    }

    Button {
        id: startBtn
        text: "Start Timer"
        x: 200
        y: 340

        onClicked: {
            ITI.startTimer();
        }
    }

    Button {
        id: stopBtn
        text: "Stop Timer"
        x: 380
        y: 340

        onClicked: {
            ITI.stopTimer();
        }
    }
}
