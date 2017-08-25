PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC = main.c
OBJS = $(SRCd:.c=.o)

all: pxrt

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

pxrt: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f pxrt
