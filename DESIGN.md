# DESIGN

**note:** see `ideas.md` file for our other ideas if this one is too dumb

### Collaborators
Alex Lu, Ida Wang, Penn Wu

## A High Level Description of the Project
Musical chairs. Except to make it more fun (and unfair), each chair will also be assigned a probability of death. Dead chair will be chosen after everyone sits down.

## User Interface
One main computer that will control the game (i.e. start music, stop music, etc.). All control will be from the terminal. Hopefully selecting songs will be an option.  
Rest of the computers (clients) will be the individual "seats" that connect back to the main computer.  
Each computer display the probability of death in the terminal. The main computer will play music.

## Technical Design
- kind of an extension of forking server
- main server will assign every computer (subserver??? we don't know how networking works) a probability
- subservers won't need to send any information back to the main server; aka clients (players) will not interact directly with  subservers
- Clients do not exit until the game is over 

**TOPICS/DATA STRUCTURES:** 
- pipes: connect server and subservers. Sockets (we think) will connect subservers and clients (other computers).
- networking: connect subservers that are on one machine to clients on other machines
- memory allocation: do we even need this? we'll find out
- processes: forking server, with the addition that the server will be able to talk to the subservers
- signals: server will kill clients one by one
- arrays: keep track of clients
- struct client {int prob (out of 1000); int status (0/1);};

**BREAKDOWN:**

*Alex:* the networking part, main server communicating with client 
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
`[01.19.18]` Finish the project 

*Alex's Timeline:* 
`[Approximately 01.02.18 - 01.05.18]` Learn about the wonders of networking 
`[01.07.18]` Setup a forking server that works with sockets rather than pipes 
`[01.14.18]` Allow the subservers to communicate with the main server, preferably with pipes (in lieu of sockets) 

*Ida's Timeline:* 
`[Approximately 01.01.18 - 01.05.18]` Learn about playing music 
`[01.x.18]` 
`[01.x.18]` 
`[01.x.18]` 
`[01.x.18]` 

*Ida:* drawing in the terminal, playing music 
- make the probability larger so that it can be easily seen when standing
- turn terminal red to signal death
- figure out how to play music files --> this should only be for the main control computer
- hopefully allow user to select music 

*Penn's Timeline:* 
`[01.03.18]` Settle on an algorithm for choosing a computer
`[01.04.18]` Implement said algorithm
`[01.14.18]` Modify code to communicate between multiple computers rather than multiple terminals















































          


          

          


              




  
