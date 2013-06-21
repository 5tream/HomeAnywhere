CC = arm-linux-g++
CFLAGS = -g -pthread
CFLAGS += -D__INFO -D__ERROR -D__FATAL
LIBS = -ljpeg
API_DIR = ../../client/api/
INCS = -I$(API_DIR) -I$(API_DIR)entities/ -I$(API_DIR)http/ -I$(API_DIR)http/third_libs -I../../server/common/utils/

TARGETS = device_car

SRC = main.c\
	  capture.c\
	  serial.c\
	  command_extractor.c\
	  command_parser.c\
	  video_container.c\
	  jpeg_encoder_mjpeg.c\
	  jpeg_encoder_yuv422.c\
	  my_callbackfunc.cc\
	  $(API_DIR)device_api.cc\
	  $(API_DIR)http_client.cc\
	  $(API_DIR)http/http_message_parser.cc\
	  $(API_DIR)http/third_libs/http_parser.c

$(TARGETS):$(SRC)
	$(CC) $(CFLAGS) $(INCS) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

.PHONY:clean
clean:
	rm -rf *.o *.swp $(TARGETS)
