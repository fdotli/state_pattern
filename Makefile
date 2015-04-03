SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
INCLUDES = -I.
LIBS = -L. -lrt -ldl
CCFLAGS = -g -Wall -O0
my_app : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(CCFLAGS)
%.o : %.c
	$(CC) -c $< $(CCFLAGS)
clean:
	-rm my_app

