import QtQuick 2.0
import QtQuick.Controls 1.4 as OldCon
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.4

Item {
    width: 750
    height: 100


    RowLayout {
        x: 0
        y: 50
        id: rawLayOutControl
        signal motorAction(int board, int channel, int steps)

        ComboBox {
            id: comboBoxSelectBoard
            font.pointSize: 22
            //textRole: "SelectBoard"
            model: ["1", "2", "3", "4", "5", "6"]

        }

        ComboBox {
            id: comboBoxSelectChannel
            font.pointSize: 22
            //textRole: "SelectMotor"
            model: ["1", "2"]
        }

        TextField {
            id:textFieldSteps
            text: "100"
            font.pointSize: 22
            font.family: "Courier"
            //validator: IntValidator { bottom: 1; top: 99999; }

        }

        RadioButton {
            id: radioButtonCW
            checked: true

        }

        RadioButton {
            id: radioButtonCCW
        }

        Button {
            id: buttonRun
            text: qsTr("Run")
            onClicked: {
                var board = comboBoxSelectBoard.currentText;
                var channle = comboBoxSelectChannel.currentText;
                var steps = textFieldSteps.text;
                if (radioButtonCCW.checked)
                {
                    steps *= -1;
                }
                //console.log("board:" + board + " channel:" + channle + " stpes:" + steps );
                //rawLayOutControl.motorAction(board, channle, steps);
                worker00.motorAction(board, channle, steps);
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 10
        width: 708
        height: 30
        color: "#00000000"

        Label {
            id: labe0
            color: "#ffffff"
            text: qsTr("Board")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 50
        }

        Label {
            id: label1
            color: "#ffffff"
            text: qsTr("channel")
            anchors.left: parent.left
            anchors.leftMargin: 180
            anchors.bottom: parent.bottom
        }

        Label {
            id: label2
            color: "#ffffff"
            text: qsTr("Steps")
            anchors.left: parent.left
            anchors.leftMargin: 360
            anchors.bottom: parent.bottom
        }

        Label {
            id: label3
            color: "#ffffff"
            text: qsTr("CW")
            anchors.left: parent.left
            anchors.leftMargin: 507
            anchors.bottom: parent.bottom
        }

        Label {
            id: label4
            color: "#ffffff"
            text: qsTr("CCW")
            anchors.left: parent.left
            anchors.leftMargin: 553
            anchors.bottom: parent.bottom
        }

        Label {
            id: label5
            color: "#ffffff"
            text: qsTr("Run")
            anchors.left: parent.left
            anchors.leftMargin: 635
            anchors.bottom: parent.bottom
        }
    }
}
