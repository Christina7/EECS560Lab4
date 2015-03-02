lab4: lab4.o queue.o
	g++ -g -std=c++11 lab4.o tree.o queue.o -o lab4

lab4.o: lab4.cpp tree.o
	g++ -c -g -std=c++11 lab4.cpp

tree.o: tree.cpp queue.o
	g++ -c -g -std=c++11 tree.cpp

queue.o: queue.cpp 
	g++ -c -g -std=c++11 queue.cpp

clean:
	rm -f *~ *.o
