test_al_get: test/test_al_get.c src/arraylist.c
	mkdir -p bin
	gcc -o bin/a.out test/test_al_get.c src/arraylist.c -lm

test_al_add: test/test_al_add.c src/arraylist.c
	mkdir -p bin
	gcc -o bin/a.out test/test_al_add.c src/arraylist.c -lm

test_al_remove: test/test_al_remove.c src/arraylist.c
	mkdir -p bin
	gcc -o bin/a.out test/test_al_remove.c src/arraylist.c -lm

test_al_add_end: test/test_al_add_end.c src/arraylist.c
	mkdir -p bin
	gcc -o bin/a.out test/test_al_add_end.c src/arraylist.c -lm
