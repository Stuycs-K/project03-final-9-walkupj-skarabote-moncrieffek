default: compile
compile runme:  main.o library.o linkedlist.o
	@gcc -o runme linkedlist.o library.o main.o
main.o: main.c library.h linkedlist.h
	@gcc -c main.c
library.o: library.c linkedlist.h
	@gcc -c library.c
linkedlist.o: linkedlist.c 
	@gcc -c linkedlist.c
run: runme 
	@./runme $(ARGS)
clean:
	@rm *.o
	@rm runme
	@rm *~



# notDefault:
# 	@echo "nothing is run"
# compile: client1 server2

# client1: basic_client.o pipe_networking.o
# 	@gcc -o client1 basic_client.o pipe_networking.o

# server2: forking_server.o pipe_networking.o
# 	@gcc -o server2 forking_server.o pipe_networking.o

# server: server2
# 	@./server2

# client: client1
# 	@./client1

# basic_client.o: basic_client.c pipe_networking.h
# 	@gcc -c basic_client.c

# forking_server.o: forking_server.c pipe_networking.h
# 	@gcc -c forking_server.c

# pipe_networking.o: pipe_networking.c pipe_networking.h
# 	@gcc -c pipe_networking.c

# clean:
# 	@rm *.o
# 	@rm *~