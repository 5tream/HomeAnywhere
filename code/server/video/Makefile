CC = gcc
CFLAGS = -g -Wall -pthread
CFLAGS += -D__DEBUG

INC = -I../common/utils
LIBS =

TARGET = video_server
OBJS = main.o\
	   video_server.o\
	   video_stream.o\
	   video_container.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $<

.PHONY: clean

clean:
	rm -rf *.o *.swp *~ $(TARGET)
