# Networking examples

## Files
* networking.h/.c
  * Code to set up socket connections for both server and client programs.
* client.c
  * Basic netowork client.
* forking_server.c
  * Network based forking server.
* select_server.c
  * Forking server code with example `select()` useage.
* select_client.c
  * Basic client code with example `select()` usage.
* makefile
  * make: Creates forking server/client programs.
  * make select: Creates select server/client programs.

## Select Statement
* The `select()` function allows a program to handle input from multiple filed descriptors (and other things).
* You can combine multiple file descriptors into a single set of inputs.
* `select()` will block until any of the set file descriptors are ready.
* Once triggered, you can check which file descriptor(s) became ready, then act accordingly.
* **select_server.c** and **select_client.c** have example select code.

## Networking Setup
### Main Server
1. wait for clients/players to connect until user prompts game start (no longer accept connections)
2. server will send start message to clients
3. play music from main server, until user prompts stop
4. server will calculate probability for each player and send to each client
5. after prompting from user, randomly choose a dead computer
6. send death signal to that computer
7. repeat 2-6 until there is only 1 client left, which is the winner

#### Looping through file descriptors for sockets
In Beej's guide, ctrl-f `selectserver.c -- a cheezy multiperson chat server`. This shows code for looping through everything and updating the total number of connected clients; modify so that it won't be reading, but just adding things.

### Clients
1. connect to server to be apart of the game
2. when start message received, set screen to be blank
3. when probability received, print ascii art thing
4. if dead, set screen to be red. otherwise, reset.
