#
# Sound test tools Makefile
#
#

prefix	= /tmp
PREFIX	= $(prefix)/soundtest

CC	= arm-xscale-linux-gnueabi-gcc
CFLAGS	= -O2 -DSANDGATE_VP 
STRIP	= arm-xscale-linux-gnueabi-strip
INSTALL	= /usr/bin/install -c

TARGET	= mic \
          mixer_ioctl \
	  mixer_ioctl_oss \
          headphonejack 

all:	$(TARGET)
clean:
	rm -f *.o $(TARGET)
install: all
	$(INSTALL) -d $(DESTDIR)/$(PREFIX)
	$(INSTALL) $(TARGET) $(DESTDIR)/$(PREFIX)
	$(STRIP) $(DESTDIR)/$(PREFIX)/$(TARGET)
uninstall:
	rm -rf $(DESTDIR)/$(PREFIX)

