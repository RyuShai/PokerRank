function biggest(array) {
    var bigest=0;
      for(var i=0; i<array.length;i++)
      {
          if(array[i]>bigest)
              bigest = array[i]
      }
      return bigest
}
function printArray(array)
{
    for(var i=0; i<array.length;i++)
    {
       console.log(array[i])
    }
}
