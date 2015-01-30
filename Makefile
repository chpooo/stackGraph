CPP=g++
CFLAGS=-std=c++11 -w -c
CC=$(CPP) $(CFLAGS)
OBJS=InvertedList.o
test: testInvertedList
testInvertedList: InvertedListTest.o $(OBJS)
	$(CPP) -o testInvertedList $(OBJS) InvertedListTest.o
clean:
	rm -rf *.o
	rm -rf test*
InvertedList.o:
		$(CC) InvertedList.cc
#test
InvertedListTest.o:
		$(CC) InvertedListTest.cc
