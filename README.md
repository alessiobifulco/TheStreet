# Progetto di Algoritmi e Strutture Dati: Costruzione di una Strada di Costo Minimo

Progetto per il corso di Laboratorio di Algoritmi e Strutture Dati dell'Università di Bologna (A.A. 2023/2024), basato sulle specifiche ufficiali.

---

## 🎯 Obiettivo del Progetto

L'obiettivo è progettare e implementare un programma in **linguaggio C (ANSI)** che calcoli il percorso di costo minimo per la costruzione di una strada su una mappa rappresentata come una griglia `n x m`. La strada deve connettere la cella di partenza `(0, 0)` con quella di arrivo `(n-1, m-1)`.

Il costo totale è determinato da due fattori:
1.  Un costo fisso **$C_{cell}$** per ogni cella attraversata.
2.  Un costo variabile dipendente dal dislivello tra celle adiacenti, calcolato come **$C_{height} \times (\Delta H)^2$**.

La formula del costo totale per un percorso di $k$ celle è:
$C_{totale} = C_{cell} \times k + C_{height} \times \sum_{i=0}^{k-2} |H[x_{i}, y_{i}] - H[x_{i+1}, y_{i+1}]|^2$

Il programma deve trovare un percorso valido che minimizzi questo costo totale.

## 🧠 Approccio Algoritmico: Algoritmo di Dijkstra

Il problema può essere modellato come la ricerca del **cammino minimo su un grafo pesato**.

### 1. Modellazione del Grafo
* **Nodi:** Ogni cella `(i, j)` della griglia `n x m` viene considerata come un nodo del grafo. Il numero totale di nodi è $V = n \times m$.
* **Archi:** Esiste un arco tra due nodi se e solo se le celle corrispondenti sulla griglia sono adiacenti (hanno un lato in comune). Ogni nodo interno alla griglia avrà quindi 4 archi uscenti (verso N, S, E, O).
* **Pesi degli Archi:** Il peso di un arco che connette una cella `u` a una cella adiacente `v` non è semplicemente il costo del dislivello, ma rappresenta il costo totale per "spostarsi" da `u` a `v`. Questo include sia il costo per "entrare" nella cella `v` sia il costo legato al dislivello tra `u` e `v`. Pertanto, il peso dell'arco $(u, v)$ è:
    $w(u, v) = C_{cell} + C_{height} \times (H_u - H_v)^2$

### 2. Algoritmo di Dijkstra
Una volta modellato il problema in questo modo, l'obiettivo diventa trovare il cammino di costo minimo dal nodo sorgente `(0, 0)` al nodo destinazione `(n-1, m-1)`. Poiché i pesi degli archi sono sempre non-negativi, l'**algoritmo di Dijkstra** è la scelta ideale per risolvere questo problema.

L'algoritmo funziona mantenendo una stima del costo minimo per raggiungere ogni nodo e aggiornando iterativamente queste stime partendo dal nodo sorgente.

### 3. Gestione della Coda a Priorità
L'efficienza dell'algoritmo di Dijkstra dipende criticamente dall'implementazione della **coda a priorità**, utilizzata per selezionare il prossimo nodo da visitare (quello con la distanza minima non ancora finalizzata). La gestione di questa struttura dati è stata un punto chiave dell'implementazione. L'algoritmo, partendo dal nodo `(0,0)`, esplora il grafo e costruisce l'albero dei cammini minimi fino a raggiungere ed estrarre dalla coda il nodo di destinazione `(n-1, m-1)`.

## 🛠️ Tecnologie e Vincoli di Progetto

* **Linguaggio:** Il progetto è stato sviluppato interamente in **ANSI C (C89/C90)**, rispettando scrupolosamente le specifiche del corso.
* **Compilatore:** Il codice è stato compilato utilizzando **GCC** con i flag `-std=c90 -Wall -Wpedantic` per garantire massima conformità e assenza di warning.
* **Gestione della Memoria:** È stata posta massima attenzione all'allocazione e deallocazione della memoria. L'assenza di memory leak e di accessi non validi è stata verificata tramite lo strumento **Valgrind** in ambiente Linux.
* **Input/Output:** Il programma accetta il nome di un file di input da riga di comando e produce un output formattato secondo le specifiche, contenente le coordinate del cammino minimo e il suo costo totale.

## 👤 Contatti
* Alessio Bifulco: `alessio.bifulco@studio.unibo.it`
