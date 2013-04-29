AR = ar
ARFLAGS = rcs
CXX = g++
INCLUDES = -I../include
LKFLAGS += -L../lib/
LKLIBS += -lapue
CPPFLAGS += -Wall
CXXFLAGS += $(INCLUDES) $(LKFLAGS) $(LKLIBS)
OBJS = fileutil.o
BINS = liblyx_fileutil.a

all : $(BINS)

$(BINS) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# test : test.o File.o
# g++ $^ -o $@ $(LKFLAGS) -lapue
#test: test.o File.o
# g++ $(INCLUDES) $^ -o $@ $(LKFLAGS)
#	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o
