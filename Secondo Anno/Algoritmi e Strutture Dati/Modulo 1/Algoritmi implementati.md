>[!important]- Algoritmo
>Procedimento che descrive una sequenza di passi ben definiti finalizzato a risolvere un dato problema (Computazionale).

# Fibonacci
## Fibonacci 1
```c
algoritmo fibonacci1(intero n) -> intero
	return 1/sqrt(5) (phi^n - phi(cappuccio)^n) 
```

## Fibonacci 2

```C
algoritmo fibonacci2(intero n) -> intero
	if(n<=2) then
		return 1
	else
		return fibonacci2(n-1) + fibonacci2(n-2)
```

## Fibonacci 3

```C
algoritmo fibonacci3(intero n) -> intero
	sia Fib un array di n interi
	Fib[1] <- 1; Fib[2] <- 1
	for i=3 to n do
		Fib[i] <- Fib[i-1] + Fib[i-2]
	return Fib[n]
```

## Fibonacci 4

```C
algoritmo fibonacci4(intero n) -> intero
	a <- 1; b <- 1;
	for i=3 to n do
		c <- a+b
		a <- b
		b <- c
	return c
```

## Fibonacci 5

```c
algoritmo fibonacci5(intero n) -> intero
	M <- [1,0;0,1]
	for i=1 to n-1 do
		M <- M*[1,1;1,0]
	return M[0][0]
```

## Fibonacci 6

```C
algoritmo fibonacci6(intero n) -> intero
	A <- [1,1;1,0]
	M <- potenzaDiMatrice(A, n-1)
	return M[0][0]

funzione potenzaDiMatrice(matrice A, intero k) -> matrice
	if k=0 then
		return [1,0;0,1]
	else
		M <- potenzaDiMatrice(A, [k/2]) //parte intera inferiore
		M <- M*M
	if (k dispari) then
		M <- M*A
	return M
```

Tempo di esecuzione : $O(\log_{2}{n})$ .