# notenogram
### (read as note-nogram)
Chill analog-styled Gameboy Advance picross/nonogram/hanjie/griddler game made with [Butano](http://https://github.com/GValiente/butano) for [GBA Jam 2022](http://https://itch.io/jam/gbajam22), with some gameplay elements inspired by [Battle Picross by Sean Reid](https://pdroms.de/files/nintendo-gameboyadvance-gba/battle-picross-v1-0).

## Features (WIP, subject to change):
* 12 original 12x12 picross puzzles to solve
* cringy Japanese anime girl voice clips provided by me
* fancy bossanova module music *not* made by me (not now at least)
* possible story mode that will put one's strategy skills to the test and have a different ending based on said skills
* maybe a tutorial mode that explains various solving strategies just because
* creator mode that allows making puzzles and sharing them via GBA save files (*any* save files)
* original character cameos of some sort?

## Controls:
* **A button** - color the square the pen cursor is pointing at/confirm menu option
* **B button** - cross out the square/exit menu
* **D-pad** - move the cursor (*hint: pressing and holding a directional key while holding A or B on the picross grid will mark otherwise empty squares as either "on" or "off" in the selected direction*)
* **Select** - exit puzzle screen
* **Start (in creator mode)** - write current puzzle to SRAM
* **L or R button (in creator mode)** - switch custom puzzle slots in SRAM to write to (only three slots available for now, writing to a full slot will overwrite its contents)

##Issues
The biggest issue for now is making the creator mode work properly on VBA-M since it will write to SRAM only on top of an already existing (and legit) save file and only after closing the emulator. That's it.

##TODO
* Completely replace boolean arrays with unsigned integers for quicker reads, writes and condition checks
* Figure out how to design the main game state interface class to avoid any chaos in overridden methods and simplify game loop coding (and reduce used backgrounds)
* Story mode - add scenarios, character sprites, timer for puzzle solving and variables for writing various puzzle solving stats of the player
* Make some lo-fi tracker beats to solve griddlers to
* Bwehh
