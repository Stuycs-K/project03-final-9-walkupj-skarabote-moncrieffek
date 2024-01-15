default: compile
compile runme:  main.o library.o linkedlist.o music.o
	@gcc -o runme linkedlist.o library.o main.o music.o
main.o: main.c library.h linkedlist.h music.c
	@gcc -c main.c
library.o: library.c linkedlist.h
	@gcc -c library.c
linkedlist.o: linkedlist.c
	@gcc -c linkedlist.c
music.o: music.c music.h
	@gcc -c music.c
run: runme
	@./runme $(ARGS)
clean:
	@rm *.o
	@rm runme
	@rm *~


# notDefault:
# 	@echo "nothing is run"
# compile: client server

# client: client.o networking.o
# 	@gcc -o client client.o networking.o

# server: server.o networking.o
# 	@gcc -o server server.o networking.o


# client.o: client.c networking.h
# 	@gcc -c client.c

# server.o: server.c networking.h
# 	@gcc -c server.c

# networking.o: networking.c networking.h
# 	@gcc -c networking.c

# clean:
# 	@rm *.o
# 	@rm server
# 	@rm client
# 	@rm *~
