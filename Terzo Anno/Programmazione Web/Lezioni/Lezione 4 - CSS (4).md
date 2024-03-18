# Formattazione
**Proprietà relative ai font**: font-family, font-size, font-style,...
**Proprietà relative al testo**: color, line-height, text-align,...
## Font
### Font family
Si fornisce una lista di "typeface" da applicare al testo:
```CSS
body { font-family: Arial;}
code { font-family: Courier, monospace;}
p { font-family: "Times New Roman", Times, serif }
```

**Regole**:
- Tutti i font cominciano con la lettera maiuscola, tranne i font generici;
- Sono separati da virgole;
- Se il loro nome contiene degli spazi, vanno tra virgolette.
### Font e OS
![[Pasted image 20240318112714.png|center|500]]

>[!info]- Non tutti i font sono disponibili, poiché dipendono dal SO e se sono installati nel PC.

#### Strategia di stack
Si specifica il font desiderato e quindi delle alternative simili. ES:
``` CSS
 font-family: Verdana, Geneva, sans-serif;
 font-family: Georgia, "Times New Roman",Times, serif;
 font-family: "Courier New", Courier, monospace;
 font-family: Arial, Helvetica, sans-serif;
 font-family: Tahoma, Geneva, sans-serif;
 font-family: "Trebuchet MS", Arial, Helvetica, sans-serif;
 font-family: "Arial Black", Gadget, sans-serif;
 ...
 ```

### Web Font
![[Pasted image 20240318113040.png|center|500]]
# Testo e c0lori
## Colore
Il colore del testo viene ereditato dagli elementi e non influenza solo il testo. Può essere indicato in vari modi:
```CSS
h1 { color: grey;}
h1 { color: #666666;}
h1 { color: #666;}
h1 { color: rgb(102,102,102);}
```
### Nomi dei colori
![[Pasted image 20240318114742.png|center|500]]
## Colori RGB
Si specifica il colore con tre valori numerici: 
- Quantità di rosso, verde e blu
- Sono tre byte
I valori per colore si esprimono in:
- Percentuale del colore;
- Valore numerico:
	- Decimale da 0 a 255;
	- Esadecimale da `0x00` a `0xFF`
![[Pasted image 20240318115255.png|center|300]]
![[Pasted image 20240318115321.png|center|500]]
### RGBa
Si tratta di una combinazione di RGB + canale alfa, che controlla il livello di trasparenza:
![[Pasted image 20240318115426.png|center|500]]
# Testo
work in progress
