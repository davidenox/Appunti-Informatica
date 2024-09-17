document.addEventListener('DOMContentLoaded', function(){
    fetch('http://localhost:3000/persone')
        .then(response => response.json())
        .then(data => {
          const userList = document.getElementById('lista');
          data.forEach(person => {
            const li = document.createElement('li');
            li.textContent = `${person.nome} ${person.cognome}`;
            li.addEventListener('click', () => {
              alert(`Nome: ${person.nome} ${person.cognome}, Età: ${person.età}`);
            });
            userList.appendChild(li);
        });
    });

});

function updateColors() {
    document.body.style.backgroundColor = '#00796b';
    document.querySelectorAll('nav a').forEach(link => {
      link.style.color = '#313131';
    });
  }




