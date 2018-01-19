import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

Popup {
    id: root
    x: parent.width/2 - root.width/2
    y: parent.height/2 - root.height/2
    width: 640
    height: 400
    property alias water1: water1
    property alias zj2: zj2
    property alias zj1: zj1
    property alias sz1: sz1
    property alias yl7: yl7
    property alias yl6: yl6
    property alias yl5: yl5
    property alias yl4: yl4
    property alias yl3: yl3
    property alias yl2: yl2
    property alias yl1: yl1
    modal: true
    focus: true
    //设置窗口关闭方式为按“Esc”键关闭
    closePolicy: Popup.OnEscape
    //设置窗口的背景控件，不设置的话Popup的边框会显示出来
    background: rect

    Rectangle {
        id: rect
        y: 0
        anchors.fill: parent
        color: "#ffffff"
        border.width: 2
        opacity: 1
        radius: 8

        Rectangle{
            width: parent.width-4
            height: 2
            anchors.top: parent.top
            anchors.topMargin: 40
            anchors.left: parent.left
            anchors.leftMargin: 2
            radius: 8
        }

        //设置标题栏区域为拖拽区域
        Text {
            width: parent.width
            height: 40
            anchors.top: parent.top
            text: qsTr("新增配色方案")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            MouseArea {
                property point clickPoint: "0,0"

                anchors.fill: parent
                acceptedButtons: Qt.LeftButton
                onPressed: {
                    clickPoint  = Qt.point(mouse.x, mouse.y)
                }
                onPositionChanged: {
                    var offset = Qt.point(mouse.x - clickPoint.x, mouse.y - clickPoint.y)
                    setDlgPoint(offset.x, offset.y)
                }
            }
        }

        Button {
            x: 105
            y: 274
            text: "ok"
            anchors.horizontalCenterOffset: -100
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 22
            onClicked: {
                console.log(name.text);
                console.log(yl1.text);
                var sth =  pageColorConfigModel.saveNewColorConfig(name.text, yl1.text, yl2.text, yl3.text, yl4.text, yl5.text, yl6.text, yl7.text, water1.text, sz1.text, zj1.text, zj2.text);
                console.log(sth);
                root.close()
            }
        }

        Button {
            x: 343
            y: 274
            text: qsTr("cancel")
            anchors.verticalCenterOffset: 100
            anchors.horizontalCenterOffset: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 22
            onClicked: {
                root.close()
            }
        }

        ColumnLayout {
            x: 56
            y: 68
            spacing: 20
            anchors.verticalCenterOffset: -50
            anchors.horizontalCenterOffset: -210
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: row

                Label {
                    id: label
                    text: qsTr("颜料1:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                    font.family: "Courier"
                }

                TextField {
                    id: yl1
                    width: 100
                    height: 30
                    text: qsTr("")
                    anchors.verticalCenter: parent.verticalCenter
                    opacity: 0.8
                    font.pointSize: 16
                    renderType: Text.NativeRendering
                    validator: IntValidator { bottom: 1; top: 500; }
                }

                Label {
                    id: label1
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row1
                Label {
                    id: label2
                    text: qsTr("颜料2:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl2
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label3
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row2
                Label {
                    id: label4
                    text: qsTr("颜料3:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl3
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label5
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row3
                Label {
                    id: label6
                    text: qsTr("颜料4:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl4
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label7
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }
        }

        ColumnLayout {
            x: 257
            y: 69
            spacing: 20
            anchors.horizontalCenterOffset: 0
            anchors.verticalCenterOffset: -50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: row4
                Label {
                    id: label8
                    text: qsTr("颜料5:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl5
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label9
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row5
                Label {
                    id: label10
                    text: qsTr("颜料6:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl6
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label11
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row6
                Label {
                    id: label12
                    text: qsTr("颜料7:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: yl7
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label13
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row7
                Label {
                    id: label14
                    text: qsTr("树脂1:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: sz1
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label15
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }
        }

        ColumnLayout {
            x: 480
            y: 97
            spacing: 20
            anchors.verticalCenterOffset: -50
            anchors.horizontalCenterOffset: 210
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Row {
                id: row8
                Label {
                    id: label16
                    text: qsTr("助剂1:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: zj1
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label17
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row9
                Label {
                    id: label18
                    text: qsTr("助剂2:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: zj2
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label19
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row10
                Label {
                    id: label20
                    text: qsTr("加水1:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: water1
                    width: 100
                    height: 30
                    text: qsTr("")
                    validator: IntValidator {
                        bottom: 1
                        top: 500
                    }
                    anchors.verticalCenter: parent.verticalCenter
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                    opacity: 0.8
                }

                Label {
                    id: label21
                    text: qsTr("G")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }

            Row {
                id: row11
                Label {
                    id: label22
                    text: qsTr("配 名:")
                    anchors.verticalCenter: parent.verticalCenter
                    font.family: "Courier"
                    font.pointSize: 22
                }

                TextField {
                    id: name
                    width: 100
                    height: 30
                    text: qsTr("")
                    anchors.verticalCenter: parent.verticalCenter
                    opacity: 0.8
                    renderType: Text.NativeRendering
                    font.pointSize: 16
                }

                Label {
                    id: label23
                    text: qsTr("")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 22
                }
            }
        }
    }

    function setDlgPoint(dlgX ,dlgY)
    {
        //设置窗口拖拽不能超过父窗口
        if(root.x + dlgX < 0)
        {
            root.x = 0
        }
        else if(root.x + dlgX > root.parent.width - root.width)
        {
            root.x = root.parent.width - root.width
        }
        else
        {
            root.x = root.x + dlgX
        }
        if(root.y + dlgY < 0)
        {
            root.y = 0
        }
        else if(root.y + dlgY > root.parent.height - root.height)
        {
            root.y = root.parent.height - root.height
        }
        else
        {
            root.y = root.y + dlgY
        }
    }
}
