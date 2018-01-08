import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 250
    height: 40

    Row {
        anchors.top: parent.top
        anchors.left: parent.left
        spacing: 10

        ComboBox {
            id: comboBoxInitAsix
            font.pointSize: 22
            model: ["0","1", "2", "3", "4", "5", "6","7","8","9","10"]
        }

        Button {
            id: buttonInitAsix
            text: qsTr("InitAsix")
            onClicked: {
                worker00.initAsix(comboBoxInitAsix.currentText);
            }
        }
    }

}
