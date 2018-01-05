import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 200
    height: 60


    Button {
        id: buttonEncoder
        text: qsTr("Button")
        anchors.left: parent.left
        anchors.top: parent.top
        onClicked: {
            console.log(worker00.initAsixA())
        }
    }
    TextArea {
        width: 80
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 120
        text: pageFactoryMod.EncoderData
        color: "#ffffff"
    }
}
