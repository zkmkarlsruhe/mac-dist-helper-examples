
VERSION = 0.1.0

CFLAGS = -I./
LDFLAGS = -L./

PLATFORM=$(shell uname -s)
ifeq ($(PLATFORM), Darwin)
	CFLAGS += -mmacosx-version-min=10.9
endif

.PHONY: libgreet libpaths checklibpaths clean

all: libgreet hello libpaths

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

ifeq ($(PLATFORM), Darwin)
# add Info.plist contents for notarization
HELLO_LDFLAGS += -sectcreate TEXT info_plist Info.plist
endif

hello: ${HELLO_FILES:.c=.o}
	$(CC) -o $@ $^ $(LDFLAGS) $(HELLO_LDFLAGS)

##### libpaths

.PHONY: libpaths checklibpaths

ifeq ($(PLATFORM), Darwin)

# disambiguate dynamic lib paths, required to run on other systems
libpaths:
	install_name_tool -id @executable_path/$(LIBGREET) $(LIBGREET)
	install_name_tool -change $(LIBGREET) @executable_path/$(LIBGREET) $(HELLO)

# print current paths
checklibpaths:
	otool -L $(LIBGREET) $(HELLO)

# Windows, Linux
else

libpaths:

checklibpaths:

endif

##### clean

clean:
	rm -f *.o $(HELLO) $(LIBGREET)

##### Makefile-mac-dist.mk

# base disttribution name
mac.dist.name = hello

# console programs
mac.dist.progs = $(HELLO)

# dynamic libraries (.dylib)
mac.dist.libs = $(LIBGREET)

mac.dist.version = $(VERSION)

# additional files to add to distribution
mac.dist.include = README.txt

# add link to /Applications in dmg
mac.dmg.appslink = false

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make app distdmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

# specify optional entitlements for codesigning
# ie. to disable dynamic library validation, etc
#mac.codesign.entitlements = hello.entitlements

MACDISTHELPER_DIR=../mac-dist-helper
include $(MACDISTHELPER_DIR)/Makefile-mac-dist.mk
