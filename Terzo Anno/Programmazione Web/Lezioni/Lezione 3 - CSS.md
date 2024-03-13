	CSS: Cascading Style Sheets
CSS è un linguaggio facente parte della W3C, e definisce la presentazione del documento HTML ( o in generale XML), cioè come un documento viene visualizzato in contesti diversi.
# Regole del CSS
```CSS
h1 { color: green; }
p { font-size: small; color: black;}
```
1. *Selector* ( selettore ):
	 - Identifica l'elemento o gli elementi a cui applicare lo stile.
2. *Declaration* ( dichiarazione ):
	- Costituita da una coppia proprietà-valore separati dai `:`
	- Fornisce l'istruzione di rendering
	- Ogni dichiarazione è delimitata da un `;`
![[Pasted image 20240313150322.png|center|300]]

## Stili nell'head
>External Style Sheet
>- Collegato mediante il tag `<link>`
>- File txt con estensione .css dove scriviamo le regole

```HTML
<head>
	<link rel="stylesheet" type="text/css" href="mystyle.css">
</head>
```
$\Downarrow$
```CSS
body{
	background-color: lightblue;
}

h1{
	color: navy;
	margin-left: 20px;
}
```

>Internal Style Element
>- Regole nell'head tra i tag `<style>...</style>`

```HTML
<head>
	<style>
		body{
			background-color: linen;
		}
		h1{
			color: maroon;
			margin-left: 40px;
		}
	</style>
</head>
```

### Stile inline
```HTML
<!DOCTYPE html>
<html>
	<head>
	</head>
	<body>
		<h1 style="color:red;">This is a Heading</h1>
		<p style="font-size:1.1em;font-family:sans-serif;"> 
		This is a paragraph</p>
	</body>
</html>
```

Definisco lo stile usando l'attributo `<style>`
***NON VA USATO***
## Selettori semplici
### Selettore elemento
