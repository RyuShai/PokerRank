import QtQuick 2.7

Item {
    height: parent.height
    width: parent.width
    ListView{
        id: playerList
        width: maximumWidth
        height: maximumHeight

        model: myModel
        delegate:playerListDelegate


//        Component.onCompleted: console.log("count: "+ model[0].name)
    }
    Component{
        id: playerListDelegate
                Rectangle{
                    height: 25
                    width: 100
                    Text {
                        text: model.modelData.name
                    }
                }

    }
}
