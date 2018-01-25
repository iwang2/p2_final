all: sclient sserver

sserver: select_server.o networking.o list.o
	gcc -o server select_server.o networking.o list.o

fserver: forking_server.o networking.o
	gcc -o server forking_server.o networking.o

sclient: select_client.o networking.o
	gcc -o client select_client.o networking.o

client: client.o networking.o
	gcc -o client client.o networking.o

list.o: list.c list.h
	gcc -c list.c

select_client.o: select_client.c networking.h
	gcc -c select_client.c

client.o: client.c networking.h
	gcc -c client.c

select_server.o: select_server.c networking.h list.h
	gcc -c select_server.c

forking_server.o: forking_server.c networking.h
	gcc -c forking_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm server
	rm client
	rm *.o
	rm *~
