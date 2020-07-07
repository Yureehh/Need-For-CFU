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
* **startGame()**: questo metodo rappresenta il gioco vero e proprio, consiste in un ciclo while in cui all'inizio di ogni ciclo viene effettuata una pausa, di 3125 millisecondi, che combinata con la funzione **clock** va a definire la velocità di gioco con cui la mappa scorre. Inoltre ad ogni ciclo vien controllato se l'utente ha mosso la macchina e ne calcola le eventuali collisioni. Successivamente ad ogni ciclo vien controllato se si è raggiunti un punteggio sufficiente a cambiare livello, in caso affermativo vien calcolato se il nuovo livello deve essere quello precedente o quello successivo e viene effettuato il passaggio.

## Game
La classe Game permette di coordinare tutte le varie funzionalità del gioco: si occupa di gestire la concatenazione dei livelli, render e le collisioni tra macchina ed ostacoli
* **Render**: 
  * **UI**: Viene stampata una sola volta, per il caso dei bordi dello schermo e del limite della pista, oppure quando serve, come i popup per il cambio di livello o di sconfitta.
  * **Track**: Non viene completamente stampata, ma solo una sezione di essa, e ad ogni tick, dettato dalla funzione **clock**, questa sezione si sposta di 1 blocco verso l'alto, dando l'illusione che la pista stia scorrendo verso il basso. Gli ostacoli verranno indicati dal colore rosso, mentre i Boost con dal colore verde.
* **Car**: Quando viene spostata, prima di ristamparla viene cancellata dalle posizioni precedenti per evitare di incorrere in glitch grafici.
* **Collisioni**: Dopo ogni spostamento della mappa e della macchina viene controllato se nella posizione occupata dalle ruote e del pilota è presente un ostacolo o un boost, in caso affermativo si va a sommare il loro punteggio allo score della partita.
* **Livelli**: La classe game si occupa anche della gestione della lista concatenata dei livelli. Una volta che si supera il limite di punti per salire/scendere al livello successivo quello attuale viene resettato facendo tornare tutti gli ostacoli tranne quelli nelle prime 10 righe dal fondo vengono fatti tornare visibili nel caso si torni poi a tale livello.

All'interno di game viene inoltre definita anche una funzione, esterna alla classe stessa, chiamata __kbhit__ che ritorna true se viene premuto un tasto dalla tastiera, false altrimenti, necessaria da definire in quanto all'interno della libreria Ncurses non è presente a differenza della libreria Conio per Windows.

## Scorestage
La classe Scorestage ha il compito di gestire il punteggio, da cui viene ricavato anche il livello attuale. Inoltre questa classe restituisce anche il punteggio massimo e minimo ottenuti e anche il livello precedente, utilizzato nel main per capire in caso di passaggio di livello se si deve salire o scendere.


## Level
//da Riscrivere
Si è scelto di rappresentare la pista come una matrice di dimensione fissata che una volta percorsa nella sua interezza, evitando ostacoli e boost , permette il passaggio al livello successivo. La matrice di ogni livello viene generata una volta raggiunto tale livello e non varierà proseguendo nella partita, è stata fatta questa scelta per far si che in caso di perdita di punti e di retrocessione di livello gli ostacoli dei livelli precedenti rimangano nella stessa posizione di quando li si è incontrati in precedenza. 

## Car
La classe Car ha il compito di inizializzare la macchina, permette di stamparla ed eliminarla dallo schermo o di cambiarne le coordinate. Al suo interno viene definita la struttura "posizione" che viene poi utilizzata nell' unico attributo privato della classe : __posizione c__ che corrisponde alle coordinate del pilota dell'auto da cui poi si può facilmente risalire anche a quelle delle ruote che si trovano in diagonale rispetto ad esso.

## Obstacle
