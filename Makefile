PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)

SRC = pxrt.c
BUILT_SRC = resources.c
OBJS = $(SRC:.c=.o) $(BUILT_SRC:.c=.o)

all: pxrt

resources.c: pxrt.gresource.xml pxrt_window.glade
	$(GLIB_COMPILE_RESOURCES) pxrt.gresource.xml --target=$@ --sourcedir=. --generate-source

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

pxrt: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f *.o
	rm -f pxrt
	rm -f $(BUILT_SRC)
