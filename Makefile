CC= gcc
GCCFLAGS= -std=c99 -Wall -pedantic
GCCLIBS= -lm

SOURCES_SERVER= server.c
SOURCES_CLIENT= client.c
SOURCES_CHALLENGES= desafios.c

OBJECTS_CHALLENGES=$(SOURCES_CHALLENGES:.c=.o)

EXECUTABLE_SERVER= server
EXECUTABLE_CLIENT= client

all: $(OBJECTS_CHALLENGES) client
	$(CC) $(GCCFLAGS) $(SOURCES_SERVER) $(OBJECTS_CHALLENGES) -I./include -o $(EXECUTABLE_SERVER) $(GCCLIBS)

%.o: %.c
	$(CC) $(GCCFLAGS) -I./include -c $^ $(GCCLIBS)

client:
	$(CC) $(GCCFLAGS) $(SOURCES_CLIENT) -o $(EXECUTABLE_CLIENT)

clean:
	rm -rf *.o server client

.PHONY: all clean cleanTest test client