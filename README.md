# Gerard
A simple terminal user interface task manager, written in C++.

## How to install

### Requirements:
- The ncurses library

For debian based systems:
```
sudo apt install lib-ncurses5-dev
```
For arch based systems:
```
pacman -S ncurses
```

- The sqlite3 library

For debian based systems:
```
sudo apt install libsqlite-3
```
For arch based systems:
```
pacman -S sqlite
```

### How to compile this program?
```
g++ main.cpp -o gerard -lncurses -lsqlite3
```

## What if I have it compiled?

You can run Gerard using the following command:
```
./gerard
```
