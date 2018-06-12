main.o: main.cpp
	g++ -g main.cpp -o main.out

clean:
	rm *.o