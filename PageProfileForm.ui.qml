import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

PageBackGround {
    id: pageBackGround
    property alias buttonDelete: buttonDelete
    property alias buttonAddNew: buttonAddNew
    tittle: "Profile"

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

            Label {
                id: labelText01
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText02
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText03
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText04
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText05
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText06
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText07
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText08
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText09
                color: "#ffffff"
                text: qsTr("-----")
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

            Label {
                id: labelText10
                color: "#ffffff"
                text: qsTr("-----")
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
