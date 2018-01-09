import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.0

Item {
    width: 260
    height: 40

    RowLayout {
        x: 0
        y: 0
        width: 260
        id: rawLayOutControl
        signal motorAction(int board, int channel, int steps)

        ComboBox {
            id: comboBoxSelectAsix
            font.pointSize: 22
            model: ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]

        }
        Button {
            id: buttonRun
            text: qsTr("Move")
            onClicked: {
                var board = comboBoxSelectAsix.currentText;
                pageFactoryMod.moveToAsix(board);
            }
        }
    }
}
