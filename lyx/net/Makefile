#VPATH = src include
#CXXFLAGS = -I./include

net_test: net_test.o SocketUtility.o
	g++ $^ -o $@

net_test.o: SocketUtility.h

.PHONY: clean

clean:
	-rm *.o net_test


