CC = gcc
CFLAGS = -g -Wall -pthread
CFLAGS += -D__DEBUG

INC = -I../common/utils
LIBS =

TARGET = video_server
OBJS = main.o\
	   video_server.o\
	   video_stream.o\
	   video_container.o\
	   client_service.o

TEST_DIR = test/
TEST_TARGET = video_server_test
TEST_OBJS = $(OBJS)\
			fake_http_server.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $<

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

%.o: $(TEST_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $<

.PHONY: clean

clean:
	rm -rf *.o *.swp *~ $(TARGET) $(TEST_TARGET)
