import QtQuick 2.7
import QtCharts 2.2
import "Calculte.js" as Cal
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
            id: rootDelegate
            height: 200
            //            width: maximumWidth
            color: index%2>0?"green":"red"
            property var listValue: model.modelData.value
            property var listDate: model.modelData.date
            Row{
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
                Rectangle{
                    color:rootDelegate.color
                    width: 400
                    height: 200
                    ChartView{
                        height: 100
                        width: 100
                        //                        title:model.modelData.name
                        anchors.fill: parent
                        antialiasing: true
                        LineSeries{
                            id: lineChart
                            name:model.modelData.name
                            axisX:ValueAxis{
                                min:0
                                max: Cal.biggest(rootDelegate.listValue)
                                Component.onCompleted: {console.log(Cal.biggest(rootDelegate.listValue) )}
                            }
                            axisY:ValueAxis{
                                min:0
                                max: Cal.biggest(rootDelegate.listValue) }
                            Component.onCompleted: {
                                Cal.printArray(rootDelegate.listDate)
                                for (var i = 0; i <= rootDelegate.listValue.length; i++) {
                                    lineChart.append(rootDelegate.listValue[i],rootDelegate.listValue[i]);
                                    //                series2.append(i, Math.random());
                                }
                            }
                        }
                    }
                }
            }

        }
    }
}
