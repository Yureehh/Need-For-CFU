# Relazione Initial C

## Table of contents
1. [ Descrizione ](#Descrizione)
2. [ Main ](#Main)  
3. [ Game ](#Game)
4. [ Scorestage ](#Scorestage)
5. [ Level ](#Level)
6. [ Car ](#Car)
7. [ Obstacle ](#Obstacle)

## Descrizione
Il gioco consiste nell'ottenere il maggior punteggio possibili muovendo una macchina di dimensioni 3x3 in una pista delimitata, evitando gli ostacoli per non perdere punti e raccogliendo i bonus per aumentarli. Ad ogni nuova partita i livelli vengono ri-generati randomicamente.

## Perchè NCurses?
Sappiamo che ncurses è esclusivamente su ambienti Linux (anche se esistono alcuni porting per Windows ), ma è stato facile sviluppare su Windows grazie alla teconologia [WSL](https://docs.microsoft.com/it-it/windows/wsl/install-win10). In oltre, l'aver lavorato in precedenza con questa libreria, ha semplificato lo sviluppo della parte di rendering.

## Main
Si occupa di gestire Input dell'utente e la logica del gioco. Il suo compito principale è di avviare il gioco, impostando alcune opzioni per ncurses, e di farlo comunicare con l'utente. Continene unicamente due funzioni:
* **mainMenu()**: come da nome, stampa il menù principale, con titolo e bordo. Volendo tenerlo minimale, le uniche scelte possibli sono : iniziare una partita, vedere gli autori del progetto o uscire dal gioco. Ogni volta che perderemo una partita verremo riportati a questa schermata.
* **startGame()**: // YUREE

## Game
La classe Game permette di coordinare tutte le varie funzionalità del gioco: si occupa di gestire la concatenazione dei livelli, render e le collisioni tra macchina ed ostacoli
* **Render**: 
  * **UI**: Viene stampata una sola volta, per il caso dei bordi dello schermo e del limite della pista, oppure quando serve, come i popup per il cambio di livello o di sconfitta.
  * **Track**: Non viene completamente stampata, ma solo una sezione di essa, e ad ogni tot "tick" questa sezione si sposta di 1 blocco verso l'alto, dando l'illusione che la pista stia scorrendo verso il basso. Gli ostacoli verranno indicati dal colore rosso, mentre i Boost con dal colore verde.
  * **Car**: Quando viene spostata, prima di ristamparla c'è bisogno di pulire nella posizione precedente, altrimenti si incorre in glitch grafici.
* **Collisioni**:
* **Livelli**:

## Scorestage
La classe Scorestage ha il compito di gestire il punteggio, da cui si vengono anche ricavati il punteggio minimo e massimo della partita e il livello attuale.

## Level
//da Riscrivere
Si è scelto di rappresentare la pista come una matrice di dimensione fissata che una volta percorsa nella sua interezza, evitando ostacoli e boost , permette il passaggio al livello successivo. La matrice di ogni livello viene generata una volta raggiunto tale livello e non varierà proseguendo nella partita, è stata fatta questa scelta per far si che in caso di perdita di punti e di retrocessione di livello gli ostacoli dei livelli precedenti rimangano nella stessa posizione di quando li si è incontrati in precedenza. 

## Car
La classe Car ha il compito di inizializzare la macchina e permette di eliminarla dallo schermo o di cambiarne le coordinate.

## Obstacle
