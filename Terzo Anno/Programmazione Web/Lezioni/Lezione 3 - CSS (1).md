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
Seleziono tutti gli elementi di quel tipo. ES:
```CSS
p {
	color: red;
	text-align: center;
}
```

### Selettore classe
Seleziono tutti gli elementi di una classe. Li individuo con l'attributo class ed un identificatore, e uso come selettore l'identificatore preceduto dal punto. ES:
```HTML
<h1 class="center">Heading</h1>
<p class="center">A paragraph</p>
```
```CSS
.center{
	text-align: center;
	color: red;
}
p.center{
	text-align: center;
	color: green;
}
```

### Selettore id
Seleziono l'elemento con quell'id. ES:
```HTML
<p id="para1">...</p>
```
```CSS
#para1{
	text-align: center;
	color: red;
}
```

## Raggruppare i selettori
```CSS
h1, h2, p{
	text-align: center;
	color: red;
}
```

# Selettori e DOM
## Relazioni nel DOM
- **Descendant** - discendenti:
	- Gli elementi contenuti in un elemento sono i  suoi discendenti.
- **Child** - figli:
	- Discendenti diretti, viceversa sono i genitori ( parent ).
- **Ancestor** - antenati:
	- Gli elementi sopra nell'albero.
- **Parent** - genitore:
	-  Elementi direttamente sopra.
- **Siblings** - fratelli:
	- Elementi con lo stesso parent.
![[Pasted image 20240313162141.png|center|500]]
## Selettori composti
1. Selettori per **descendant** (*spazio*).
2. Selettori per **child** (*>*).
3. Selettori per **adjacent siblings** (*+*).
	1. Il fratello immediatamente successivo.
4. Selettori per **general siblings** ($\sim$).
	1. Tutti i fratelli successivi.
