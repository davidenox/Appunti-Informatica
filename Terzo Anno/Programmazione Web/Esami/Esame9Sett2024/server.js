const express = require('express');
const app = express();
const cors = require('cors'); // Importa il pacchetto cors
const port = 3000;

app.use(cors()); // Abilita CORS per tutte le richieste

let counter = 5;
const colors = {
  background: "#882200",
  text: "#44DDAA"
};

// Endpoint GET /counter
app.get('/counter', (req, res) => {
  res.json({ counter });
});

// Endpoint POST /increase
app.post('/increase', (req, res) => {
  counter++;
  res.json({ counter });
});

// Endpoint POST /decrease
app.post('/decrease', (req, res) => {
  counter--;
  res.json({ counter });
});

// Endpoint GET /colors
app.get('/colors', (req, res) => {
  res.json(colors);
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
