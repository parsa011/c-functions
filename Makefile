ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

all : c-functions
	cc c-functions.c -o c-functions

install: c-functions
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 c-functions $(DESTDIR)$(PREFIX)/lib/
	#install -d $(DESTDIR)$(PREFIX)/include/
	#install -m 644 unixlib.h $(DESTDIR)$(PREFIX)/include/
