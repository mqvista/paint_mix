import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 100
    height: 40
    property alias button: button
    Button {
        id: button
        text: qsTr("Button")
        anchors.left: parent.left
        anchors.top: parent.top
        onClicked: {
            pageMainModel.runTest();
        }
    }

}
