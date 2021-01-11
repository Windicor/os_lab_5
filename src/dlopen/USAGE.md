gcc -fPIC -c mylib.c

gcc -shared -o libmy.so mylib.o

gcc -c main.c

gcc main.o -Wl,-rpath,. -ldl
