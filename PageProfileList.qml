import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

Item {
    RowLayout {
        y: 78
        width: 300
        anchors.verticalCenterOffset: -250
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 600

        Label {
            id: labelProfiles
            color: "#ffffff"
            text: qsTr("Profiles")
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pointSize: 30
        }

        ComboBox {
            id: comboBoxProfiles
            width: 140
            model: pageProfileModel.profileList
            onCurrentIndexChanged: {
                pageProfileModel.reflushSubList(currentText);
                console.log(currentText);
            }
        }
    }

    ColumnLayout {
        y: 128
        anchors.left: parent.left
        anchors.leftMargin: 120
        anchors.verticalCenter: parent.verticalCenter
        spacing: 80

        RowLayout {
            spacing: 10

            Label {
                id: labelUnit01
                color: "#ffffff"
                text: qsTr("Unit01:")
                font.pointSize: 30
            }
            TextEdit {
                id: textUnit01
                color: "#ffffff"
                text: pageProfileModel.subList[0]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit02
                color: "#ffffff"
                text: qsTr("Unit02:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit02
                color: "#ffffff"
                text: pageProfileModel.subList[1]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit03
                color: "#ffffff"
                text: qsTr("Unit03:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit03
                color: "#ffffff"
                text: pageProfileModel.subList[2]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit04
                color: "#ffffff"
                text: qsTr("Unit04:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit04
                color: "#ffffff"
                text: pageProfileModel.subList[3]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit05
                color: "#ffffff"
                text: qsTr("Unit05:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit05
                color: "#ffffff"
                text: pageProfileModel.subList[4]
                font.pointSize: 30
            }
        }
    }

    ColumnLayout {
        y: 128
        anchors.left: parent.left
        anchors.leftMargin: 380
        anchors.verticalCenter: parent.verticalCenter
        spacing: 80
        RowLayout {
            spacing: 10
            Label {
                id: labelUnit06
                color: "#ffffff"
                text: qsTr("Unit06:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit06
                color: "#ffffff"
                text: pageProfileModel.subList[5]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit07
                color: "#ffffff"
                text: qsTr("Unit07:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit07
                color: "#ffffff"
                text: pageProfileModel.subList[6]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit08
                color: "#ffffff"
                text: qsTr("Unit08:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit08
                color: "#ffffff"
                text: pageProfileModel.subList[7]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit09
                color: "#ffffff"
                text: qsTr("Unit09:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit09
                color: "#ffffff"
                text: pageProfileModel.subList[8]
                font.pointSize: 30
            }
        }

        RowLayout {
            spacing: 10
            Label {
                id: labelUnit10
                color: "#ffffff"
                text: qsTr("Unit10:")
                font.pointSize: 30
            }

            TextEdit {
                id: textUnit10
                color: "#ffffff"
                text: pageProfileModel.subList[9]
                font.pointSize: 30
            }
        }
    }

    RowLayout {
        y: 270
        anchors.verticalCenterOffset: -100
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 600
        spacing: 100

        Button {
            id: buttonDelete
            text: qsTr("Delete")
            font.capitalization: Font.AllLowercase
            font.pointSize: 22
        }

        Button {
            id: buttonAddNew
            text: qsTr("AddNew")
            font.pointSize: 22
        }
    }

}
