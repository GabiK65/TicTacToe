My first try at making a Tic-tac-toe game in C++

It has "AI" that will place an X or O on a random cell if it's empty

It has also "Character" selection.

Unfortunetly it can't check who has won, at least for now.


## Installing required dependencies:

- Debian and Ubuntu based systems:
```sudo apt update && sudo apt install build-essential cmake``` 
- ArchLinux and other Arch based systems:
```sudo pacman -Syu base-devel cmake```


## How to build and run:

```
git clone https://github.com/GabiK65/TicTacToe.git

cd ./TicTacToe

cmake .

cmake --build .

chmod a+x ./build/TicTacToe

./build/TicTacToe
```

- all built executables can be found in the 'build' directory 