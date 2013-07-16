CC = gcc
CCFLAGS = -Wall -g -std=gnu99
LDFLAGS = -lreadline
SOURCES = sample.c arbfunc.c
OBJS = $(SOURCES:.c=.o)
DEPS =
EXEC = sample arbfunc

all: $(SOURCES) $(EXEC)

# Build all the object files
%.o: %.c $(DEPS)
	$(CC) -c $(CCFLAGS) -o $@ $<

sample: sample.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

arbfunc: arbfunc.o arbfunc.h
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)