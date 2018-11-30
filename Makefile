CC=gcc
CFLAGS=-Wall -Wextra -lm

.PHONY: all ll

all:
	$(CC) linked_list.c queue.c array.c graph.c main.c -o main
	./main
	rm -f main

ll:
	$(CC) linked_list.c linked_list_test.c -o ll
	./ll
	rm -f ll

queue:
	$(CC) queue.c queue_test.c -o queue
	./queue
	rm -f queue

array:
	$(CC) array.c array_test.c -o array
	./array
	rm -f array

graph:
	$(CC) linked_list.c queue.c array.c graph.c graph_test.c -o graph
	./graph
	rm -f graph

kruskal:
	$(CC) linked_list.c kruskal.c kruskal_test.c -o kruskal
	./kruskal
	rm -f kruskal