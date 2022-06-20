GCC= gcc
GCCFLAGS= -std=c99 -Wall -pedantic
GCCLIBS= -lm

SOURCES_SERVER= server.c
SOURCES_CLIENT= client.c
SOURCES_CHALLENGES= desafios.c

OBJECTS_CHALLENGES=$(SOURCES_CHALLENGES:.c=.o)

EXECUTABLE_SERVER= server
EXECUTABLE_CLIENT= client

all: $(OBJECTS_CHALLENGES) client
	$(GCC) $(GCCFLAGS) $(SOURCES_SERVER) $(OBJECTS_CHALLENGES) -I./include -o $(EXECUTABLE_SERVER) $(GCCLIBS)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $^ $(GCCLIBS)

client:
	$(GCC) $(GCCFLAGS) $(SOURCES_CLIENT) -o $(EXECUTABLE_CLIENT)

clean:
	rm -rf *.o server client

cleanTest:
	rm -rf output.cppOut report.tasks results.valgrind

test: clean 
	./pvs.sh; cppcheck --quiet --enable=all --force --suppress=missingIncludeSystem --inconclusive server.c desafios.c client.c 2>> output.cppOut; valgrind --leak-check=full -v ./server 2>> results.valgrind; valgrind --leak-check=full -v ./client 2>> results.valgrind 

.PHONY: all clean cleanTest test client