import QtQuick 2.0
import QtQuick.Controls 2.2
Item {
    property alias name: playerName
    property alias score: playerScore
    Column{
       Button{
           id: playerName
       }
       Label{
           id: playerScore
           text: "1\n2"
       }
       Label{
           id:playerResult
           text:"result"
       }
    }
}
