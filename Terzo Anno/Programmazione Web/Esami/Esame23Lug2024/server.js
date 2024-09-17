const express = require('express');
const fs = require('fs');  // Modulo per leggere file
const app = express();
const port = 3000;
const cors = require('cors');
app.use(cors());

// Legge direttamente il file JSON
const articoli = JSON.parse(fs.readFileSync('articoli.json', 'utf8'));

// Endpoint GET /articoli
app.get('/articoli', (req, res) => {
  res.json(articoli);  // Restituisce l'array di articoli
});

// Endpoint GET /autori
app.get('/autori', (req, res) => {
  const autori = articoli.map(articolo => articolo.autore);  // Estrae gli autori
  res.json([...new Set(autori)]);  // Restituisce autori unici
});

// Avvia il server sulla porta 3000
app.listen(port, () => {
  console.log(`Server in ascolto su http://localhost:${port}`);
});
