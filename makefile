all: sclient sserver

sserver: select_server.o networking.o list.o algo.o
	gcc -o server select_server.o networking.o list.o algo.o

sclient: select_client.o networking.o print_num.o
	gcc -o client select_client.o networking.o print_num.o

list.o: list.c list.h
	gcc -c list.c

algo.o: algo.c algo.h
	gcc -c algo.c

print_num.o: print_num.c print_num.h
	gcc -c print_num.c

select_client.o: select_client.c networking.h print_num.h
	gcc -c select_client.c

select_server.o: select_server.c networking.h list.h algo.h
	gcc -c select_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm server
	rm client
	rm *.o
	rm *~
