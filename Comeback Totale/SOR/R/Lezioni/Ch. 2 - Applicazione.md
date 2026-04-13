# Principi delle applicazioni di rete
## Creare un'applicazione di rete
Scrivere programmi che:
- Girano su sistemi periferici differenti;
- Comunicano attraverso la rete;
Non è necessario scrivere programmi per i dispositivi nel nucleo della rete:
- I dispositivi del nucleo della rete non eseguono applicazioni utente;
- Il confinamento delle applicazioni nei sistemi periferici ha facilitato il rapido sviluppo e la diffusione di una vasta gamma di applicazioni per internet.

**Paradigma client-server**
*Server*:
- Host sempre attivo;
- Indirizzo IP fisso;
- Spesso in datacenter (per scalabilità);
- Onere economico sui fornitori del servizio (per infrastruttura, manutenzione, traffico).
*Client*:
- Contatta, comunica col server;
- Può contattare il server in qualsiasi momento;
- Può avere IP dinamici;
- Non comunica direttamente con gli altri client;

**Architettura peer-to-peer**