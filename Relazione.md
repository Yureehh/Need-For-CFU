# Relazione Initial C

## Table of contents
1. [ Descrizione ](#Descrizione)
2. [Perchè Ncurses?](#Perchè-NCurses?)
3. [ Main ](#Main)  
4. [ Game ](#Game)
5. [ Scorestage ](#Scorestage)
6. [ Level ](#Level)
7. [ Car ](#Car)
8. [ Obstacle ](#Obstacle)

## Descrizione
Il gioco consiste nell'ottenere il maggior punteggio possibile muovendo una macchina di dimensioni 3x3 in una pista delimitata, evitando gli ostacoli per non perdere punti e raccogliendo i bonus per aumentarli. Non esiste un traguardo finale e il gioco prosegue finchè non si perde o si decide di finire la corsa. Ad ogni nuovo gioco i livelli vengono ri-generati randomicamente ma rimangono gli stessi durante la singola partita.

## Perchè NCurses?
Siccome il responsabile alla sezione di rendering del gioco aveva già lavorato con __ncurses__, lo abbiamo scelto in favore di conio.h. Per poter sviluppare anche in ambiente Windows, ci ha aiutati la teconlogia [WSL](https://docs.microsoft.com/it-it/windows/wsl/install-win10), che mette a disposizione una simil "VM" di Linux su Windows. In oltre abbiamo provato a portare conio.h su Linux, ma non abbiamo trovato un modo.

## Main
Si occupa di gestire Input dell'utente e la logica del gioco. Il suo compito principale è di avviare il gioco, impostando alcune opzioni per ncurses, e di farlo comunicare con l'utente. Continene unicamente due funzioni:
* **mainMenu()**: come da nome, stampa il menù principale, con titolo e bordo. Volendo tenerlo minimale, le uniche scelte possibli sono : iniziare una partita, vedere gli autori del progetto o uscire dal gioco. Ogni volta che perderemo una partita verremo riportati a questa schermata.
* **startGame()**: questo metodo rappresenta il gioco vero e proprio, consiste in un while in cui all'inizio di ogni ciclo viene effettuata una pausa, di 3125 millisecondi, che combinata con la funzione **clock** va a definire la velocità di gioco con cui la mappa scorre. Ad ogni iterazione vien controllato se l'utente ha mosso la macchina e ne calcola le eventuali collisioni. Successivamente vien controllato se si è raggiunti un punteggio sufficiente a cambiare livello, in caso affermativo vien calcolato se si deve passare al successivo o al precedente.

## Game
La classe Game permette di coordinare tutte le varie funzionalità del gioco: si occupa di gestire la concatenazione dei livelli, render e le collisioni tra macchina ed ostacoli
* **Render**: 
  * **UI**: Viene stampata una sola volta, per il caso dei bordi dello schermo e del limite della pista, oppure quando serve, come i popup per il cambio di livello o di sconfitta.
  * **Track**: Non viene stampata completamente, ma solo una sezione di essa, e ad ogni tick, dettato dalla funzione **clock**, questa sezione si sposta di 1 blocco verso l'alto, dando l'illusione che la pista stia scorrendo verso il basso. Gli ostacoli verranno indicati dal colore rosso, mentre i Boost con dal colore verde.
* **Car**: Quando viene spostata, prima di essere ristampata viene cancellata dalla posizione precedente per evitare di incorrere in glitch grafici.
* **Collisioni**: Dopo ogni spostamento della mappa e della macchina viene controllato se nella posizione occupata dalle ruote e dal pilota è presente un ostacolo o un boost, in caso affermativo si va a sommare il loro punteggio allo score della partita.
* **Livelli**: La classe game si occupa anche della gestione della lista concatenata dei livelli. Una volta che si supera il limite di punti per salire/scendere al livello successivo quello attuale viene resettato facendo tornare visibili tutti gli ostacoli tranne quelli nelle prime 10 righe dal fondo, nel caso si torni poi a tale livello successivamente.

All'interno di game viene inoltre definita anche una funzione, esterna alla classe stessa, chiamata __kbhit__ che ritorna true se viene premuto un tasto dalla tastiera, false altrimenti, necessaria da definire in quanto all'interno della libreria Ncurses non è presente a differenza della libreria Conio per Windows.

## Scorestage
La classe Scorestage ha il compito di gestire il punteggio, da cui viene ricavato anche il livello attuale dividendo per 1000. Inoltre questa classe restituisce anche il punteggio massimo e minimo ottenuti e anche il livello precedente, utilizzato nel main per capire in caso di passaggio di livello se si deve salire o scendere. Il costruttore è stato fatto in modo che la partita possa iniziare da qualsiasi punteggio(purchè sia positivo) e non perforza dal livello 1.

## Level
* Questa classe è incaricata della creazione dei livelli che il giocatore dovrà superare per avanzare nel gioco. Abbiamo implementato la creazione dei livelli generando casualmente, per ogni punto della mappa, l'eventuale presenza di un entità. Sono anche presenti alcune limitazioni sulla quantità di elementi di ogni tipo che possono crearsi e la distanza che li separa, questi controlli sono stati creati per fare in modo che sia sempre possibile proseguire all'interno del gioco, anche se la difficoltà aumenta progressivamente con l'avanzamento del livello. Sono in oltre presenti funzioni ausiliarie  come getter o setter di alcuni attributi necessari.
* Si è scelto di rappresentare la pista come una matrice di dimensione fissata che una volta percorsa nella sua interezza, evitando ostacoli e boost , permette il passaggio al livello successivo. La matrice di ogni livello viene generata una volta raggiunto tale livello e non varierà proseguendo nella partita, è stata fatta questa scelta per far si che in caso di perdita di punti e di retrocessione di livello gli ostacoli dei livelli precedenti rimangano nella stessa posizione di quando li si è incontrati in precedenza. 

## Car
La classe Car ha il compito di inizializzare la macchina, permette di stamparla ed eliminarla dallo schermo o di cambiarne le coordinate. sono presenti inoltre 2 metodi per ritornare le coordinate x/y della posizione del pilota da cui si risale anche a quella delle ruote.

## Obstacle
La classe Obstacle è utilizzata per definire le entità che assieme alla macchina si trovano sul percorso che il giocatore deve percorrere, infatti in questa classe possiamo definire sia ostacoli che danneggiano il giocatore sia ostacoli che invece premiano il giocatore (boost).