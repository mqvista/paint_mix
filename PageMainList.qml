import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1

    ColumnLayout {
        x: 88
        y: 80
        anchors.verticalCenterOffset: -100
        anchors.horizontalCenterOffset: -150
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 100

        RowLayout {
            spacing: 100

            Label {
                id: label
                text: pageMainModel.subList[0]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label1
                text: pageMainModel.subList[1]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label2
                text: pageMainModel.subList[2]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }
        }

        RowLayout {
            spacing: 100
            Label {
                id: label3
                text: pageMainModel.subList[3]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label4
                text: pageMainModel.subList[4]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label5
                text: pageMainModel.subList[5]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }
        }

        RowLayout {
            spacing: 100
            Label {
                id: label6
                text: pageMainModel.subList[6]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label7
                text: pageMainModel.subList[7]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }

            Label {
                id: label8
                text: pageMainModel.subList[8]
                color: "#ffffff"
                font.pointSize: 22
                font.family: "Courier"
            }
        }
    }

    ColumnLayout {
        x: 423
        y: 80
        anchors.horizontalCenterOffset: 250
        anchors.verticalCenterOffset: -100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 100

        ComboBox {
            id: comboBox
            font.pointSize: 22
            spacing: -6
            model: pageMainModel.profileList
            onCurrentTextChanged: {
                pageMainModel.reflushSubList(currentText);
                console.log(currentText);
            }
        }

        Button {
            id: button
            text: qsTr("Run")
            Layout.preferredWidth: 140
            enabled: {
                if (pageMainModel.busy == true)
                {
                    return false
                }
                else
                    return true;
            }

            onClicked: {
                pageMainModel.runFromProfile(comboBox.currentText);
                console.log(currentText);
            }
        }
    }

}
