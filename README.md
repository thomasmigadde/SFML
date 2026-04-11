# SFML Emoji Collision Game

## Overview
Simple SFML C++ game: Move the cute emoji (WASD or arrow keys) to collide with the sad emoji for points. Score prints to console.

Files:
- `game.cpp`: Main playable game (unified).
- `my_game.cpp`, `try_game.cpp`, `main.cpp`, `syntax.cpp`: Examples/improvements committed in steps.

## Build & Run (VSCode)
1. Open folder in VSCode.
2. Ctrl+Shift+P > Tasks: Run Task > `Build Game` or `Build Active File`.
3. Run `game.exe` (or built .exe).

Or CLI:
```
g++ game.cpp -o game.exe -ISFML/include -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++17
./game.exe
```

## Controls
- WASD or Arrow Keys: Move cute emoji
- ESC/Close: Quit
- Collide: +1 score (console)

## Commits
10 divided commits for code improvements, as requested.

Enjoy!

