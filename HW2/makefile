main: main.o libfoo.so
	g++ -Wall -o main main.o -lfoo -L.

main.o: main.cpp
	g++ -c -Wall main.cpp -o main.o

libfoo.so: hello.o
	g++ -shared -o libfoo.so hello.o

hello.o: hello.cpp 
	g++ -c -Wall -fPIC hello.cpp -o hello.o
	
run: main
	LD_LIBRARY_PATH=. ./main
