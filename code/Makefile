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
MODULES=main.c functions2.c
OBJECTS=main.o functions2.o

## Rules

all: $(EXEC)

test: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

functions2.o: functions2.c
	$(CC) -c functions2.c -o functions2.o $(CFLAGS)

clean:
	rm -f *.o $(EXEC) *~

