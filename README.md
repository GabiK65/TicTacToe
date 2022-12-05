# A simple game of Tic-Tac-Toe 
#### Version:0.5.0

---
## ToDo:
- ✅ ~~Add "play again" option~~ 
- ✅ ~~Add "character" selection~~
- ✅ ~~Add "AI" for singleplayer mode~~
- 🚧 Optimize code
- Add online multiplayer mode
- Add a nice gui
- Support for input devices (keyboard, mouse, gamepad)
- Make "AI" decide the best next step
- Add game difficulty

## How to build and run:

### Installing required dependencies:
```
pip3 install --user meson
```

### Building and running the game
```
git clone https://codeberg.org/GabiK65/TicTacToe.git

cd ./TicTacToe

meson setup build

cd build

meson compile

chmod a+x ./src/TicTacToe # Optional

./src/TicTacToe
```

- all built executables can be found in the 'build/src' directory
