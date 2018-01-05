import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Pages 1.0

//Item {
//    ListView {
//        implicitHeight: 250
//        implicitWidth: 250

//        model: 100
//    }
//}

Frame {
    ListView {
        implicitHeight: 250
        implicitWidth: 250
        clip:  true

//        model: ListModel {
//            ListElement {
//                done: true
//                description: "What ever you want"
//            }
//            ListElement {
//                done: true
//                description: "you can do any things"
//            }
//        }
        model: PageTestModel {}

        delegate: RowLayout {
            width:  parent.width

            CheckBox {
                checked: model.done
                onClicked: model.done = checked
            }
            TextField {
                text: model.description
                Layout.fillWidth: true
                onEditingFinished: model.description = text
            }
        }

    }
}
