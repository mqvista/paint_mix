import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2
import QtQuick.Extras 1.4

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 1280
    height: 800
    title: qsTr("Paint Mix")

    Rectangle {
        id: tittleMain
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        height: 60
        color: "silver"

        Label {
            text: "<b>Hiwave</b>"
            color: "#1e90ff"
            font.pointSize: 33
            fontSizeMode: Text.VerticalFit
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

    }

    StackLayout {
        id: stackLayoutMain
        //anchors.top: parent.top
        anchors.top: tittleMain.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: tabBarMain.top
        currentIndex: tabBarMain.currentIndex

        PageMain {

        }

        PageColorConfig {

        }
        PageColorConfig {

        }
        PageFactory {

        }

    }
    TabBar {
        id: tabBarMain
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.bottomMargin: 16
        anchors.leftMargin: 0
        currentIndex: stackLayoutMain.currentIndex
        TabButton {
            id: tabButtonMain
            text: qsTr("Main")
            height: 60
            background: Rectangle {
                color: tabBarMain.currentIndex === 0 ? "silver" : "#1e90ff"
            }
        }
        TabButton {
            id: tabButtonProfile
            text: qsTr("Profile")
            height: 60
            background: Rectangle {
                color: tabBarMain.currentIndex === 1 ? "silver" : "#1e90ff"
            }
        }
        TabButton {
            id: tabButtonSetting
            text: qsTr("Setting")
            height: 60
            background: Rectangle {
                color: tabBarMain.currentIndex === 2 ? "silver" : "#1e90ff"
            }
        }

        TabButton {
            id: tabButtonFactory
            text: qsTr("Factory Mode")
            height: 60
            background: Rectangle {
                color: tabBarMain.currentIndex === 3 ? "silver" : "#1e90ff"
            }
        }
    }

//    Material.theme: Material.Dark
//    Material.accent: Material.DeepOrange

//    StackLayout {
//        id: stackLayOut
//        anchors.left: slideBar.right
//        anchors.right: parent.right
//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
//        currentIndex: tabBar.currentIndex

//        PageMain {

//        }

//        PageProfile {

//        }

//        PageSettings {

//        }

//        PageFactory{

//        }
//    }

//    TabBar {
//        id: tabBar
//        anchors.right: parent.right
//        anchors.left: slideBar.right
//        anchors.bottom: parent.bottom
//        currentIndex: stackLayOut.currentIndex
//        TabButton {
//            id: tabButtonMain
//            text: qsTr("Main")
//        }
//        TabButton {
//            id: tabButtonProfile
//            text: qsTr("Profile")
//        }
//        TabButton {
//            id: tabButtonSetting
//            text: qsTr("Setting")
//        }

//        TabButton {
//            id: tabButtonFactory
//            text: qsTr("Factory Mode")
//        }
//    }

//    SlideBar {
//        id: slideBar
//    }
}
