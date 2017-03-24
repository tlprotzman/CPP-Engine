OBJS = physics.o particle.o cannon.o
CC = g++
DEBUG = -pg
OPTIMIZATION = -O3
CFLAGS = -Wall -Wextra

all: main.out

debug: CFLAGS += $(DEBUG)
debug: main.out

optimized: CFLAGS += $(OPTIMIZATION)
optimized: main.out

main.out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o main.out

physics.o: physics.cpp physics.h 
	$(CC) $(CFLAGS) -c physics.cpp

particle.o: particle.cpp particle.h 
	$(CC) $(CFLAGS) -c particle.cpp

cannon.o: cannon.cpp physics.cpp physics.h particle.cpp particle.h
	$(CC) $(CFLAGS) -c cannon.cpp

clean:
	$(RM) main.out
	$(RM) *.o
