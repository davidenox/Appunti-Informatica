# Async Await
## async
```js
async function f(){
	return 1;
}
```
`async` prima di una funzione significa che la funzione ritorna **SEMPRE** una *promise*.
```js
async function f(){
	return 1;
}
f().then(alert); //1
```

```js
async function f(){
	return Promise.resolve(1);
}
f().then(alert); //1
```
## await
Rende il codice asincrono ed aspetta la risposta
```js
// funziona solo dentro funzioni async
let value = await promise;
```
Es.
```js
async function f(){
	let promise = new Promise((resolve,reject) => {
		setTimeout(() => resolve("Done"), 1000)
	});
	
	let result = await promise; // asoetta finché la promise non si risolve
	alert(result);//Done 
}
f();
```

### Error handling : `try`/`catch`
Nel caso di **rigetto** una promessa rilascia un errore. Si può recuperare l'errore con try/catch:
```js
async function f(){
	try{
		let response = await fetch("http://no-such-url");
	} catch(err) {
		alert(err); //TypeError: failed to fetch
	}
}
f();
```
## Fetch con Async/Await
### GET
29