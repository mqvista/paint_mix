import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 950
    height: 300

    Rectangle {
        id: rectangle
        color: "#ffffff"
        radius: 3
        anchors.fill: parent
        border.width: 3
        border.color: "Silver"

        ColumnLayout {
            x: 88
            y: 80
            width: 900
            height: 250
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 60

            RowLayout {
                spacing: 80

                Label {
                    id: label
                    text: pageMainModel.subList[0]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label1
                    text: pageMainModel.subList[1]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label2
                    text: pageMainModel.subList[2]
                    font.pointSize: 33
                    font.family: "Courier"
                }
            }

            RowLayout {
                scale: 1
                spacing: 80
                Label {
                    id: label3
                    text: pageMainModel.subList[3]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label4
                    text: pageMainModel.subList[4]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label5
                    text: pageMainModel.subList[5]
                    font.pointSize: 33
                    font.family: "Courier"
                }
            }

            RowLayout {
                spacing: 80
                Label {
                    id: label6
                    text: pageMainModel.subList[6]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label7
                    text: pageMainModel.subList[7]
                    font.pointSize: 33
                    font.family: "Courier"
                }

                Label {
                    id: label8
                    text: pageMainModel.subList[8]
                    font.pointSize: 33
                    font.family: "Courier"
                }
            }
        }
    }

}
