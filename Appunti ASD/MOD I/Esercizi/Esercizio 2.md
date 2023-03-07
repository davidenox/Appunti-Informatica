# Complessità nel caso medio
## Testo
Analizazre la complessità nel caso medio del primo algoritmo di pesatura (Alg1) visto nella prima lezione. Rispetto alla distribuzione di probabilità sulle istanza, si assuma che la moneta falsa possa trovarsi in modo equiprobabile in una delle qualsiasi delle n posizioni.

## Svolgimento
Data la parola chiave "equiprobabile" possiamo dedurre che la probabilità sulle istanze, quindi $P(\mathcal{I})$è uguale a $\frac{1}{n}$

Il tempo tempo($\mathcal{I}$) su ogni istanza di dimesione n è 1 se la la pos della moneta è uguale a 1,j-1 altrimenti

Di conseguenza possiamo utilizzare la formula e il costo nel caso medio è pari a:

$T_{avg}(n)=\sum_{j=1}^n \frac{1}{n}\cdot tempo(I)=(1/n)(1+\sum_{j=2}^n(j-1))$
$=(1/n)(1+\sum_{j=1}^{n-1}j)=(1/n)(1+(n-1)n/2)=\frac{1}{n}+\frac{n-1}{2}\implies \frac{n-1}{2}$

Quindi : $T_{avg}(n)=\frac{n-1}{2}$ 