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
	rm *.o
	rm runme
