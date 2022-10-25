
VERSION = 0.1.0

CFLAGS = -I./ -mmacosx-version-min=10.9
LDFLAGS = -L./

.PHONY: libgreet rpath rpath-check clean

all: libgreet hello rpath

##### libgreet

LIBGREET = libgreet.dylib
LIBGREET_FILES = libgreet.c

libgreet: $(LIBGREET)

$(LIBGREET): ${LIBGREET_FILES:.c=.o}
	$(CC) -o $@ $^ -shared

##### hello

HELLO = hello
HELLO_FILES = hello.c
HELLO_LDFLAGS = -lgreet

# add Info.plist contents for notarization
HELLO_LDFLAGS += -sectcreate TEXT info_plist Info.plist -I.

hello: ${HELLO_FILES:.c=.o}
	$(CC) -o $@ $^ $(LDFLAGS) $(HELLO_LDFLAGS)

##### libpaths

# disambiguate dynamic lib paths
libpaths:
	install_name_tool -id @executable_path/$(LIBGREET) $(LIBGREET)
	install_name_tool -change $(LIBGREET) @executable_path/$(LIBGREET) $(HELLO)

# print current paths
checklibpaths:
	otool -L $(LIBGREET) $(HELLO)

##### clean

clean:
	rm -f *.o $(HELLO) $(LIBGREET)

##### mac-dist-helpers

mac.dist.name = hello
mac.dist.progs = $(HELLO)
mac.dist.libs = $(LIBGREET)

mac.dist.version = $(VERSION)
mac.dist.include = README.txt

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make app distdmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

# specify optional entitlements for codesigning, ie. disable dynamic library validation, etc
#mac.codesign.entitlements = hello.entitlements

include ../mac-dist-helpers/Makefile-mac-dist.mk
