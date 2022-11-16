# A simple game of Tic-Tac-Toe 
#### Version:0.2.0</sub>

---
## ToDo:
- Add "play again" option
- Add "character" selection
- Add "AI" for singleplayer mode
- Make "AI" decide the best next step
- Add game difficulty
- Add a nice gui that can be used with different input devices (keyboard, mouse, gamepad)
- Add online multiplayer mode

## How to build and run:

### Installing required dependencies:
- Debian and Ubuntu based systems:
```sudo apt update && sudo apt install build-essential cmake``` 
- ArchLinux and other Arch based systems:
```sudo pacman -Syu base-devel cmake```

### Building and running the game
```
git clone https://github.com/GabiK65/TicTacToe.git

cd ./TicTacToe

cmake .

cmake --build .

chmod a+x ./build/TicTacToe

./build/TicTacToe
```

- all built executables can be found in the 'build' directory 