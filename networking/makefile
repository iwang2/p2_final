select: sclient sserver

sserver: select_server.o networking.o list.o
	gcc -o server select_server.o networking.o list.o

sclient: select_client.o networking.o
	gcc -o client select_client.o networking.o

list.o: list.c list.h
	gcc -c list.c

select_client.o: select_client.c networking.h
	gcc -c select_client.c

select_server.o: select_server.c networking.h list.h
	gcc -c select_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm server
	rm client
	rm *.o
	rm *~
