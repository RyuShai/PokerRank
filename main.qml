import QtQuick 2.9
import QtQuick.Controls 2.2
import QtCharts 2.2
ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Tabs")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        PlayerDetail{
            height: maximumHeight
            width: maximumWidth
        }
        GameDetail{
            width: maximumWidth
            height: maximumHeight
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }

}
