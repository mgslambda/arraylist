test_al_get: test/test_al_get.c src/arraylist.c
	mkdir -p bin
	gcc -o bin/a.out test/test_al_get.c src/arraylist.c
