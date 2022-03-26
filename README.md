# Team members
Name: Guan Pinheng 
UID: 3035952604
# Game type: 
Text adventure

# Game background: 
  You are an adventurer who are exploring an unknown forest at the very edge of the world. 
  A storm came and the last thing you remembered before you passed out was a giant wave of flood water.
  When you woke up, you found yourself was lying somewhere underground and all your teammates were missing.
  You knew that staying where you woke up might be a sensible idea to meet with your teammates again.
  However, you heard an unclear voice that is calling your name and you could not help your curiosity to follow the voice.
  Was the voice from your teammates or something else?
  Whatever, a new adventure has started.
  
# Game description:
  //All rules mentioned below might be changed in further development.
  
## Map setting
  There will be 49 regions that can be explored by players, which will be distributed in a 7x7 square.
  The birth point of players will always be the region at centre of the square. 
  The region with source of voice will be generated randomly at least 4 regions away from the centre.
  An injured teammate will be randomly generated on the edge (the frame of the square).
  
## Win/pass the game
  Win: Find the injured teammate and gather with everyone at the source of voice.
  Pass: Gather with survivors at the source of voice.
  
## Movement
  Players need to type commands such as 'Go North','Go West' to move to next region.
  After each movement, there will be sentences to descibe the new region. 
  It includes description of the environment, hints and events.
  
## Hints for voice source 
  After each movement, there will be sentences printed on the screen to state the distance between the player and the voice.
  "The voice calling you name becomes weaker/larger/disappears/is so close to you/is right here."
  The players should plan their route according to these instructions and find the source at the end.
  
## Hints for the injured teammate
  When the player gets closed to the injured teammates (with a distance within 2 regions), there will be sentences printed on the screen.
  "That is Iris' bottle! She has been here. God bless her."/"The cloth has the same color as Sam's shirt! Hope he is fine"
  The players should search nearby regions to find their lost teammate in order to actually win the game.
  
## Events
  Except the birth region, players will meet random events when they move to a new region.
  These events require the players to 'fight' or 'decide'.
  
###### Fight
  In a 'fight' event, the players will meet a random opposed npc and the players need to win the fight in order to move to next region.
  For current design, the fight will be random games such as 'guessing a number','rock paper scissors' and so on.
  Each player has 3 lives, for each lose of a fight players lose one life and they fail when lives are used up.
  
###### Decide
  In a 'decide' event, the players need to make decisions for the situation they meet to move to next region.
  The result will differ according to players' choices, which might be buff(gain one life), debuff(lose one life), tools(help players win the 'fight') or even finding a hidden opposed npc.
  
  
