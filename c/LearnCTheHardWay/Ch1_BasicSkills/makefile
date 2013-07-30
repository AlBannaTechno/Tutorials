CFLAGS = -Wall -g -DNDEBUG

EXEC = ex1 ex3 ex4 ex4-fixed ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex13-2 ex14 ex14-2 ex15 ex15-2 ex16 ex16-2 ex17 ex17-2 ex18 ex18-2 ex19 ex20 ex22_main ex23 ex24 ex24-2 ex25
SRCS = $(EXEC:=.c)

OBJS    = object ex22
ALLOBJS = $(OBJS:%=%.o)


all: $(EXEC)

$(EXEC): $(SRCS) $(ALLOBJS)
	$(CC) $(CFLAGS) $@.c -o $@

ex19: object.o
	$(CC) $(CFLAGS) object.o ex19.c -o ex19

ex22_main: ex22.o
	$(CC) $(CFLAGS) ex22.o ex22_main.c -o ex22_main

clean:
	$(RM) $(EXEC) $(EXEC:=.exe) $(ALLOBJS)
