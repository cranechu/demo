gcc -c -I. -g hello-tp.c
gcc -c -g hello.c
gcc -o hello hello.o hello-tp.o -llttng-ust -ldl
