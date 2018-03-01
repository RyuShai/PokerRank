import QtQuick 2.7
import QtCharts 2.2
import "Calculte.js" as Cal
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
ColumnLayout {
    id:root
    RowLayout{
        height: 25
        implicitWidth:  411
        Layout.fillHeight: true
        Button{
            id:previousYear
            text:"previous Year"
            height: 25
            Layout.fillWidth: true
        }

        Button{
            id:previousMonth
            text:"previous Month"
            height: 25
            Layout.fillWidth: true
        }
        Button{
            id:nextMonth
            text:"next month"
            height: 25
            Layout.fillWidth: true
        }
        Button{
            id:nextYear
            text:"next year"
            height: 25
            Layout.fillWidth: true
        }
    }



    ListView{
        id: playerList
        Layout.fillHeight: true
        //        opacity: 0.3
        //            height: maximumHeight
        model: playerControl.playerData
        delegate:playerListDelegate
        Layout.fillWidth: true
//        clip: true
        ScrollBar.vertical: ScrollBar{

        }
    }


    Component{
        id: playerListDelegate
        Rectangle{
            id: rootDelegate
            height: 220
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            width: parent.width
            property var listValue: model.modelData.value
            property var listDate: model.modelData.game
            ChartView{
                id: chart
                theme: ChartView.ChartThemeDark
                anchors.fill: parent
                antialiasing: true
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.bottomMargin: 0
                anchors.topMargin: 0
                animationOptions:ChartView.AllAnimations
                animationDuration: 1500
                DateTimeAxis{
                    id: dateTime
                    format: "yy/MM/dd"
                    max: new Date("2018/12/31")
                    min:new Date("2018/1/1")
                }

                LineSeries{
                    id: lineChart
                    name:model.modelData.name

                    axisX:ValueAxis{
                        min:0
                        max: playerControl.game
                        tickCount: 5
                    }
                    //                            axisX:dateTime
                    axisY:ValueAxis{
                        min:Cal.smallest(rootDelegate.listValue)
                        max: Cal.biggest(rootDelegate.listValue)
                        tickCount: 5
                    }


                    Component.onCompleted: {
                        Cal.printArray(rootDelegate.listDate)
                        //
                        //                                Cal.getMonth(rootDelegate.listDate[0])
                        for (var i = 0; i < rootDelegate.listValue.length; i++) {
                            console.log("listvalue: "+rootDelegate.listDate[i])
                            console.log("name: "+lineChart.name + " "+ rootDelegate.listDate[i]+ " "+rootDelegate.listValue[i])
                            //                                    lineChart.append(Cal.getDay(rootDelegate.listDate[i]),rootDelegate.listValue[i]);
                            lineChart.append(rootDelegate.listDate[i],rootDelegate.listValue[i]);
                            //                series2.append(i, Math.random());
                        }
                    }
                }
            }
        }
    }
}
