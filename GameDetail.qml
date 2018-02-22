import QtQuick 2.0
import QtCharts 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import "Calculte.js" as Cal
Item {
    property var listPlayer: myModel

    ScrollView{
        anchors.fill: parent
        Row{
            id:root
            spacing: 2
            Repeater{
                model: listPlayer.length
                Column{
                    Button{
                        id: playerName
                        text: listPlayer[index].name
                        leftPadding: 0
                        onClicked: {
                            playerScore.text = playerScore.text+"\n200";
                        }
                    }
                    TextEdit{
                        id: playerScore
                        text: "200\n200"
                        width: playerName.width
                        anchors.bottomMargin: 10
                    }

                    Label{
                        id:playerResult
                        width: playerName.width
                        text:Cal.getTotalScore(playerScore.text)
                        background: Rectangle{
                            color: "yellow"
                        }
                    }
                }
            }
            Component.onCompleted: {
                console.log("width: "+ root.width)
            }
        }
    }
}
