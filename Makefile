tree_demo: main.o tree.o  
	g++ -o tree_demo main.o tree.o

main.o: main.cpp
	g++ -c main.cpp

tree.o: tree.cpp tree.h
	g++ -c tree.cpp

clean:
	rm *.o tree_demo
    
