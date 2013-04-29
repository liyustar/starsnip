INCLUDES = -I../include
LKFLAGS += -L./../lib
CXXFLAGS += $(INCLUDES)
CPPFLAGS += -Wall

all : test
test : test.o File.o
	g++ $^ -o $@ $(LKFLAGS) -lapue
#test: test.o File.o
# g++ $(INCLUDES) $^ -o $@ $(LKFLAGS)
#	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.gch test *.o
