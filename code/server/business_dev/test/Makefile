CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I../ -I../../http/ -I../../http/third_libs/ -I../../common/utils/ -I./http_plugins

TARGETS = business

all: $(TARGETS)

business: main.cc ../../http/http_message_parser.cc ../../http/third_libs/http_parser.c ../../http/http_server.cc http_plugins/http_get_command.cc 
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
