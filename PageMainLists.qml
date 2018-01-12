import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 300
    height: 550
    property alias contactDelegate: contactDelegate

    Rectangle {
        id: rectangle
        width: 300; height: 550
        radius: 3
        border.width: 3
        border.color: "Silver"

        Component {
            id: contactDelegate
            Item {
                width: 285; height: 80
                Column {
                    Text { text: '<b>Name:</b> ' + modelData ;font.pointSize: 20 }
                }
                MouseArea {
                    anchors.fill: parent
                    anchors.centerIn: parent
                    onClicked: {
                        listViewMain.currentIndex = index;  //实现item切换
                        pageMainModel.reflushSubList(modelData);
                    }
                }
            }
        }

        ListView {
            id: listViewMain
            width: 285
            anchors.bottomMargin: 8
            anchors.topMargin: 8
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            model: pageMainModel.profileList
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
            onModelChanged: {
                pageMainModel.reflushSubList(modelData);
            }
        }
    }
}
