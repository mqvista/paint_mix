import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0


ApplicationWindow {
    modality: Qt.ApplicationModal

    ColumnLayout {
        x: 83
        y: 36
        spacing: 10

        RowLayout {
            spacing: 10

            Label {
                id: label
                text: qsTr("Unit01:")
                font.pointSize: 22
            }

            TextField {
                id: textField
                text: qsTr("Text Field")
                Layout.preferredWidth: 100
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: label1
                text: qsTr("Unit01:")
                font.pointSize: 22
            }

            TextField {
                id: textField1
                text: qsTr("Text Field")
                Layout.preferredWidth: 100
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: label4
                text: qsTr("Unit01:")
                font.pointSize: 22
            }

            TextField {
                id: textField4
                text: qsTr("Text Field")
                Layout.preferredWidth: 100
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: label2
                text: qsTr("Unit01:")
                font.pointSize: 22
            }

            TextField {
                id: textField2
                text: qsTr("Text Field")
                Layout.preferredWidth: 100
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: label3
                text: qsTr("Unit01:")
                font.pointSize: 22
            }

            TextField {
                id: textField3
                text: qsTr("Text Field")
                Layout.preferredWidth: 100
            }
        }
    }

}
