CC = g++
CFLAGS = -O3

CPP_FILE = BST.cpp BSTNode.cpp

all:
	$(CC) $(CFLAGS) $(CPP_FILE) main.cpp

clean:
	rm a.out
