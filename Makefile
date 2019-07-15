CFLAGS=-Wall -std=c++11

build: build-p1 build-p2 build-p3 #build-p4

build-p1:
	g++ $(CFLAGS) p1.cpp -o p1

build-p2:
	g++ $(CFLAGS) p2.cpp -o p2

build-p3:
	g++ $(CFLAGS) p3.cpp -o p3

build-p4:
	g++ $(CFLAGS) p4.cpp -o p4

run-p1:
	./p1

run-p2:
	./p2

run-p3: 
	./p3

run-p4: 
	./p4

clean:
	rm -f p1 p2 p3 p4
