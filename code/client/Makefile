CPP = g++
CFLAGS = -pthread -g
CFLAGS += -D__DEBUG -D__INFO -D__ERROR -D__FATAL

INCS = -I./ -I./api/ -I./api/entities/ -I./api/http/ -I./api/http/third_libs/ -I../server/common/utils/

TARGETS = demo

all: $(TARGETS)

demo: demo_client.cc my_callbackfunc.cc api/device_api.cc api/http_client.cc api/http/third_libs/http_parser.c api/http/http_message_parser.cc
	$(CPP) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^


clean:
	rm -f *.o *.swp *~ $(TARGETS)
