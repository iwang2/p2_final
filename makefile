all: sclient sserver

sserver: select_server.o networking.o algo.o play_song.o
	gcc -o server select_server.o networking.o algo.o play_song.o

sclient: select_client.o networking.o print_num.o
	gcc -o client select_client.o networking.o print_num.o

algo.o: algo.c algo.h
	gcc -c algo.c

print_num.o: print_num.c print_num.h
	gcc -c print_num.c

play_song.o: play_song.c play_song.h
	gcc -c play_song.c

select_client.o: select_client.c networking.h print_num.h
	gcc -c select_client.c

select_server.o: select_server.c networking.h algo.h play_song.h
	gcc -c select_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm server
	rm client
	rm *.o
	rm *~
