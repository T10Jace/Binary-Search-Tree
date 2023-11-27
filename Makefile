#	Author: Jace Riley
#	File:   Makefile
#	Date:   September 25, 2023

CC = g++ 	# this is the compiler we are using

CFLAGS = -c -Wall -Wextra	# Compiles with all errors and warnings

TARGET = BST	# assigning bst as our target

all: $(TARGET)		# Target for building all

$(TARGET): driver.o BST.o Node.o				#target for linking all .o files and creating binary $(TARGET)
	$(CC) driver.o BST.o Node.o -o $(TARGET)

driver.o: driver.cpp		     # Compiles BST.o from source (BST.cpp)
	$(CC) $(CFLAGS) driver.cpp

BST.o: BST.cpp BST.h	 	# Compiles BST.o from source (BST.cpp)
	$(CC) $(CFLAGS) BST.cpp

Node.o: Node.cpp Node.h	 # Compiles Node.o from source (Node.cpp)
	$(CC) $(CFLAGS) Node.cpp


clean:						 # Removes all objects, emacs backups, and target
	$(RM) $(TARGET) *.o *~