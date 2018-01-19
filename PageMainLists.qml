import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 1280
    height: 760

    RowLayout {
        x: 163
        y: 97
        anchors.verticalCenterOffset: -150
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 50

        Column {
            spacing: 40

            RowLayout {

                Label {
                    id: label
                    text: qsTr("颜料1：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL1
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label1
                    text: qsTr("颜料2：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL2
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label2
                    text: qsTr("颜料3：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL3
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label3
                    text: qsTr("颜料4：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL4
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }
        }

        ColumnLayout {
            spacing: 40

            RowLayout {
                spacing: 5
                Label {
                    id: label4
                    text: qsTr("颜料5：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL5
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label5
                    text: qsTr("颜料6：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL6
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label6
                    text: qsTr("颜料7：")
                    font.pointSize: 33
                }

                TextField {
                    id: teYL7
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label7
                    text: qsTr("树脂1：")
                    font.pointSize: 33
                }

                TextField {
                    id: teSZ1
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }
        }

        ColumnLayout {
            spacing: 40

            RowLayout {
                Label {
                    id: label8
                    text: qsTr("助剂1：")
                    font.pointSize: 33
                }

                TextField {
                    id: teZJ1
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label9
                    text: qsTr("助剂2：")
                    font.pointSize: 33
                }

                TextField {
                    id: teZJ2
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label10
                    text: qsTr("放水1：")
                    font.pointSize: 33
                }

                TextField {
                    id: teWater1
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }

            RowLayout {
                Label {
                    id: label11
                    text: qsTr("放水2：")
                    font.pointSize: 33
                }

                TextField {
                    id: teWater2
                    text: qsTr("")
                    font.capitalization: Font.AllLowercase
                    font.pointSize: 33
                }
            }
        }
    }

    Row {
        x: 142
        y: 492
        anchors.verticalCenterOffset: 200
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 500

        Button {
            id: button
            width: 200
            height: 60
            text: qsTr("运    行")
            opacity: 0.8
            font.pointSize: 33
            onClicked: {
                pageMainModel.manualControl(teYL1.text, teYL2.text, teYL3.text,
                                            teYL4.text, teYL4.text, teYL5.text,
                                            teYL6.text, teYL7.text, teSZ1.text,
                                            teZJ1.text, teZJ2.text, teWater1.text,
                                            teWater2.text);

            }
        }

        Button {
            id: button1
            width: 200
            height: 60
            text: qsTr("停    止")
            font.pointSize: 33
            opacity: 0.8
        }
    }

}
