# Need-For-CFU
Endless Racing Game sviluppato in C++ per ambiente Linux.

## Gioco
L'obiettivo è raggiungere il punteggio più alto possibile, si perde raggiungendo un punteggio minore o uguale a 0.

## Punteggio
Il punteggio parte da 0 e ogni tick di gioco viene incrementato di 20 punti, può diminuire collidendo con un ostacolo o con i bordi laterali e può aumentare ulteriormente raccogliendo i boost. Ogni 1000 punti si passa al livello successivo e si può retrocedere ai livelli precedenti in caso di collisioni.

## Entità
Sono presenti **barriere laterali** che delimitano la pista, collidendo con esse si perdono 1000 punti. Ci sono inoltre due tipi di entità sulla pista: 
- Gli **ostacoli**, di colore rosso, che causano danno all'impatto facendo diminuire il punteggio. Partono da un danno di 200 punti aumentando di   100 ogni livello fino a un tetto massimo di 1000 al livello 9.
- I **boost**, di colore verde, che aumentano il punteggio venendo raccolti. Fanno sempre guadagnare 200 punti ma la probabilità di spawn aumenta ogni livello fino al nono.


## Velocità di gioco
Ad ogni tick di gioco l'automobile guidata dal giocatore si sposta di una riga in avanti. La velocità aumenta proporzionalmente ai livelli: al livello 1 è di circa 400ms per poi scendere fino a 200ms. Retrocedendo di livello la velocità rimane uguale a quella del livello massimo raggiunto dal giocatore.


## Comandi
**A/D** - Movimento Macchina  
**Enter** - Seleziona  
**Esc** - Pausa  
**Q** - Esce dalla partita corrente e torna al menù principale


## Installazione
Per essere compilato richiede la seguente libreria

* [ncurses o lib32-ncurses](https://invisible-island.net/ncurses/ncurses.html)

**Arch Linux**
```bash
sudo pacman -S ncurses
```

**Debian e derivate ( Ubuntu, Linux Mint ... )**
```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

Poi compilare il codice con:
```bash
make all
```

## Utilizzo
```bash
./outrun
```
Oppure usando make
```bash
make run
```
## Screenshots
![Game](https://i.imgur.com/VrMczYC.png)
![Level UP](https://i.imgur.com/L5sekBl.png)

## Autori
[Alessandro Filippini](https://github.com/AlePini)  
[Filippo Bertozzi](https://github.com/FilippoBertozzi)  
[Juri Fabbri](https://github.com/Yureehh)

## License
[MIT](https://choosealicense.com/licenses/mit/)