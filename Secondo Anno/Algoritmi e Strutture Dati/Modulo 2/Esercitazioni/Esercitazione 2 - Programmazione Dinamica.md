# Problema 1
Valter Bianchi, stecca di cioccolata. La stecca di cioccolata può essere venduta tutta intera o può essere spezzata in segmenti più piccoli da vendere separatamente. La lunghezza della stecca è di $L$ centimentri, con $L$ intero. Si assuma che nello spezzare la stecca la lunghezza dei pezzi ottenuti debba essere ancora un numero intero. Il guadagno che Valter Bianchi riesce a fare se vende un pezzo lungo $t$ centimetri è $G(t),t=1,\dots,L.$ 
*Progettare un algoritmo di programmazione dinamica che aiuti il signor Valter Bianchi a guadagnare il più possibile*. La complessità dell'algoritmo deve essere polinomiale in $L$.

**Esempio di istanza**:
![[Pasted image 20250402112628.png|center|500]]

$$OPT(j)=\max_{k=0,1,..,j-1}(G(j-k)+OPT(k)).$$
Dove $OPT(j)$: il guadagno massimo ottenibile da una stecca di cioccolata lunga $j$.

**Soluzione discussa** [[https://www.mat.uniroma2.it/~guala/discussi.pdf|qui]].

# Problema 2

Si vuole dotare una pista ciclabile di un servizio WiFi. Per fare questo si devono installare dei ripetitori wireless. La pista ciclabile è lunga $n$ tratte. Il costo di installazione di un ripetitore non è uniforme e dipende dalla tratta in cui si installa il ripetitore e dal tipo di ripetitore. In particolare, ci sono due tipi di ripetitore, uno di tipo *high*($H$) ed uno di tipo *low*($L$).

Se nella tratta $i$ si installa:
- Un ripetitore di tipo $L$, il ripetitore è in grado di fornire il servizio alle tratte $i$ e $i+1$. Il *costo* di installazione è $L_i$.
- Un ripetitore di tipo $H$, il ripetitore è in grado di fornire il servizio alle tratte $i$, $i+1$ e $i+2$. Il costo di installazione è $H_i\ge L_i$.
*Progettare un algoritmo di programmazione dinamica che calcoli una soluzione di costo totale minimo che fornisce il servizio a tutte le tratte*.

![[eserc2.gif|center|500]]

**Idea**:
- "Indovinare" il tipo di ripetitore instalato nella soluzione ottima nella tratta $1$
- Questo copre alcune tratte che ora non è più necessario coprire
- Coprire le tratte "restanti" all'ottimo
- *Attenzione*: Non è detto che nell'ottimo  non ci sia un ripetitore anche nella tratta 2!
![[Pasted image 20250402115545.png|center|500]]

## Soluzione
**Sottoproblemi:**
	$Opt[i]$: costo minimo per coprire le tratte $i, i+1,\dots,n$.
**Soluzione cercata**:
	$Opt[1]$
**Equazione di Bellman**:
	$Opt[i]=\min\{L_i+Opt[i+1],L_i+Opt[i+2],H_i+Opt[i+3]\}$
Casi base: 
- $Opt[i]=0\text{ se } i\gt n$ .

```pseudo
CalcoloCostoInstallazione:
	Opt[n+1]=Opt[n+2]=0
	for i=n down to 1 do
		Opt[i]=min{L_i+Opt[i+1],L_i+Opt[i+2],H_i+Opt[i+3]}
	return Opt[1]
```

**Tempo di esecuzione**: $O(n)$
- L'algoritmo calcola solo il valore della soluzione ottima
- Dato il vettore $Opt[]$ sapete ricostruire in tempo $O(n)$ anche la soluzione?
