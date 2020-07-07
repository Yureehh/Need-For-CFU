# Documentazione Project-Mercury

## Table of contents
1. [ Descrizione ](#Descrizione)
2. [ Main ](#Main)  
3. [ Game ](#Game)
4. [ Scorestage ](#scorestage)
5. [ Level ](#level)
6. [ Car ](#car)
7. [ Obstacle ](#opbstacle)

## Descrizione
Il gioco consiste nell'ottenere il maggior punteggio possibili muovendo una macchina di dimensioni 3x3 in una pista delimitata, evitando gli ostacoli per non perdere punti e raccogliendo i bonus per aumentarli. Ad ogni nuova partita i livelli vengono ri-generati randomicamente.  

<a name="Main"></a>
## Main


<a name="Game"></a>
## Game
La classe Game permette di coordinare tutte le varie funzionalità del gioco: si occupa di gestire la concatenazione dei livelli, lo spostamento degli ostacoli e della macchina, le relative collisioni ed eventualmente la sconfitta.

<a name="Scorestage"></a>
## Scorestage
La classe Scorestage ha il compito di inizializzare e gestire il punteggio, da cui si vengono anche ricavati il punteggio minimo e massimo della partita e il livello attuale.

<a name="Level"></a>
## Level.cpp


<a name="Car"></a>
## Car
La classe Car ha il compito di inizializzare la macchina e permette di eliminarla dallo schermo o di cambiarne le coordinate.

<a name="Obstacle"></a>
## Obstacle

//da mettere nella classe della pista
Si è scelto di rappresentare la pista come una matrice di dimensione fissata che una volta percorsa nella sua interezza, evitando ostacoli e boost , permette il passaggio al livello successivo. La matrice di ogni livello viene generata una volta raggiunto tale livello e non varierà proseguendo nella partita, è stata fatta questa scelta per far si che in caso di perdita di punti e di retrocessione di livello gli ostacoli dei livelli precedenti rimangano nella stessa posizione di quando li si è incontrati in precedenza. 
