# Agenti e ricerca

Un **agente risolutore di problemi** è un agente che simula una sequenza di azioni prima di eseguirle, al fine di arrivare allo stato obiettivo. Quindi l'agente simula una **ricerca**.
Questi agenti sono detti **agenti pianificatori**, poiché adottano una **rappresentazione atomica della realtà**, in cui lo stato del mondo è indivisibile e non ha struttura interna.
La scelta delle azioni di tali agenti dipende dall'ambiente in cui si trovano:

- Ambiente **ignoto**: 
	L'agente non può fare altro che scegliere azioni in maniera randomica:
- Ambiente **noto**: 
	L'agente raggiunge l'obiettivo eseguendo quattro fasi:
	1. **Formulazione dell'obiettivo**: Aiuta ad organizzare il comportamento limitando le azioni da considerare;
	2. **Formulazione del problema**: Definisce gli stati e le azioni utili per l'obiettivo;
	3. **Ricerca**: Simula sequenze di azioni finché non trova la soluzione ( può anche non esserci );
	4. **Esecuzione**: Esegue le azioni indicate dalla soluzione.

Si può notare che se l'ambiente è *deterministico, noto ed osservabile* allora l'agente può ignorare le percezioni, poiché l'agente ha tutte le informazioni affinché possa ricavare una sequenza di azioni. Quindi, si va a rompere la relazione percezione-azione, avendo così un **sistema ad anello aperto**. In caso contrario (ambiente non deterministico o modello errato) si ha un **sistema ad anello chiuso**.

## Problema di ricerca

Un problema di ricerca è composto da:

- *Un insieme di stati*;
- *Uno stato iniziale*;
- *Uno o più stati obiettivo*;
- *Azioni che può compiere l'agente in base allo stato dell'ambiente*;
- *Un modello di transazione*;
- *Una funzione di costo dell'azione*.

L'insieme degli stati e le azioni dell'agente possono essere rappresentati tramite un **grafo orientato e pesato** in cui i nodi rappresentano gli stati e gli archi le azioni che possono essere applicati allo stato. Perciò, l'obiettivo dell'agente è **il cammino di costo minimo che raggiunge lo stato obiettivo**.

È possibile rappresentare i cammini per raggiungere lo stato obiettivo tramite un **albero di ricerca** in cui:
- Root = Stato iniziale;
- Nodo = Qualunque stato;
- Ramo = Azione qualunque.