# Chess
This repository includes the C code for the game chess.
## Discriptions
Before excuting the code,since this code was written awile ago, if you are using Visual Studio you have to follow the instruction below 
in order for the code to work (It will give errors for fopen and other functions that have been edited through the years.)

Under "Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions" add " ;_CRT_SECURE_NO_WARNINGS"

We will now explain how to play C-Chess game.
### First Menu
At first, when the code is launched, you will have two options.
1. Load Game
2. New Game

If you have saved a game before, the name of the file you saved the game with will appear below (you can save up to 5 game). The highscore for the game is also 
shown in the first menu. The score of each chess piece will be noted down in the score section.

After pressing 2 you will directed to a new game and pressing 1 will ask which saved game you want to load. By typing the name of the
saved file you will be able to continue the game.
### Second Menu
The second menu is quite self explanatory. The rules that are important is that either teams can start but after that please consider 
which team's turn it is. If your piece move is invalid a notification will appear and your turn is over.

By pressing P you can pick up a piece and move it. The pieces are as follows:
- P or p : *Pawn*
- N or n : *Knight*
- R or r : *Rook*
- B or b : *Bishop*
- Q or q : *Queen*
- K or k : *King*

The game will only end when either team **hits** the oppositions king. 
### Score
The score for hitting each piece is noted below:
- 1 point for ***Pawns***.
- 2 points for ***Knights***.
- 3 points for ***Bishops***.
- 5 points  for ***Rooks***.
- 10 points for ***Queen***.
- 100 point for ***King***.

The score of the winner team will be printed at the end of the game and you can see the 
highscores of all the games in the first menu.
### Bugs
In the future, I'll try to fix the minor bugs that the code has and will post updates for it here.

**Thank You for your attention.**
