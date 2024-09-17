async function load() {
    try {
        const resp = await fetch('http://localhost:3000/articoli');
        const articoli = await resp.json();
        
        articoli.forEach(articolo => {
            const sezione = document.createElement('section');
            sezione.classList.add('articolo');  // Aggiungi la classe "articolo"
            sezione.innerHTML = `
                <h1>${articolo.titolo}</h1>
                <p><strong> Autore: </strong>${articolo.autore}</p>
                <p>${articolo.contenuto}</p>
                <button style="background-color: grey;"> Mostra Dettagli </button>
            `;
            document.getElementById('main').appendChild(sezione);    

            // Aggiungi il listener per il pulsante "Mostra Dettagli" subito dopo averlo creato
            const button = sezione.querySelector('button');
            button.addEventListener('click', showDetails);
        });

        // Crea e aggiungi il pulsante "Mostra Autori"
        const button = document.createElement('button');
        button.id = 'showAuthors';
        button.textContent = 'Mostra Autori';
        button.style.cssText = 'background-color: #007bff; color: white; padding: 10px 20px; border: none; cursor: pointer; margin-top: 20px;';
        document.getElementById('main').appendChild(button);
        
        button.addEventListener('click', showAuthors);

    } catch (error) {
        console.error("Errore nel caricamento degli articoli:", error);
    }
}

load();

// Funzione per mostrare i dettagli dell'articolo
function showDetails(event) {
    const articolo = event.target.closest('.articolo');  // Trova l'elemento articolo più vicino
    
    if (articolo) {
        const titolo = articolo.querySelector('h1').textContent;
        const autore = articolo.querySelector('p strong').nextSibling.textContent.trim();
        const contenuto = articolo.querySelector('p:nth-of-type(2)').textContent;

        alert(`Titolo: ${titolo}\nAutore: ${autore}\nContenuto: ${contenuto}`);
    }
}

function showAuthors() {
    fetch('http://localhost:3000/autori')
      .then(response => response.json())
      .then(autori => {
        const lista = document.getElementById('lista-autori');
        lista.innerHTML = '';
        autori.forEach(autore => {
          const li = document.createElement('li');
          li.textContent = autore;
          lista.appendChild(li);
        });
        document.getElementById('modale').style.display = 'block';
        document.getElementById('overlay').style.display = 'block';
      });
  
    document.querySelector('.chiudi').addEventListener('click', function() {
      document.getElementById('modale').style.display = 'none';
      document.getElementById('overlay').style.display = 'none';
    });
}