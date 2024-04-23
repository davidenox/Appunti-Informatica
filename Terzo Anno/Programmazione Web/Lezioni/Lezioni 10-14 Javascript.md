# Cos'è Javascript
Javascript è un linguaggio di programmazione nato come linguaggio semplice per i non sviluppatori.
## Ruolo di js
*Client side*: praticamente monopolista;
*Server side*: NodeJs.
## Cosa fa JS
- *Cambiare elementi e stili in una pagina*
- *Comunicazione asincrona*
	- Invio dati senza ricaricare la pagina o senza interazione con l'utente
- *Altro*
	- Test browser capabilities ed adattamente
### Cosa fa e cosa non fa
>[!important]- Cosa fa
>- Modifica elementi della pagina
>- Interagisce con un server remoto
>- Reagisce ad azioni dell'utente
>- Imposta cookie e contenuti locali ( file storage )
>- Disegna sulla pagina

>[!warning]- Cosa non fa ( nei browser )
>- Accede ai file locali del computer
>- Interagisce con qualunque server remoto

### JS lato server: NodeJS
Si tratta di un *back-end* javascript runtime environment, permettendo di utilizzare uno stesso linguaggio sia client-side che server-side.
#### Framework famosi (client side)
- ExtJS
- Knockout
- Backbone
- Angular
- React
- Vue.js
# Hello World!
## Aggiungere Js ad una pagina web
```HTML
<script>
	//codice
</script>
```
$\Uparrow$ METODO BRUTTO $\Uparrow$
$\Downarrow$METODO GIUSTO $\Downarrow$
```HTML
<script src="myscript.js"></script>
```
# Lavorare con le variabili
```Javascript
// commento
let myName = "Giovanni"; //variabile con stringa
let myNumber = 5; //variabile con intero
let myVar; //variabile non inizializzata
myVar = myNumber; //assegnazione
console.log(myVar); //stampa del risultato
```
## Tipi di dato
Ogni dato appartiene ad un *tipo*:

| Codice               | Spiegazione                                        |
| -------------------- | -------------------------------------------------- |
| `let test = 5;`      | La variabile è un *numero*. Operazioni: + - * / %  |
| `let test = "ciao";` | La variabile è una *stringa*. Concatenazione con + |
| `let test = true;`   | La variabile è *Booleana*. Inverso con !           |
| `let test;`          | La variabile è *undefined*                         |
| `let test = null`    | La variabile è *null*                              |
### Conversioni - funzioni utili
>`parseInt()`
>- *Descrizione* : Analizza l'argomento di una stringa e restituisce un intero del raggio specifico.
>- *Sintassi*: `parseInt(string, radix)`

>`parseFloat()`
>- *Descrizione* : Analizza l'argomento di una stringa e restituisce un numero a virgola mobile.
>- *Sintassi*: `parseInt(string)`

- Conversione di un numero in una stringa: `num.toString();`
- Regolazione del numero di cifre decimali
	- `let pi = (3,141592).toFixed(2)`
	- `> 3.14`

> Costanti
> `const prefix = 06; //read only`

# Interazione base
- `alert`:
![[Pasted image 20240423151652.png|center|500]]
- `prompt`
![[Pasted image 20240423151723.png|center|500]]
- `confirm`
![[Pasted image 20240423151815.png|center|500]]
# Istruzioni di base
	branch and loop
## Operazioni di comparazione

| Operazione              | Significato                                              |
| ----------------------- | -------------------------------------------------------- |
| `==` e `!=`             | *Uguale* e *non uguale*                                  |
| `>` e `>=` e `<` e `<=` | *Maggiore*, *maggiore-uguale*, *minore*, *minore-uguale* |
| `===` e `!==`           | *Identico* o *non identico* (stesso dato e tipo)         |
## Operatori logici

| Operatore | Logico |
| --------- | ------ |
| `&&`      | AND    |
| \|\|      | OR     |
| !         | NOT    |
## Funzioni
Slide 51