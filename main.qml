import QtQuick 2.9
import QtQuick.Controls 2.2
import QtCharts 2.2
import QtQuick.Window 2.2
ApplicationWindow {
    id:root
    visible: true
//    height:  Screen.desktopAvailableHeight
//    width:   Screen.desktopAvailableWidth
    height: 821
    width:  411
    maximumHeight: height
    maximumWidth: width
    title: qsTr("Tabs")

    SwipeView {
        id: swipeView
        anchors.fill: parent
//        currentIndex: tabBar.currentIndex
        onCurrentIndexChanged: {
        }

        PlayerDetail{

        }
        GameDetail{

        }
    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex

//        TabButton {
//            text: qsTr("Page 1")
//        }
//        TabButton {
//            text: qsTr("Page 2")
//        }
//    }
    Component.onCompleted: {
        console.log("application: "+ Screen.desktopAvailableHeight +" "+ root.width)
    }
}

