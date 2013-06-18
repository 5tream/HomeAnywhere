CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I./ -I../ -I../http/ -I../http/third_libs/ -I../common/utils/ -I./http_plugins -I./resources_handler/

TARGETS = restserver

all: $(TARGETS)

restserver: main.cc rest_server.cc resource.cc url_template.cc ../http/http_message_parser.cc ../http/third_libs/http_parser.c ../http/http_server.cc http_plugins/get_handler.cc resources_handler/get_users.cc
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
