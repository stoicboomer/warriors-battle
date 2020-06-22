# warriors-battle 


Fight between 2 fighters; gameplay is turn-based, where the warrior chooses his action between attack, defense, parry, where attacking deals damage and uses STAMINA, defending reduces the damage taken and restores some stamina, and last but not least parrying has a chance to stun the enemy; either succeeding and failing the parry gives stamina. ![Shitty gameplay](https://media.discordapp.net/attachments/392746939415789569/724750528273449150/unknown.png?width=435&height=367)

## Tutorial

src/warrior.c -> warrior logic, stats and movement.
src/win.c	  -> windows managment.
src/colors.c  -> colors.

> See config.h to modify players stats, stamina costs and colors! 

WASD to move the player, one move per turn.

1 - Attack, deals damage and spends stamina
2 - Defende, reduces damage taken for the next coming attack and increases warrior stamina.
3 - Parry, try to parry next enemy's attack and get a chance to stun him; increases warrior stamina.


### Installation

You need ncurses library to compile the game:
> sudo apt-get install libncurses-dev

Play:
> ./compile && ./game

#### TODO

- [x] Remake of the game from C++ to C with ncurses
- [x] Make the game playable.
- [ ] Find someone to play with
- [ ] Fix stupid logic errors and try to make the game balanced.
- [ ] Add scrolling log messages.
- [ ] Add multiplayer. (yes)

Ye. I learnt a lot by coding this game. This is what matters, knowledge. -Alex 
