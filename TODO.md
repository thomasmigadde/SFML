# 10 Divided Commits Plan for SFML Game Project

## Completed Steps
- [x] Commit 1: Create .gitignore (ignore binaries, DLLs, output/, images/)
- [x] Commit 2: Update TODO.md with this 10-commit plan
- [x] Commit 3: Improve my_game.cpp (add collision score with SFML Text display) - console for now

## Pending Steps (Mark [x] as completed)
- [ ] Commit 4: Refactor main.cpp (fix event loop to standard while(pollEvent()), add error checks)
- [ ] Commit 5: Clean syntax.cpp (remove redundant comments, add framerate limit)
- [ ] Commit 6: Enhance try_game.cpp (add WASD controls, graphical score)
- [ ] Commit 7: Create unified game.cpp merging best features (emoji game + score + audio?)
- [ ] Commit 8: Update .vscode/tasks.json (add build task for g++)
- [ ] Commit 9: Create README.md (build/run instructions, controls)
- [ ] Commit 10: Final cleanup (git log verify), optional push

## Followup
- Test: g++ *.cpp -o game.exe -I SFML/include -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
- git log --oneline (aim 10 new commits)

