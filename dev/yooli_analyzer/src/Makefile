
OBJ = yooli_analyzer.o lyxUrl.o

all: yooli_analyzer

yooli_analyzer: ${OBJ}
	g++ -o $@ $^

lyxUrl.o: lyxUrl.h

.PHONY: clean
clean:
	-rm *.o yooli_analyzer


