document.addEventListener('DOMContentLoaded',()=>{

    // Prima richiesta
    fetch('http://localhost:3000/task')
    .then(response => response.json())
    .then(data => {
        const main = document.getElementById('main');
        data.forEach(item => {
            const btn = document.createElement('button');
            const card = document.createElement('div');
            card.classList.add('card');
            card.innerHTML = `
            <h2>${item.text}</h2>
            <button> Completa </button>
            `;
            if(item.completed == true){
                //btn.classList.add('btnCompleted')
                card.innerHTML = `
                <h2>${item.text}</h2>
                <button style="backgound-color:grey"> Completa </button>
                `;
            }

            //main.appendChild(btn)
            main.appendChild(card);
            });
        })
});