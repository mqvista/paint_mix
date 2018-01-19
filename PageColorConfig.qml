import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: item1
    width: 1280
    height: 680
    Button {
        id: button
        width: 200
        height: 60
        text: qsTr("新增方案")
        anchors.verticalCenterOffset: 245
        anchors.horizontalCenterOffset: 188
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: 0.8
        font.pointSize: 33
        onClicked: {
            myDialog.open()
            myDialog.x = parent.width/2 - myDialog.width/2
            myDialog.y = parent.height/2 - myDialog.height/2
        }
    }

    PageColorConfigAddDialog {
        id: myDialog
    }

    PageColorConfigList {
        id: pageColorConfigList
        anchors.verticalCenterOffset: 0
        anchors.rightMargin: 19
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
    }

//    PageColorConfigArray {
//        id: pageColorConfigArray
//        anchors.verticalCenterOffset: -120
//        anchors.horizontalCenterOffset: -160
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.horizontalCenter: parent.horizontalCenter
//    }
    PageColorConfigGridView {
        id: pageColorConfigGridView
        anchors.verticalCenterOffset: -120
        anchors.horizontalCenterOffset: -160
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    PageColorConfigRunning {
        id: pageColorConfigRunning
        x: 44
        y: 506
        anchors.verticalCenterOffset: 245
        anchors.horizontalCenterOffset: -200
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: buttonRun
        x: 194
        y: 214
        width: 200
        height: 60
        text: qsTr("运行")
        anchors.verticalCenterOffset: 86
        anchors.horizontalCenterOffset: 188
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 33
        focusPolicy: Qt.NoFocus
        enabled: {
            if (pageColorConfigModel.busy == true)
            {
                return false
            }
            else
                return true;
        }
        onClicked: {
            console.log(pageColorConfigModel.profileList[pageColorConfigList.listViewMain.currentIndex]);
            pageColorConfigModel.runFromProfile(pageColorConfigModel.profileList[pageColorConfigList.listViewMain.currentIndex]);

        }
    }

    Row {
        x: 57
        y: 396
        anchors.verticalCenterOffset: 200
        anchors.horizontalCenterOffset: -520
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: label
            text: qsTr("小秤读数:")
            font.pointSize: 33
            font.family: "Verdana"
        }

        Label {
            id: label1
            width: 33
            height: 10
            text: pageColorConfigModel.smallScales
            font.pointSize: 33
        }
    }

    Row {
        x: 65
        y: 391
        anchors.horizontalCenterOffset: -520
        anchors.verticalCenter: parent.verticalCenter
        Label {
            id: label2
            text: qsTr("大秤读数:")
            font.pointSize: 33
            font.family: "Verdana"
        }

        Label {
            id: label3
            width: 33
            height: 10
            text: pageColorConfigModel.bigScales
            font.pointSize: 33
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: 250
    }

    Row {
        x: 47
        y: 386
        anchors.horizontalCenter: parent.horizontalCenter
        Label {
            id: label4
            text: qsTr("预计重量:")
            font.family: "Verdana"
            font.pointSize: 33
        }

        Label {
            id: label5
            width: 33
            height: 10
            text: "123"
            font.pointSize: 33
        }
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 93
        anchors.horizontalCenterOffset: -520
    }

    Row {
        x: 53
        y: 376
        anchors.horizontalCenter: parent.horizontalCenter
        Label {
            id: label6
            text: qsTr("实际重量:")
            font.family: "Verdana"
            font.pointSize: 33
        }

        Label {
            id: label7
            width: 33
            height: 10
            text: "123"
            font.pointSize: 33
        }
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 93
        anchors.horizontalCenterOffset: -246
    }
}
