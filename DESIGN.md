# DESIGN

### Collaborators
Alex Lu, Ida Wang, Penn Wu

## A High Level Description of the Project
Musical chairs. Except to make it more fun, each chair will also be assigned a probability of death. Dead chair will be chosen after everyone sits down.

## User Interface
One main computer that will control the game (i.e. start music, stop music, etc.). Hopefully selecting songs will be an option.  
Rest of the computers will be the individual "seats" that connect back to the main computer.  
Each computer will play music and display the probability of death in the terminal.

## Technical Design
- kind of an extension of forking server
- main server will assign every computer (subserver??? we don't know how networking works) a probability
- subservers won't need to send any information back to the main server; aka clients (players) will not interact directly with  subservers

**TOPICS:** pipes, networking, memory allocation, processes, signals (maybe)

**DATA STRUCTURES:** arrays, TBD

**BREAKDOWN:**

*Alex:* the networking part, main server 
- networking: sending probability and death signal from the main computer to each "chair"
- modifying forking server so that it uses networking instead

*Ida:* drawing in the terminal, playing music 
- make the probability larger so that it can be easily seen when standing
- turn terminal red to signal death
- figure out how to play music files --> this should only be for the main control computer
- hopefully allow user to select music

*Penn:* probability algorithm
- the sum of each probability of the chairs should add up to 1
- choosing a computer according to the probability

## Timeline
`[after break]` Modify current forking server code so the main server can communicate to every subserver over the break  
`[after break]` Finish non-networking stuff (playing music, assigning probabilities, etc.)  
`[after break]` Learn networking after the break and use sockets instead of pipes
