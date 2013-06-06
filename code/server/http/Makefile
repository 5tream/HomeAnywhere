CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I./ -I../ -I./utils/

TARGETS = httpserver

all: $(TARGETS)

httpserver: main.cc http_server.h http_server.cc handler_get.cc utils/http_parser.c
	$(CPP) $(CFLAGS) $(INCS) -o $@ $^


clean:
	rm -f $(TARGETS)
