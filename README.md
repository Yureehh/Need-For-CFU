# Need-For-CFU
Endless Racing Game sviluppato per ambiente Linux

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
## Autori
[Alessandro Filippini](https://github.com/AlePini)  
[Filippo Bertozzi](https://github.com/FilippoBertozzi)  
[Juri Fabbri](https://github.com/Yureehh)

## License
[MIT](https://choosealicense.com/licenses/mit/)