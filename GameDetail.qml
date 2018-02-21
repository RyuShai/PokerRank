import QtQuick 2.0
import QtCharts 2.2
Item {
    ChartView{
        title:"test"
        anchors.fill: parent
        antialiasing: true
        LineSeries{
            name:"LineSeries"
            XYPoint{x:0;y:0}
            XYPoint{x:1;y:1}
        }
    }
}
