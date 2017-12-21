# DESIGN

### Collaborators
Alex Lu, Ida Wang, Penn Wu

### A High Level Description of the Project
Musical chairs. Except to make it more fun, each chair will also be assigned a probability of death. Dead chair will be chosen after everyone sits down.

### User Interface
One main server that will control the game (i.e. start music, stop music, etc.)  
Rest of the computers will be individual "seats" that connect back to the main server.  

### Technical Design
- kind of an extension of forking server
- main server will assign every computer (subserver??? we don't know how networking works) a probability
- subservers won't need to send any information back to the main server; aka clients (players) will not interact directly with  subservers

**TOPICS:** pipes, networking, memory allocation, processes, signals (maybe)

**ALGORITHMS:**

**BREAKDOWN:** 

### Timeline
