import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

Item {
    width: 600
    height: 350
    GroupBox {
        id: groupBox
        x: 0
        y: 0
        width: 600
        height: 350
        contentHeight: -5
        title: "Limit Status"

        GridLayout {
            id: girdBoard1
            x: 10
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2

            Label {
                id: labLim1
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim1
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[0] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim2
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim2
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[1] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim3
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim3
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[2] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim4
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim4
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[3] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim5
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim5
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[4] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim6
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim6
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[5] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim7
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim7
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[6] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim8
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim8
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[7] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }

        GridLayout {
            id: girdBoard2
            x: 110
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2
            Label {
                id: labLim9
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim9
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[8] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim10
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim10
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[9] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim11
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim11
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[10] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim12
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim12
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[11] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim13
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim13
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[12] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim14
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim14
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[13] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim15
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim15
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[14] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim16
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim16
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[15] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }

        GridLayout {
            id: girdBoard3
            x: 210
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2
            Label {
                id: labLim17
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim17
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[16] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim18
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim18
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[17] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim19
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim19
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[18] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim20
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim20
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[19] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim21
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim21
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[20] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim22
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim22
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[21] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim23
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim23
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[22] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim24
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim24
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[23] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }

        GridLayout {
            id: girdBoard4
            x: 310
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2
            Label {
                id: labLim25
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim25
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[24] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim26
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim26
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[25] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim27
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim27
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[26] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }


            Label {
                id: labLim28
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim28
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[27] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim29
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim29
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[28] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim30
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim30
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[29] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim31
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim31
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[30] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim32
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim32
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[31] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }

        GridLayout {
            id: girdBoard5
            x: 410
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2
            Label {
                id: labLim33
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim33
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[32] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim34
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim34
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[33] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim35
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim35
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[34] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim36
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim36
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[35] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim37
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim37
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[36] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim38
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim38
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[37] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim39
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim39
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[38] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim40
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim40
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[39] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }

        GridLayout {
            id: girdBoard6
            x: 510
            y: 30
            width: 70
            height: 270
            rows: 8
            columns: 2
            Label {
                id: labLim41
                color: "#ffffff"
                text: qsTr("Lim1")
            }

            Rectangle {
                id: recLim41
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[40] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim42
                color: "#ffffff"
                text: qsTr("Lim2")
            }

            Rectangle {
                id: recLim42
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[41] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim43
                color: "#ffffff"
                text: qsTr("Lim3")
            }

            Rectangle {
                id: recLim43
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[42] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim44
                color: "#ffffff"
                text: qsTr("Lim4")
            }

            Rectangle {
                id: recLim44
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[43] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim45
                color: "#ffffff"
                text: qsTr("Lim5")
            }

            Rectangle {
                id: recLim45
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[44] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim46
                color: "#ffffff"
                text: qsTr("Lim6")
            }

            Rectangle {
                id: recLim46
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[45] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim47
                color: "#ffffff"
                text: qsTr("Lim7")
            }

            Rectangle {
                id: recLim47
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[46] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }

            Label {
                id: labLim48
                color: "#ffffff"
                text: qsTr("Lim8")
            }

            Rectangle {
                id: recLim48
                Layout.preferredHeight: 20
                Layout.preferredWidth: 20
                color: {
                    if (pageFactoryMod.LimitData[47] === 0)
                    {
                        return "#FFFFFF"
                    }
                    else
                    {
                        return "#00FF7F"
                    }
                }
            }
        }
    }

    RowLayout {
        x: 20
        y: 35
        spacing: 48

        Label {
            id: labBoard01
            color: "#ffffff"
            text: qsTr("Board01")
        }

        Label {
            id: labBoard02
            color: "#ffffff"
            text: qsTr("Board02")
        }

        Label {
            id: labBoard03
            color: "#ffffff"
            text: qsTr("Board03")
        }

        Label {
            id: labBoard04
            color: "#ffffff"
            text: qsTr("Board04")
        }

        Label {
            id: labBoard05
            color: "#ffffff"
            text: qsTr("Board05")
        }

        Label {
            id: labBoard06
            color: "#ffffff"
            text: qsTr("Board06")
        }
    }
}
