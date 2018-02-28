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
            ScrollBar.vertical: ScrollBar{

            }
        }


    Component{
        id: playerListDelegate
        Rectangle{
            id: rootDelegate
            height: 200
                        width: maximumWidth
            //            color: index%2>0?"green":"red"
            property var listValue: model.modelData.value
            property var listDate: model.modelData.date
//            Row{
                //                Text {
                //                    text: model.modelData.name
                //                    width: 100
                //                    Component.onCompleted: {
                ////                        var list = model.modelData.value;
                //                        for(var i= 0;i<listValue.length;i++)
                //                        {
                //                            console.log("indext: "+index+" "+ listValue[i])
                //                        }
                //                    }
                //                }
//                Rectangle{
//                    color:rootDelegate.color
//                    width: root.width
//                    height: 200
//                    anchors.bottomMargin: 0
                    ChartView{
                        height: 100
                        width: 100
                        theme: ChartView.ChartThemeDark
                        anchors.fill: parent
                        antialiasing: true
                        anchors.bottomMargin: 0
                        LineSeries{
                            id: lineChart
                            name:model.modelData.name
                            axisX:ValueAxis{
                                min:1
                                max: 31
                            }
                            axisY:ValueAxis{
                                min:Cal.smallest(rootDelegate.listValue)
                                max: Cal.biggest(rootDelegate.listValue)
                            }


                            Component.onCompleted: {
                                Cal.printArray(rootDelegate.listDate)
                                //                                console.log("listvalue: "+rootDelegate.listDate.length)
//                                Cal.getMonth(rootDelegate.listDate[0])
                                for (var i = 0; i < rootDelegate.listValue.length; i++) {
                                    console.log("name: "+lineChart.name + " "+ Cal.getDay(rootDelegate.listDate[i])+ " "+rootDelegate.listValue[i])
                                    lineChart.append(Cal.getDay(rootDelegate.listDate[i]),rootDelegate.listValue[i]);
                                    //                series2.append(i, Math.random());
                                }
                            }
                        }
                    }
//                }
//            }
        }
    }
}
