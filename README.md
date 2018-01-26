# :musical_note: Musical Chairs :musical_note:

### Collaborators
**Period :four:** : Alex Lu, Ida Wang, Penn Wu

### A Broad Description of this Project
Musical chairs, except to make it more fun and unfair, the dead chair is chosen after everyone sits down. Each computer will display the probability of dying while the music plays, and each player must be seated at a computer by the end of each round.

To make things a little more festive (since this game is psychologically rather cruel), all music is Christmas-themed. :christmas_tree:

### Some More Detail on How This Thing Works
We have one main computer, essentially the "server", that controls the game. It is the computer that all the players ("clients") connect to, and the computer that calculates the probability of death and determines which chair will be the "dead" chair.

On the client end, not much is happening. As the music is running, the probability of death will be displayed in the terminal (in large ascii art so it can be seen while standing; each number found at *[this](http://patorjk.com/software/taag/#p=display&h=0&v=0&f=Doh&t=0123456789%25)* website under the "doh" font). Once the music stops, the chosen dead computer will display a death message to signify that it is no longer in the game. 

### Required Libraries
To play music, `mpg123` must be installed. This is only necessary for the main server (a.k.a. the computer that will be running the game).
```
$ sudo apt-get install mpg123
```
Assuming the speakers on the main computer are loud enough, clients won't need to install this (also our program doesn't play music from the client end). 

### Compilation Instructions
1. `$ make` to compile all the necessary files
2. Have the server computer run `./server`
3. Have each client run `./client SERVER_IP`, substituting in the IP address of the server
4. Play the game, moving on to the next round by pressing the ENTER key on the server

### Bugs (or as we like to call them, "unique features") :bug: :honeybee: :ant: :beetle:
- If a client exits prematurely (before being killed off), everything breaks and probability can't be assigned correctly.
- The probability assigning algorithm itself is heavily biased. Computers that connect first have a greater chance of getting killed off.
