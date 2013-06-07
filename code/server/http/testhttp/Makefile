CC = gcc
CPP = g++

CFLAGS = -pthread -g -D__DEBUG -D__INFO -D__ERROR -D__FATAL
INCS = -I../ -I../../

TARGETS = testhttp

all: $(TARGETS)

testhttp: testhttp.cc
	$(CPP) $(CFLAGS) $(INCS) -o $@ $^

clean:
	rm -f *.o *.swp *~ $(TARGETS)
