AR = ar
ARFLAGS = rcs
CXX = g++
CXXFLAGS = 
CPPFLAGS = -Wall
OBJS = error.o errorlog.o
BINS = liblyx_apue.a 

all : $(BINS)

$(BINS) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm *.o

