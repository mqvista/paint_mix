import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 160
    height: 102

    ColumnLayout {
        x: 87
        y: 130
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 50

        RowLayout {
            spacing: 30

            Label {
                id: label
                text: qsTr("ScalesSml:")
                color: "#ffffff"
                font.pointSize: 22
            }

            Label {
                id: label1
                text: pageSideBarModel.smallScales;
                color: "#ffffff"
                font.pointSize: 22
            }
        }

        RowLayout {
            spacing: 30
            Label {
                id: label2
                text: qsTr("ScalesBig :")
                color: "#ffffff"
                font.pointSize: 22
            }

            Label {
                id: label3
                text: qsTr("--")
                color: "#ffffff"
                font.pointSize: 22
            }
        }
    }
}
