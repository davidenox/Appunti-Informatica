# Software Engineering
Disciplina per la produzione del software secondo i principi dell’ingegneria (progettazione e validazione). È  essenziale per fare del software un prodotto industriale.
Se manca, si incorre in:
- scarsa qualità del prodotto;
- scarsa competitività:
	- cost overrun;
	- time overrun.

# Ciclo di vita del Software
	3 Stadi, 6 Fasi
- Produzione Software = Sviluppo + Manutenzione
- *Sviluppo* ( Stadio 1 ):
	 1. Requisiti;
	 2. Specifiche ( Analisi dei requisiti );
	 3. Pianificazione;
	 4. Progetto ( Preliminare e Dettagliato );
	 5. Codifica;
	 6. Integrazione.
- *Manutenzione* ( Stadio 2 ):
	- Copre circa il 60% dei costi del ciclo di vita.
- *Dismissione* ( Stadio 3 ).
## Effetto delle modifiche
L'effetto delle modifiche varia secondo la fase in cui vengono introdotte. In fasi avanzate, una modifica può comportare rivolgimenti che richiedono nuove risorse o correzioni importanti al progetto, cioè costi supplementari:
![[Pasted image 20241004113527.png|center|500]]
## Testing
Il Testing non è esplicitamente menzionato tra le sei fasi, non è una fase separata bensì un'attività che ha luogo durante l'intero sviluppo. Viene attuata in due modi:
- *Verifica* alla fine di ogni fase ( La fase è stata ben svolta );
- *Validazione* alla fine dello sviluppo ( Il prodotto finale è buono ).
### Defect Removal Efficiency ( DRE)
Il DRE fa riferimento alla *percentuale di difetti trovati* **prima** del rilascio del software

>[!info] Esempio: Se il team di sviluppo trova 900 difetti prima del rilascio e gli studenti trovano 100 difetti in un intervallo di tempo standard ( tipicamente 90 giorni ), allora il DRE è pari al 90%

## Aspetti tipici dell'ISW
### Accidentali
	Superabili con il progresso della tecnologia.
- Di attitudine;
- Di manutenzione;
- Di specifica e progetto;
- Di teaming.
### Essenziali
	Non superabili col progresso di mezzi e conoscenze.
- Complessità;
- Conformità;
- Cambiabilità;
- Invisibilità.
### Di costo
- Costo verso dimensione (size);
- Costo verso repliche;
- Costo verso ampiezza di mercato.
#### Aspetti di costo
- Costo proporzionale al quadrato del size ($C=aS^2$)
	- fare due prodotti di size $S/2$ costa meno che farne uno di size $S$
- Produrre una replica non costa niente
- Vendere un prodotto di size doppio per il mercato
	- richiede un prezzo 4 volte superiore a parità di (ampiezza di) mercato 
	- richiede un mercato (di ampiezza) 4 volte maggiore a parità di prezzo
# Definizioni
-  Prodotto *Sw* (o brevemente Sw) = Codice + Documentazione;
-  *Artefatto*= prodotto Sw intermedio;
	-  documento requisiti;
	-  documento di specifica;
	-  documento di progetto.
-  *Codice* = prodotto Sw finale;
-  *Sistema* Sw = insieme organizzato di prodotti Sw;
-  *Cliente* = soggetto che ordina il prodotto Sw;
-  *Sviluppatore* = soggetto che lo produce;
-  *Utente* = soggetto che lo usa;
-  *Sw interno* = cliente e sviluppatore coincidono;
-  *Sw a contratto* = cliente e sviluppatore sono soggetti differenti.
# Aspetti di Affidabilità
Informalmente, tratta della *credibilità* del prodotto software.
**Formalmente**, tratta della *probabilità che il prodotto software lavori correttamente in un determinato intervallo temporale*.

>[!info]- Intuitivamente, un prodotto software con molti difetti è poco affidabile; È chiaro che l'affidabilità del prodotto software migliora con la diminuzione dei difetti.

## Difetto, guasto, errore
- **Difetto**: Anomalia presente in un prodotto SW;
- **Guasto**: Comportamento anomalo del prodotto SW dovuto alla presenza di un difetto;
- **Errore**: Azione errata di chi introduce un difetto nel prodotto SW ( per ignoranza, distrazione ecc..).
## Caratteristiche dell'affidabilità SW

Si parla di una **relazione** non-semplice tra l'*affidabilità osservata* ed il numero di *difetti latenti*.

>[!important]- La regola 10-90
>Il 90% del tempo di esecuzione totale è speso eseguendo il solo 10% delle istruzioni.
>Il detto 10% è chiamato **Core**, ovvero il nucleo del programma.

Il miglioramento di affidabilità per eliminazione di un difetto dipende dalla *localizzazione del difetto* ( se appartiene o meno al nucleo del programma ).
Dunque, l'affidabilità osservata dipende da come è usato il prodotto e dal suo profilo operativo ( *operational profile* ). Poiché utenti differenti usano il SW secondo profili operativi diversi, *i difetti che si manifestano per un utente potrebbero **non** manifestarsi per l'altro*. 
In sintesi, l'affidabilità di un prodotto SW **dipende dall'utente**.

# Confronto tra affidabilità HW e SW
1. I guasti *SW* sono dovuti alla presenza di difetti nei programmi, di conseguenza il SW non si consuma.
2. I guasti *HW* sono quasi sempre dovuti a:
	1. Consumo/Deterioramento dei componenti;
	2. Qualche componente non si comporta più come specificato;
	3. Qualche componente si rompe.
A causa della differenza negli effetti dei difetti, le metriche usate per l'affidabilità HW *non sono* estensibili al SW.
Dopo la riparazione dell'HW la sua affidabilità *torna come prima*, mentre dopo la riparazione del SW la sua affidabilità *può aumentare o diminuire*.
Dunque, l'*obiettivo* dell'affidabilità HW è la **stabilità**, mentre l'*obiettivo* dell'affidabilità SW è la **crescita di stabilità**.

# Disponibilità
Si parla tempo (in percentuale) in cui il SW è risultato usabile nel corso della sua vita. Esso dipende:
- Dal numero di guasti che si verificano;
- Dal tempo necessario a ripararli.

# Importanza di affidabilità e disponibilità
Sono metriche importanti per sistemi in cui la caduta del servizio crea cadute di efficienza e sicurezza: 
-  sistemi di trasporto
-  di governo del traffico aereo
-  di governo del volo
-  di produzione e distribuzione di energia
-  di comunicazione
-  etc
# Conclusioni
Nel corso degli anni la produzione del software ha seguito varie fasi:
-  fase di abilità, nella quale prevalgono gli aspetti di lavoro individuale e creativo
-  fase artigianale, nella quale il software viene prodotto da piccoli gruppi specializzati, spesso di alto livello di professionalità
-  fase industriale, nella quale l'attività di sviluppo e manutenzione del software viene pianificata e coordinata, ed il lavoro del progettista viene sempre più supportato da strumenti automatici.
Il software può essere considerato come un **insieme** di elementi che formano una "*configurazione*" che include:
-  programmi;
-  documenti;
-  dati multimediali.
Viene realizzato dall'ingegnere del software applicando un *processo* che conduca a risultati di *qualità* elevata. Come per ogni altro prodotto di successo, si applica al software un approccio ingegneristico.

Caratteristiche del software:
-  il software va "ingegnerizzato";
-  il software non si consuma;
-  il software è complesso, invisibile, si conforma, si cambia.

 - Come assicurare la qualità del software che si produce?
-  Come bilanciare la "domanda" crescente pur mantenendo il controllo del budget a disposizione?
-  Come aggiornare applicazioni vecchie (legacy) ma ancora necessarie?
-  Come evitare tempi di consegna più lunghi di quelli pianificati?
-  Come applicare con successo le nuove tecnologie software?

I metodi e le tecniche di **Ingegneria del Software** hanno lo scopo di fornire le risposte a tali problemi, al fine di realizzare software con le desiderate caratteristiche di qualità.