CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I./ -I./http/ -I./http/third_libs/ -I../../server/common/utils/

TARGETS = httpclient

all: $(TARGETS)

httpclient: main.cc http_client.h http_client.cc http/third_libs/http_parser.c http/http_message_parser.cc
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
