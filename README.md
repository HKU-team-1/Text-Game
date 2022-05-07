# Team members
Name: Guan Pinheng 
UID: 3035952604

Name: Zhang Shengce
UID: 3035952721
# Game type: 
Text adventure

# Game background: 
  You are an adventurer who are exploring an unknown forest at the very edge of the world with your reliable teammates. 
  An unexpected storm created a wild flood that took you away from your teammates.
  When you woke up, you found yourself was lying somewhere in the deep forest lonely.
  You need to survive in every unpredictable situation and you must find your teammates to go home.
  Well, it is exactly your daily life style, my great adventurer.
  
# Game description:
  
## Map setting
  There will be 169 regions that can be explored by players, which will be distributed in a 13x13 square.
  The birth point of players will always be the region at left bottom of the square. 
  The destination The region with source of voice will be generated randomly at least 5 regions away from the centre.
   
## How to win the game
  Win: Find your teammates at the destination node.

## Movement
  Players need to type commands such as 'W', 'A', 'S', 'D' to move to next region.
  
## Hints for voice source 
  If you have get close enough to the destination. You will hear voice of your teammates.
  When you get in a square of 9x9 (destination as the centre). You will see this hint:
  "A familiar voice is calling from far away."
  When you get in a square of 5x5 (destination as the centre). You will see this hint:
  "The voice is just next to you."
  The players should plan their route according to these instructions and find the teammates at the destination.
  
## Events
  Players will always meet random events when they move to a region.
  These events require the players to fight with enermies, get buff or debuff and make their own choice for their fate.
  
###### Fight with enermy
  In a 'fight' event, the players will meet a random opposed npc and the players need to win the fight in order to move to next region.
  For current design, the fight will be random games such as 'guessing a number','rock paper scissors' and so on.
  Each player has 3 lives, for each lose of a fight players lose one life and they fail when lives are used up.
  
###### Non-battle events
  Some events may give you buff or debuff as soon as you get to a new region.
  In this case, your fate depends on our random functions. It may save you when you are dying or help you to take your last breath.
  Some events ask you to choose from several choices. 
  In this case, your fate depends on yourself. If you make wise choice, you can be well benefited while on the other hand you may get some serious debuff that keeps you away from success. Fortunately, there is always a choice to run away.
  
# Features

### 1
Initializing the game, the program will randomly assign a certain destination on the map. When the player moves to a new region, they will meet random events. It could be a statue where the player can get magic spells by sacrificing enermy's soul (gems), where the player encounters a fight. (This explains coding requirements 1) and so on.

### 2
Integer will be used to represent the random event, and used to represent the state of the event (whether could the event be triggered, whether has the event happened, could something else happen and so on). (This explains coding requirement 2)

### 3
The memory used by dead characters or dumped weapons and objects will be release. During the game, the instructions and text will also be recorded and saved, so next time the game is read the text will be prompt again. (This uses dynamic memory management. coding requirement 3)

### 4
Game map will be saved in the form of .txt, where both the map data and the character data will be stored and read in the form of string. The prompt history will also be saved and reprinted. (loading and saving of the game. coding requirement 4)

### 5
Object oriented programming will be implemented and the values of the characters will be stored accordingly. (This explains coding requirement 5)

