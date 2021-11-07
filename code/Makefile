### 
## 
## MATH0500-1 Introduction à l'algorithmique numérique
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

# Files
EXEC=test
MODULES=main.c functions.c
OBJECTS=main.o functions.o

## Rules

all: $(EXEC)

test: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

functions.o: functions.c
	$(CC) -c functions.c -o functions.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~

