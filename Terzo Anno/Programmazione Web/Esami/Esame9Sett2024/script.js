// Esegui il codice solo quando il DOM è completamente caricato
document.addEventListener('DOMContentLoaded', function() {
    
    // Seleziona gli elementi HTML
    const countElement = document.getElementById('count');
    const incrementBtn = document.getElementById('increment');
    const decrementBtn = document.getElementById('decrement');
    const changeColorBtn = document.getElementById('changeColor');
    const header = document.querySelector('header');
    const footer = document.querySelector('footer');

    // Funzione per aggiornare il contatore nella pagina
    function updateCounterDisplay(value) {
        countElement.textContent = value;
    }

    // Carica il contatore iniziale con una richiesta GET
    fetch('http://localhost:3000/counter')
        .then(response => response.json())
        .then(data => {
            updateCounterDisplay(data.counter);
        })
        .catch(error => console.error('Errore nel caricamento del contatore:', error));

    // Incrementa il contatore al click sul bottone "Incrementa"
    incrementBtn.addEventListener('click', function() {
        fetch('http://localhost:3000/increase', {
            method: 'POST'
        })
        .then(response => response.json())
        .then(data => {
            updateCounterDisplay(data.counter);
        })
        .catch(error => console.error('Errore durante l\'incremento del contatore:', error));
    });

    // Decrementa il contatore al click sul bottone "Decrementa"
    decrementBtn.addEventListener('click', function() {
        fetch('http://localhost:3000/decrease', {
            method: 'POST'
        })
        .then(response => response.json())
        .then(data => {
            updateCounterDisplay(data.counter);
        })
        .catch(error => console.error('Errore durante il decremento del contatore:', error));
    });

    // Cambia i colori dell'header e del footer al click sul bottone "Cambia Colori"
    changeColorBtn.addEventListener('click', function() {
        fetch('http://localhost:3000/colors')
        .then(response => response.json())
        .then(data => {
            header.style.backgroundColor = data.background;
            header.style.color = data.text;
            footer.style.backgroundColor = data.background;
            footer.style.color = data.text;
        })
        .catch(error => console.error('Errore nel caricamento dei colori:', error));
    });

});
