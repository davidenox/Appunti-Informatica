# Esercizio 1

$T(n)=T(n-1)+n$

avremo che
$$T(n)=T(n-1)+n=T(n-2)+2n=T(n-3)+3n=...=T(n-i)+in$$
Il caso baso lo abbiamo quando i=n-1. Infatti per i=n-1 abbiamo che:
$$T(n)=T(\cancel{n}-\cancel{n}+1)+(n-1)n=T(1)+n^2-n=\Theta(n^2)$$

# Esercizio 2

$T(n)=9T(n/3)+n$

$$T(n)=9T(n/3)+n=9(9T(n/9)+n/3)+n=9^2(T(n/3^2)+9n/3)+n=...$$
$$=9^iT(n/3^i)+\sum_{j=0}^{i-1}(9/3)^jn$$

Il caso base lo abbiamo quando $i=log_3n$. Infatti, per $i=log_3n$ abbiamo che:
$$T(n)=9^{log_3n}+n\sum_{j=0}^{log_3n-1}(9/3)^j=9^{log_3n}+n\sum_{j=0}^{log_3n-1}3^j$$
dato che $log_3n=log_9n\cdot log_39$ risulta che $9^{log_3n}=9^{log_9n\cdot log_39}=n^2$ 
A questo punto, usando la [serie geometrica](https://it.wikipedia.org/wiki/Serie_geometrica#Formule), abbiamo che 
$$T(n)=n^2+\frac{3^{log_3n}-1}{3-1}=n^2+\frac{n-1}{2}$$
e quindi $T(n)=\Theta(n^2)$

