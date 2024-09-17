const express = require('express');
const fs = require('fs');
const app = express();
const port = 3000;
const cors = require('cors');

app.use(cors());
const dataPath = './persone.json';

app.get('/persone', (req, res) => {
  fs.readFile(dataPath, 'utf8', (err, data) => {
    if (err) {
      res.status(500).send('Error reading file');
      return;
    }
    res.json(JSON.parse(data));
  });
});

app.get('/persone/:id', (req, res) => {
    const id = parseInt(req.params.id, 10);
    fs.readFile(dataPath, 'utf8', (err, data) => {
      if (err) {
        res.status(500).send('Error reading file');
        return;
      }
      const persone = JSON.parse(data);
      const persona = persone.find(p => p.id == id);
      if (persona) {
        res.json(persona);
      } else {
        res.status(404).send('Person not found');
      }
    });
  });

app.listen(port, () =>{
    console.log(`Server running on http://localhost:${port}`);
})