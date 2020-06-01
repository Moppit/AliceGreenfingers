# Alice Greenfingers Sim

## Disclaimer
This is based on the wonderful game, Alice Greenfingers by the Arcade Lab, and is not my own idea. I'm merely a fan, and I miss the game; however, my computer software is too new for me to buy the current available version.

Also, a disclaimer for non-legal purposes: I coded this late at night in a frenzy of longing for nostalgia, so if you're wondering why this code looks prototype-y and not at all thought through, that's because it is. I didn't plan on making this repo public, especially since I don't plan on working on this more in the future unless I find myself with copious amounts of free time. However, there is a chance that someone else might garner some joy from this, and adding joy to the world overrides software developer shame in my opinion. So, hope you enjoy it!

## Game
Alice Greenfingers is the ultimate chill farm game. I used to play it to destress, and although this rudimentary text-based version isn't quite the same, listening to the soundtrack (.mp3 file included in repo) while playing this version helps.

In the game, Alice is represented by the symbol 'A' and can be moved around by the keys J, I, K, and L, which represent left, up, down, and right, respectively. Other commands are listed in the legend beneath the inventory and balance. To execute a command, type the character that represents the command, and press ENTER.

Note: you can type multiple commands at once! i.e. If you want to dig, plant a tomato plant, and then move down, you can do it like so:
```
> dptk
```
And all four of those commands will be executed at once!

## Installation
Clone this repo and execute the following commands (make sure you have the g++ compiler):
```
> cd AliceGreenfingers
> g++ main.cpp actions.cpp
> ./a.out
```
And you're all set!

## To Do's (if I or anyone else gets to them)

### Future Features
- Spending money: Right now, we can earn money, but we can't really spend it except for by digging, which is kind of a silly way to lose money.
  - It would be nice to be able to purchase more features, like trees and henhouses, maybe bees
  - Needs to account for large amasses of money -- so make things on a spectrum of expensiveness
- Include more seeds: only have 4 right now, and you can't change the amount you have, which is a bummer
  - Will need more colors and symbols in that case
- From both of the above, looks like a store feature would be nifty
- Boxes, which would require crops to be sold in sets
- Integrate the music in the program so you don't have to use the Music app
- Grandma (or Uncle Barry for the sequel): having some objectives for the game would be neat
- Improving the market: the market array currently operates like a stack (as in, items are purchased with the first-in last-out principle), which is predictable
- Fluctuating crop prices

### Bugs/General Items to be Fixed

#### Major/Critical
- Software structure: since I sped-coded it in a few hours on the fly, it requires some major structural enhancements. i.e. Modularization, generalizing functions/code reuse, actually using classes, etc.
- Fix x and y coordinate flip: right now, have to pass in coordinates as y,x which is confusing and may lead to unintuitive bugs
- Figure out how to print out map without hard-coding the dimensions (will allow for customizable spaces)
- Comment everything

#### Minor
- Sprite disappears: when Alice plants something or harvests, she disappears (but reappears on the next move)
- Find a way to incorporate color in the Crop struct so you don't have to deal with clunky if statements
- Fix the save feature: repeated loops are no good
- Fix marketplace banner: "Alice Greenfingers" is slightly off center
- Can overlap patches: Need to be able to detect existing patches to prevent digging mishaps
  - Example of current behavior: [ ]A -> Press D -> [ [A]
