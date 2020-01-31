Thread : Thread.c 
	gcc -pthread -o Thread Thread.c
	./Thread

clean: 
	-rm Thread
.PHONY: all Thread clean