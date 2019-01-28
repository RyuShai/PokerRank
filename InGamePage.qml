import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import GameModel 1.0
Rectangle {
    color: "#acd7e3"
    ColumnLayout{
        width: parent.width
        height: parent.height
        Rectangle{
            id: top
            color: "grey"
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: 40
            Layout.fillWidth: true
            Row{
                id:row
                spacing: 10
                width: parent.width
                height: parent.height
                Component.onCompleted: {console.log(width)}
                Label{
                    text: "Buy-in:"
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                Rectangle{
                    radius: 10
                    width: 100
                    height: 25
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.margins: 20
                    TextInput{
                        id: buyIn
                        text: "200"
                        cursorVisible: true
                        anchors.centerIn: parent
                    }
                }
                Label{
                    id:totalPlayerValue
                    text:"should it zero"
                    anchors.verticalCenter: parent.verticalCenter
                    x: parent.width/2 -width/2
                    font.bold: true
                    background: Rectangle{
                        color: "yellow"
                        anchors.margins: 10
                        radius: 5
                    }
                }
                Button{
                    text: "Save"
                    Layout.alignment: Qt.AlignRight
//                    rightPadding: 100
                    x: parent.width - width
                }
            }
        }
        Rectangle {
            id: playerList
            Layout.preferredHeight:100
            Layout.preferredWidth: parent.width
            Layout.fillWidth: true
            Layout.fillHeight: true
            ListView{
                height: parent.height
                width: parent.width
                model: GameModel{
                    list: controller
                }

                delegate: Item{
                    property variant dataModel : []
                    property string playerName: model.name
                    id:delegate
                    width: playerList.width
                    height: 30
                    Row{
                        spacing: 5
                        Button{
                            width: 20
                            height: 20
                            text: "+"
                            onClicked: {
                                delegate.dataModel.push("+"+buyIn.text)
                                repeater.model = delegate.dataModel.length
                                console.log(delegate.dataModel.length)
                                totalValue.text = totalValue.totalValue()
                            }
                        }
                        Button{
                            width: 20
                            height: 20
                            text: "-"
                            onClicked: {
                                delegate.dataModel.push("-"+buyIn.text)
                                repeater.model = delegate.dataModel.length
                                totalValue.text = totalValue.totalValue()
                            }
                        }
                        Label{
                            text: model.name
                            font.bold: true
                        }
                        Repeater{
                            id:repeater
                            model: delegate.dataModel.length

                            TextInput{
                                text: delegate.dataModel[index]
                                onTextEdited: {
                                    console.log("text edited")
                                    if(text === "")
                                    {
                                        delegate.dataModel.splice(index,1)
                                        console.log("model after delete: "+ delegate.dataModel.length + " "+repeater.count)
                                        totalValue.text = totalValue.totalValue()
                                        repeater.model = delegate.dataModel.length
                                    }
                                }
                            }
                            onModelChanged: {
//                                console.log(model.name)
                                controller.updateDayGame(playerName, parseInt(totalValue.text))
                            }
                        }

                        Label{
                            id:totalValue
                            function totalValue()
                            {
                                var total=0;
                                for(var i=0; i<delegate.dataModel.length;i++)
                                {
                                    total+= parseInt(delegate.dataModel[i]);
                                }
                                return total.toString()
                            }
                            text: ""
                            font.bold: true
                            Layout.alignment: Qt.AlignRight
                            background: Rectangle{
                                color: "yellow"
                            }
                        }
                    }
                }
            }
        }

    }
}
