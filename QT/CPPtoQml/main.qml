import QtQuick
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Rectangle{
        height: 100
        width: 100
        color: "red"
        anchors.centerIn: parent



        Text{
            id: textID
            color: "white"
            anchors.centerIn: parent
            font.pointSize: 60
        }
    }

    Connections{

        target: ITI
        function onCppToQML (value){
            textID.text=value;
        }
    }

    Button {
        id: btn
        text: "Signal"
        onClicked: function(){
        ITI_Reciver.qm_ToCpp();
    }
    }
}
