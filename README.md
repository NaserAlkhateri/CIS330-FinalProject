** Project name: Manhunt

** Project repository:
https://bitbucket.org/a77med/uo-cis330-project

** Team members:
Ahmed Al-Ali
Naser AlKhateri
Majed AlMazrouei

** Description (1-3 paragraphs):
Initially, the game is a grid of (ROW)*(COL) slots. As the player, you can only see yourself in that grid. 
However, somewhere in that grid exists a hidden opponent. How can you find someone or something you cannot see? 
Every three moves, a hint drops, stating the closest direction of the opponent. The game can be further developed by
placing traps or allowing the opponent to move every round as well. Those might be modes of the main game, or levels
to completion. This idea can be further developed in different directions.

** Implementation approach:
There is a huge probability that the use of vectors can be 
helpful in the implementation. Basically, by grasping ideas from classes
and templates, we plan to implement them to keep track of the opponent
by a boolean assigned to every slot and tracking that is tracking
the opponent.


** Risk management plan (max 1 paragraph):
There is a possibility that expanding this idea might take an extremely
long time to implement since adding new ideas will require adding new rules to 
be theorized before even implementing them.

** How to run?

Make file is included in the project.

* To run normal test 

type in the bash:
make

then type: 
./manhunt.exe

this should run the game.

* To run memory check:

type in the bash:
make memcheckManhunt.exe

then type: 
./memcheckManhunt.exe

this should run the game with valgrind (Checks memory leakage).
