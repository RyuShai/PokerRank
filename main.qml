import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Window 2.0
ApplicationWindow {
    id: window
    visible: true
    width: 800//Screen.width
    height: 600//Screen.height
    title: qsTr("Stack")

    TabBar{
        id: bottomBar
        width: parent.width
        height: contentHeight
        position: TabBar.Footer
        Repeater{
            model: ["In Game","Statistic"]
            TabButton{
                text: modelData
            }
        }
        anchors.bottom: parent.bottom
    }

    StackLayout{
        id:stackView
        width: parent.width
        height: parent.height-bottomBar.height
        currentIndex:bottomBar.currentIndex
        InGamePage{
            Layout.preferredHeight: stackView.height-10
        }

        Rectangle{
            Text {
                text: qsTr("Statistic Page")
            }
        }
    }


    Component.onCompleted: {console.log(window.width+" "+window.height)}
}
