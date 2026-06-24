# Livello Applicazione

### DNS — Domain Name System

Sistema distribuito che traduce nomi di dominio (es. google.com) in indirizzi IP utilizzabili dalla rete.

### SMTP — Simple Mail Transfer Protocol

Protocollo utilizzato per l'invio delle email tra client e server e tra server di posta.

### ISP — Internet Service Provider

Azienda che fornisce accesso a Internet e servizi di connettività agli utenti.

---

# Livello Trasporto

### TCP — Transmission Control Protocol

Protocollo affidabile orientato alla connessione che garantisce consegna ordinata, controllo di flusso e controllo della congestione.

### UDP — User Datagram Protocol

Protocollo non orientato alla connessione e senza garanzie di consegna, utilizzato quando velocità e bassa latenza sono prioritarie.

### TLS — Transport Layer Security

Protocollo crittografico che protegge le comunicazioni garantendo confidenzialità, autenticazione e integrità dei dati.

### RTT — Round Trip Time

Tempo necessario affinché un pacchetto raggiunga la destinazione e la relativa risposta ritorni al mittente.

### RDT — Reliable Data Transfer

Modello teorico che descrive meccanismi per ottenere trasferimenti affidabili su canali potenzialmente inaffidabili.

### FSM — Finite State Machine

Modello matematico a stati utilizzato per descrivere il comportamento dei protocolli di comunicazione.

### MSS — Maximum Segment Size

Massima quantità di dati applicativi contenuta in un segmento TCP, esclusi gli header.

### MTU — Maximum Transmission Unit

Dimensione massima di un pacchetto che può essere trasmesso su un collegamento senza frammentazione.

### AIMD — Additive Increase Multiplicative Decrease

Algoritmo di controllo della congestione TCP che aumenta gradualmente la finestra e la riduce drasticamente in caso di congestione.

### ECN — Explicit Congestion Notification

Meccanismo che permette ai router di segnalare la congestione senza scartare i pacchetti.

### QUIC — Quick UDP Internet Connections

Protocollo di trasporto moderno basato su UDP che integra funzionalità di TCP e TLS per ridurre la latenza.

### DDoS — Distributed Denial of Service

Attacco in cui numerosi dispositivi compromettono la disponibilità di un servizio saturandone le risorse.

---

# Livello Rete - Piano Dati

### IP — Internet Protocol

Protocollo responsabile dell'indirizzamento e dell'instradamento dei pacchetti tra reti diverse.

### CIDR — Classless Inter-Domain Routing

Tecnica di indirizzamento IP che utilizza prefissi di lunghezza variabile per migliorare l'allocazione degli indirizzi.

### DHCP — Dynamic Host Configuration Protocol

Protocollo che assegna automaticamente indirizzi IP e altri parametri di configurazione agli host.

### NAT — Network Address Translation

Tecnica che traduce indirizzi IP privati in indirizzi pubblici e viceversa.

### ICMP — Internet Control Message Protocol

Protocollo utilizzato per segnalazioni di errore e diagnostica della rete (es. ping).

### TTL — Time To Live

Campo dell'header IP che limita il numero massimo di hop attraversabili da un pacchetto.

---

# Livello Rete - Piano Controllo

### OSPF — Open Shortest Path First

Protocollo di routing interno che utilizza l'algoritmo di Dijkstra per calcolare i percorsi minimi.

### BGP — Border Gateway Protocol

Protocollo di routing utilizzato tra Sistemi Autonomi (AS) per instradare il traffico su Internet.

### ECMP Routing — Equal Cost Multi Path Routing

Tecnica che distribuisce il traffico su più percorsi aventi lo stesso costo.

### SDN — Software Defined Networking

Architettura che separa il piano di controllo dal piano dati consentendo gestione centralizzata della rete.

### TCAM — Ternary Content Addressable Memory

Memoria speciale utilizzata negli switch/router per effettuare ricerche molto rapide nelle tabelle di forwarding.

### IBN — Intent-Based Networking

Paradigma di gestione della rete in cui l'amministratore specifica l'obiettivo desiderato e il sistema configura automaticamente la rete.

### CLI — Command Line Interface

Interfaccia testuale utilizzata per configurare e amministrare dispositivi di rete.

### SNMP — Simple Network Management Protocol

Protocollo utilizzato per monitorare e gestire dispositivi di rete.

### MIB — Management Information Base

Database strutturato contenente gli oggetti gestiti tramite SNMP.

### NETCONF — Network Configuration Protocol

Protocollo per la configurazione e gestione automatizzata dei dispositivi di rete.

### YANG — Yet Another Next Generation

Linguaggio di modellazione utilizzato per descrivere dati e configurazioni gestite tramite NETCONF.

---

# Livello Collegamento (Data Link)

### CRC — Cyclic Redundancy Check

Tecnica di rilevazione degli errori basata su operazioni polinomiali.

### TDMA — Time Division Multiple Access

Tecnica di accesso multiplo che assegna a ogni nodo specifici intervalli temporali di trasmissione.

### CSMA — Carrier Sense Multiple Access

Protocollo in cui una stazione ascolta il mezzo trasmissivo prima di trasmettere.

### CSMA/CD — Carrier Sense Multiple Access with Collision Detection

Versione di CSMA utilizzata nelle reti Ethernet condivise che rileva e gestisce le collisioni.

### FDM — Frequency Division Multiplexing

Tecnica di multiplazione che divide il canale in diverse bande di frequenza.

### TDM — Time Division Multiplexing

Tecnica di multiplazione che divide il canale in intervalli temporali assegnati ai vari flussi.

### LAN — Local Area Network

Rete locale che collega dispositivi all'interno di un'area geografica limitata.

### MAC — Media Access Control

Sottolivello del Data Link che gestisce l'accesso al mezzo e identifica le interfacce tramite indirizzi MAC.

### ROM — Read Only Memory

Memoria non volatile utilizzata nei dispositivi di rete per conservare firmware e bootstrap.

### NIC — Network Interface Card

Scheda di rete che consente a un dispositivo di comunicare sulla rete.

### ARP — Address Resolution Protocol

Protocollo che associa indirizzi IP a indirizzi MAC all'interno di una LAN.

### VLAN — Virtual Local Area Network

Tecnologia che permette di creare reti logiche separate sulla stessa infrastruttura fisica.

### EVPN — Ethernet Virtual Private Network

Tecnologia di controllo che estende domini Ethernet su reti IP/MPLS tramite BGP.

### VXLAN — Virtual eXtensible LAN

Protocollo di overlay che incapsula frame Ethernet in pacchetti UDP per creare reti virtuali scalabili.
