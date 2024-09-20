const express = require('express');
const fs = require('fs');
const cors = require('cors');

const app = express();
const port = 3000;
app.use(cors());

app.get('/task', (req,res)=>{
    const task = fs.readFileSync('task.json', 'utf8');
    res.json(JSON.parse(task));
    
});

app.get('/task/complete/:id', (req,res)=>{
    const id = req.params.id;
    const task = fs.readFileSync('task.json', 'utf8');
    const jsonData = JSON.parse(task);
    const item = jsonData.find(item => item.id === parseInt(id));
    if(item){
        // jsonData.forEach(item =>{
            // const itemCompleted = jsonData.find(item => item.completed == true);
            // if(itemCompleted){
            //     res.json(itemCompleted);
            // }
            
        // })
        res.json(item)
    }else{
        res.status(404).json({message: 'Item not found'});
    }
})





app.listen(port, () =>{
    console.log(`Server in ascolto su http://localhost:${port}`);
})