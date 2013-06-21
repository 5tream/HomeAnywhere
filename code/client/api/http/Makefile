CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I./ -I../ -I./third_libs/ -I../common/utils/
LIBS = -L./third_libs/

TARGETS = httpserver

all: $(TARGETS)

httpserver: main.cc http_server.h http_server.cc handler_get.cc third_libs/http_parser.c http_message_parser.cc
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
