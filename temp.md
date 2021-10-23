# Specification for "Temple Golem"

Temple Golem is a simple 2D RPG platform game.

The game starts on the menu screen, awaiting user imput.

## Main Menu

The main menu screen shows certain informations:
- that it indeed is the main menu screen;
- the currently set player name;
- a button to start a new game;
- a button to see the scoreboard;
- a button to alter certain settings;
- a button to exit the game.

## The gameplay

In game, the player is moved with the following keys:
- ↑ Up arrow, making the character jump;
- ← Left arrow, making the character move left;
- → Right arrow, making the character move right.

In the game, the player tries to clear each map (of 3), collecting gems at the fastest speed
possible. The end score is calculated accordingly:

[end score] := *integer function of* ( 1 / [time with millisecond accuracy] ) * 100,000 * ( [collected gems] / [all gems] ) ^ 2

As shown in the expression above, a run of `97.375s` time (even though the in game timer would show
97.4s) with the collection of `11` of the 12 available gems would generate a score of `862`, while
one done in `114.943s` but collecting all `12` gems would result in a score of `869`.

This means that collecting no gems automatically results in a score of 0.

### Physics

The character in game is controllable with 3 of the arrow keys, as specified above. We expect not
only to have it respond to them, but to interact with its surroundings. Walls and floor tiles push
back against our character, to put it simply, we collide with solid objects.

Water and lava have a different effect though. They alter the character's look and properties, and
slow it down all together. Walking in water or lava slows the character dawn to half speed.
Additionally, every 3 seconds spent in water or lava change the characters "rigidity". Less rigid
means that the character walks overall slower and jumps lower.

Stages of rigidness:

0. Rigid   - Initial attribute, normal values (of force).
1. Drippy  - Normal forces cut in half.
2. Flowy   - Normal forces cut in quarter.
3. Flowing - This stage marks the player's death.

## New Game

From the main menu, clicking on the "New Game" button, one can start a new game.

A map is finished when the end door is reached. This places the player on the next map, until the
last one where reaching the end door brings up a summary of the run.

It is possible to pause the game in progress, but there is no option to save a run's progress.

### Pause Menu

The pause menu is similar to the main menu of the game. It shows the following:
- text clarifying that this is the pause menu;
- a "Return to Game" button;
- a "Exit to Main Menu" button;
- a "Exit the Application" button.

## Settings

There are certain aspects of the game the user can change:
- The "Player name" (this will show on the scoreboard)
- The window's resolution (this requires a restart)

#### Available window resolutions:
(In pixels.)

- 320  x 240p
- 640  x 480p
- 960  x 720p
- 1280 x 960p	(default)
- 1600 x 1200p
