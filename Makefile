all: map1 map2

map1: bst_1.o utils_1.o data_1.o main_1.o
	gcc -o map1 bst_1.o utils_1.o data_1.o main_1.o -lm
	
map2: bst_2.o utils_2.o data_2.o main_2.o
	gcc -o map2 bst_2.o utils_2.o data_2.o main_2.o -lm

bst_1.o: bst_1.c bst_1.h
	gcc -c -Wall bst_1.c

utils_1.o: utils_1.c utils_1.h
	gcc -c -Wall utils_1.c

data_1.o: data_1.c data_1.h
	gcc -c -Wall data_1.c

main_1.o: main_1.c
	gcc -c -Wall main_1.c
	
bst_2.o: bst_2.c bst_2.h
	gcc -c -Wall bst_2.c

utils_2.o: utils_2.c utils_2.h
	gcc -c -Wall utils_2.c

data_2.o: data_2.c data_2.h
	gcc -c -Wall data_2.c

main_2.o: main_2.c
	gcc -c -Wall main_2.c