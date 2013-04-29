#VPATH = src include
#CXXFLAGS = -I./include
AR = ar
ARFLAGS = rcs
CXX = g++
INCLUDES = -I../include
LKFLAGS += -L../lib/ -L.
LKLIBS += -llyx_netutil
CPPFLAGS += -Wall
CXXFLAGS += $(INCLUDES) $(LKFLAGS)
OBJS = net_test.o
BINS = net_test

all : $(BINS)

$(BINS) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LKLIBS)

.PHONY: clean

clean:
	-rm *.o net_test


