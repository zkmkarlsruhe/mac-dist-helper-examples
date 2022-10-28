# Makefile to build class 'helloworld' for Pure Data.
# Needs Makefile.pdlibbuilder as helper makefile for platform-dependent build
# settings and rules.

# library name
lib.name = hellopd

# input source file (class name == source file basename)
class.sources = hellopd.c

# all extra files to be included in binary distribution of the library
datafiles = README.txt hellopd-help.pd

PDLIBBUILDER_DIR=.
include $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder

##### Makefile-mac-dist.mk

ifeq ($(shell uname -s), Darwin)

# package name
mac.dist.name = $(lib.name)

# set version manually...
mac.dist.version = 1.2.3
# ... or pull version from define in hellopd.c
mac.dist.version = $(shell grep VERSION hellopd.c | awk '{gsub("\"",""); print $$3}')

# binary libs
mac.dist.libs = $(classes.executables)

# things to include with libs
mac.dist.include = $(datafiles) $(datadirs)

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make distdmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

MACDISTHELPER_DIR=../mac-dist-helper
include $(MACDISTHELPER_DIR)/Makefile-mac-dist.mk

# override zip and dmg naming to include platform and arch,
# could include some logic to choose between current arch or "universal"
mac.dmg.name=$(mac.dist.name.version)-macos-$(shell uname -m)
mac.zip.name=$(mac.dist.name.version)-macos-$(shell uname -m)

endif
