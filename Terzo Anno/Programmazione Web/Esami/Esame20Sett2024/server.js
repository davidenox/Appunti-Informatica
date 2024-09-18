const express = require('express');
const fs = require('fs');
const cors = require('cors');

const app = express();
const port = 3000;
app.use(cors());








app.listen(port, () =>{
    console.log(`Server in ascolto su http://localhost:${port}`);
})