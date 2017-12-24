# DESIGN

### Collaborators
Alex Lu, Ida Wang, Penn Wu

### A High Level Description of the Project
Musical chairs. Except to make it more fun, each chair will also be assigned a probability of death. Dead chair will be chosen after everyone sits down.

### User Interface
One main server that will control the game (i.e. start music, stop music, etc.)  
Rest of the computers will be individual "seats" that connect back to the main server.  
Each computer will play music and display the probability of death in the terminal.

### Technical Design
- kind of an extension of forking server
- main server will assign every computer (subserver??? we don't know how networking works) a probability
- subservers won't need to send any information back to the main server; aka clients (players) will not interact directly with  subservers

**TOPICS:** pipes, networking, memory allocation, processes, signals (maybe)

**DATA STRUCTURES:** arrays, TBD

**ALGORITHMS:**
All seats initially connect to the main server  
Every round, server chooses a seat that will die based on assigned probabilities  
All seats will play music

**BREAKDOWN:**  
Alex:  
Ida:  
Penn:  

### Timeline
`[after break]` Modify current forking server code so the main server can communicate to every subserver over the break  
`[after break]` Finish non-networking stuff (playing music, assigning probabilities, etc.)  
`[after break]` Learn networking after the break and use sockets instead of pipes
