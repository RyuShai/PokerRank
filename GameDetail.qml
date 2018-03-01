import QtQuick 2.0
import QtCharts 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import "Calculte.js" as Cal
Item {
    property var listPlayer: playerControl.playerData
    property var listPlayerValue: []
    property var repeaterIndex: 0
    height: 821
    width: 411
    x:0
    y:0
    //    clip:true
    ScrollView{
        height: parent.height
        width: parent.width
        ColumnLayout{
            id:root
            spacing: 2
            height: parent.height
            RowLayout{
                height: 25
                implicitWidth:  411
                Layout.fillHeight: true
                Button{
                    text:"add new"
                    Layout.fillWidth: true
                    height: 25
                    width: parent.width
                    onClicked:{
                        popup.open()
                    }

                }
                Button{
                    text:"delete"
                    Layout.fillWidth: true
                    height: 25
                    width: parent.width
                    onClicked:{
                        console.log("index "+ repeaterIndex )
                       playerControl.DeletePlayer(repeaterIndex)
                    }
                }

                Row{
                    Text {
                        font.bold: true
                        text: "game "
                    }
                    TextEdit{
                        id: gameNumber
                        text:playerControl.game
                        font.bold: true
                    }
                }

                Button{
                    text:"finished"
                    anchors.right: parent.right
                    Layout.fillWidth: true
                    height: 25

                    onClicked: {
                        for(var i=0; i<listPlayer.length;i++)
                        {
//                            console.log("finished: "+ listPlayerValue[i] + " name: "+ listPlayer[i].name)
                            playerControl.InsertPlayerValue(listPlayer[i].name, parseInt(listPlayerValue[i],10),gameNumber.text )
                        }
                    }
                }

            }
            Repeater{
                id: repeatPlayer
                model: listPlayer.length
                GridLayout{
                    columns: 3
                    Button{
                        id: playerName
                        text: listPlayer[index].name
                        leftPadding: 0
                        onClicked: {
                            if(Cal.getListScoreSize(playerScore.text)==6)
                            {
                                playerScore.text = Cal.getTotalScore(playerScore.text) + " 200"
                            }
                            else
                            {
                                playerScore.text = playerScore.text+" 200";
                            }


                        }

                        width: 50
                    }
                    TextEdit{
                        id: playerScore
                        text: "200 "
                        width: playerName.width
                        anchors.bottomMargin: 10
                        Layout.fillWidth: true
                        onCursorVisibleChanged: {
                            if(cursorVisible)
                            {
                                selectAll()
                            }repeaterIndex = index
                        }

                    }

                    Label{
                        id:playerResult
                        //                        width: playerName.width
                        text:Cal.getTotalScore(playerScore.text)
                        background: Rectangle{
                            color: "yellow"
                        }
                        Layout.fillWidth: true
                        onTextChanged: {
                            listPlayerValue[index]=text;
                        }
                    }
                }
            }


            Component.onCompleted: {
                console.log("width: "+ root.width)
            }
        }
    }
    Popup {
        id: popup
        x: 100
        y: 100
        width: 230
        height: 300
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
        ColumnLayout{
            TextEdit{
                id: newPlayerName
                Layout.fillWidth: true
                text: "edit here"
                selectByMouse: true
                onCursorVisibleChanged: {
                    if(cursorVisible)
                        newPlayerName.selectAll()
                }

                Rectangle{
                    anchors.fill: parent
                    color: "blue"
                    opacity: 0.3
                }
            }
            RowLayout{
                width: 200
                Layout.fillWidth: true
                Button{
                    text:"ok"
                    Rectangle{
                        anchors.fill: parent
                        color: "red"
                        opacity: 0.3
                    }
                    Layout.fillWidth: true
                    onClicked: {
                        playerControl.AddPlayer(newPlayerName.text);
                        popup.close()
                    }
                }
                Button{
                    Layout.fillWidth: true
                    Rectangle{
                        anchors.fill: parent
                        color: "yellow"
                        opacity: 0.3
                    }
                    text: "cancel"
                    onClicked: {
                        popup.close()
                    }
                }
            }
        }
    }
}
