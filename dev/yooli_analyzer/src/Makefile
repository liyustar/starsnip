
OBJ = yooli_analyzer.o lyxUrl.o lyxSocket.o lyxHttp.o

all: yooli_analyzer

yooli_analyzer: ${OBJ}
	g++ -o $@ $^

lyxUrl.o: lyxUrl.h
lyxHttp.o: lyxHttp.h lyxUrl.h lyxSocket.h
lyxSocket.o: lyxSocket.h

.PHONY: clean
clean:
	-rm *.o yooli_analyzer


