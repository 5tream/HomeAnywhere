CPP = g++
CFLAGS = -pthread -g -std=c++0x
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

HTTP_PATH = ../http/
REST_PATH = ../restful/
UTILS_PATH = ../common/utils/

INCS = -I./ -I./resources_handler/ -I./entities/ -I../ -I$(HTTP_PATH) -I$(REST_PATH) -I$(HTTP_PATH)third_libs/ -I$(UTILS_PATH) -I$(REST_PATH)http_plugins 

TARGETS = business

HTTP_FILE = $(HTTP_PATH)http_message_parser.cc $(HTTP_PATH)third_libs/http_parser.c $(HTTP_PATH)http_server.cc
REST_FILE = $(REST_PATH)rest_server.cc $(REST_PATH)resource.cc $(REST_PATH)url_template.cc $(REST_PATH)http_plugins/get_handler.cc $(REST_PATH)http_plugins/put_handler.cc

all: $(TARGETS)

business: main.cc $(HTTP_FILE) $(REST_FILE) resources_handler/put_command.cc resources_handler/get_command.cc 
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
