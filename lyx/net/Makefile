#VPATH = src include

AR = ar
ARFLAGS = rcs
CXX = g++
# CXXFLAGS = -I./include
CPPFLAGS = -Wall
OBJS = socketutil.o
BINS = liblyx_netutil.a

all : $(BINS)

$(BINS) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: clean

clean:
	-rm *.o


