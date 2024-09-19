document.addEventListener('DOMContentLoaded',()=>{
    fetch('http://localhost:3000/data')
    .then(response => response.json())
    .then(data => {
        const container = document.getElementById('container');
        data.forEach(item => {
            const card = document.createElement('div');
            card.classList.add('card');
            card.innerHTML = `
            <h2>${item.name}</h2>
            `;
            container.appendChild(card);
            });
        })
});