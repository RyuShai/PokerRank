function biggest(array) {
    var value=0;
      for(var i=0; i<array.length;i++)
      {
          if(array[i]>value)
              value = array[i]
      }
      return value
}

function smallest(array) {
    var value=10000;
      for(var i=0; i<array.length;i++)
      {
          if(array[i]<value)
              value = array[i]
      }
      return value
}

function getDay(strDay)
{
    //console.log("getDay: "+strDay)
    var result = strDay.split("-");

    result = result[result.length-1];
    //console.log("getDay result: "+ result)
    return Number(result)
}
function getMonth(strDay)
{
    //console.log("getMonth: "+strDay)
    var result = strDay.split("-");

    result = result[1];
    //console.log("getMonth result: "+ result)
    return Number(result)
}
function getYear(strDay)
{
    //console.log("getYeah: "+strDay)
    var result = strDay.split("-");
    result = result[0];
    //console.log("getYeah result: "+ result)
    return Number(result)
}

function printArray(array)
{
    for(var i=0; i<array.length;i++)
    {
       //console.log("printArray: "+array[i])
    }
}

function getTotalScore(strScore)
{
    var score=0;
    var listScore = strScore.split(" ");
    for(var i=0; i<listScore.length;i++)
    {
        score+=Number(listScore[i])
    }
    return score
}

function getListScoreSize(strScore)
{

    var listScore = strScore.split(" ");

    return listScore.length
}

function addNewPlayer(listPlayer, player)
{
    listPlayer.add(player)
    return listPlayer
}
