import QtQuick 2.0
import QtQuick.Layouts 1.3


Item {
    id: item1
    width: 950
    height: 300
    Rectangle {
        id: rootRectangle
        color: "#ffffff"
        radius: 5
        anchors.fill: parent
        border.width: 3
        border.color: "Silver"

        GridView {
            keyNavigationWraps: false
            anchors.fill: parent
            anchors.margins: 20
            clip: true
            model: pViewGrid
            cellHeight: 90
            cellWidth: 226
            delegate: girdViewDelegate
        }
        Component {
            id: girdViewDelegate
            Rectangle {
                width: 215
                height: 80
                color: "#cad5db"
                Column {
                    Text {
                        text: '<b>名称:</b> '  + name
                        font.pointSize: 20
                    }
                    Text {
                        text: '设定重量:'  + setValue
                        font.pointSize: 15
                    }
                    Text {
                        text: '实际重量: '  + realValue
                        font.pointSize: 15
                    }
                }
            }
        }
    }
}
