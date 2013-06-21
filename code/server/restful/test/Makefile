CC = gcc
CPP = g++

CFLAGS = -g -D__DEBUG -D__INFO -D__ERROR -D__FATAL
INCS = -I../ -I../http/ -I../../common/ -I../../common/utils/

TARGETS = test

all: $(TARGETS)

test: test.cc ../user_handler.cc
	$(CPP) $(CFLAGS) $(INCS) -o $@ $^

clean:
	rm -f *.o *.swp *~ $(TARGETS)
