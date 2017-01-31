CC := g++

CFLAGS += -g

OBJ += main.o
OBJ += robosapien.o

DEP = $(subst .o,.d,$(OBJ))

TARGET := cmd_robo

all: $(OBJ)
	gcc $(OBJ) -o cmd_robo -lwiringPi
	

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.d: %.c
	gcc -MM $(CFLAGS) $< > $@

include $(DEP)
