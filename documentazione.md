# Documentazione Project-Mercury

## Table of contents
1. [ Main.cpp ](#main)  
2. [ Game.cpp ](#game)
3. [ Scorestage.cpp ](#scorestage)
4. [ Level.cpp ](#level)
5. [ Car.cpp ](#car)
6. [ Obstacle.cpp ](#obstacle)

## Descrizione
Il gioco consiste nell'ottenere il maggior punteggio possibili muovendo una macchina di dimensioni 3x3 in una pista delimitata, evitando gli ostacoli per non perdere punti e raccogliendo i bonus per aumentarli. Ad ogni nuova partita i livelli vengono ri-generati randomicamente.  

//da mettere nella classe della pista
Si è scelto di rappresentare la pista come una matrice di dimensione fissata che una volta percorsa nella sua interezza, evitando ostacoli e boost , permette il passaggio al livello successivo. La matrice di ogni livello viene generata una volta raggiunto tale livello e non varierà proseguendo nella partita, è stata fatta questa scelta per far si che in caso di perdita di punti e di retrocessione di livello gli ostacoli dei livelli precedenti rimangano nella stessa posizione di quando li si è incontrati in precedenza. 
