const sqlite3 = require('sqlite3').verbose();

let db = new sqlite3.Database('../PlayerData.db',sqlite3.OPEN_READWRITE, (err) => {
    if (err) {
      return console.error(err.message);
    }
    console.log('Connected to the in-memory SQlite database.');
  });

  db.serialize(()=>{
    db.each('SELECT name as name, value as value FROM PlayerValue ORDER BY Game ASC',(err,row)=>{
        if(err)
        {
            console.log(err.message);
        }
        console.log("name: "+row.name + "\t"+row.value );
    });
  });

  db.close(()=>{
    // if(error)
    // {
    //     console.log(err.message);
    // }
    console.log("close database");
  });