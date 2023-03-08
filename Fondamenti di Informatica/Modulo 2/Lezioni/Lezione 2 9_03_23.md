# Definizione di Macchina di Turing
La macchina di Turing della scorsa lezione utilizza tre nastri: sui primi due nastri, prima che la macchina inizi ad operare, vengono scritti dall'utente i due numeri da sommare, sul terzo, inizialmente vuoto, la macchina scrive il risultato nel corso della sua computazione. Dobbiamo, ora, formalizzare questi concetti e, allo scopo, cominciamo con il limitarci a considerare macchine di Turing che utilizzano un solo nastro.
E come funziona una macchina di Turing? Facile: quando l’unità di controllo si trova nello stato $q_0$, la testina legge il simbolo contenuto nella cella che sta scandendo, cerca una quintupla i cui primi due elementi sono $q_0$ e il simbolo letto dalla testina (che può anche essere il simbolo **blank** ◻) e, se trova una tale quintupla, la esegue; se non la trova ... non compie alcuna azione (ci torneremo più avanti) e la computazione termina.
Eseguire una quintupla significa eseguire le tre azioni in essa indicate:
1. Sovrascrivere il simbolo nella cella scandita dalla testina con il simbolo indicato nella quintupla;
2. Cambiare (eventualmente) stato interno: eventualmente, ossia, a meno che nella quintupla non sia indicato di rimanere nel medesimo stato in cui ci si trovava prima della sua esecuzione
3. Muovere (eventualmente) la testina (eventualmente, ossia a meno che nella quintupla sia indicato “ferma”)
Eseguita la prima quintupla, si cerca un’altra quintupla da eseguire (ossia, una quintupla i cui primi due elementi sono lo stato in cui si trova la machina e il simbolo letto dalla testina) e così via, fino a quando nessuna quintupla può essere eseguita
## Esempio di macchina di Turing
Consideriamo una macchina di Turing ad un nastro, $T_{parità}$ , definita sull’alfabeto    $Σ = \{ 0, 1, p, d\}$ e sull’insieme di stati 
$Q = \{q_0 , q_p , q_d , q_{(F )}\}$ con stato iniziale $q_0$ e stato finale $q_F$ il cui insieme delle quintuple è
$$\begin{align}&P  =  \{  〈 q_0 , 0, ◻, q_p , destra〉, 〈 q_0 , 1, ◻, q_d , destra〉, \\&  〈 q_p , 0, ◻, q_p , destra〉, 〈 q_d , 0, ◻, q_d , destra〉, \\&  〈 q_p , 1, ◻, q_d , destra〉, 〈 q_d , 1, ◻, q_p , destra〉, \\&  〈 q_p , ◻, p, q_F , fermo〉, 〈 q_d , ◻, d, q_F , fermo〉\}\end{align}
$$
La macchina $T_{parità}$ scandisce la sequenza di caratteri scritta sul suo nastro, cancellandoli via via che vengono scanditi, e verificando se tale sequenza contiene un numero pari o un numero dispari di ‘1’: al termine della scansione, nel primo caso scrive ‘p’ e termina, nel secondo caso scrive ‘d’ e termina.