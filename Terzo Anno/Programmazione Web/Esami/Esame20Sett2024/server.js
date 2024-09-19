const express = require('express');
const fs = require('fs');
const cors = require('cors');

const app = express();
const port = 3000;
app.use(cors());

app.get('/data', (req,res)=>{
    const data = fs.readFileSync('data.json', 'utf8');
    res.json(JSON.parse(data));
    
});

app.get('/data/:id', (req,res)=>{
    const id = req.params.id;
    const data = fs.readFileSync('data.json', 'utf8');
    const jsonData = JSON.parse(data);
    const item = jsonData.find(item => item.id === parseInt(id));
    if(item){
        res.json(item);
    }else{
        res.status(404).json({message: 'Item not found'});
    }
})





app.listen(port, () =>{
    console.log(`Server in ascolto su http://localhost:${port}`);
})