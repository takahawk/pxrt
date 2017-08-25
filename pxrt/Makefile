CFLAGS = -Wpedantic -Werror

SRC = image.c
OBJS = $(SRC:.c=.o)

all: $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f *.o
