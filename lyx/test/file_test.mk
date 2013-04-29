AR = ar
ARFLAGS = rcs
CXX = g++
INCLUDES = -I../include
LKFLAGS += -L../lib/ -L.
LKLIBS += -llyx_fileutil -llyx_apue
CPPFLAGS += -Wall
CXXFLAGS += $(INCLUDES) $(LKFLAGS)
OBJS = file_test.o
BINS = file_test

all : $(BINS)

$(BINS) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LKLIBS)

# test : test.o File.o
# g++ $^ -o $@ $(LKFLAGS) -lapue
#test: test.o File.o
# g++ $(INCLUDES) $^ -o $@ $(LKFLAGS)
#	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o
