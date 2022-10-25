# app name to build (no extension) for Makefile-mac-app.mk
mac.app.name = HelloWorld

# dist name and app for Makefile-mac-dist.mk,
# define these if not using Makefile-mac-app.mk
#mac.dist.name = HelloWorld
#mac.dist.apps = $(mac.dist.name).app

# pull version string from project, this is slow...
#mac.dist.version := $(shell xcodebuild -showBuildSettings 2> /dev/null | grep MARKETING_VERSION | tr -d 'MARKETING_VERSION =')

# ... or set it manually
mac.dist.version = 0.1.0

# additional files to add to distribution?
#mac.dist.include = README.txt

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make app distdmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

include ../mac-dist-helpers/Makefile-mac-app.mk
include ../mac-dist-helpers/Makefile-mac-dist.mk

mac.dmg.name=$(mac.dist.name.version)-macos-$(shell uname -m)
mac.zip.name=$(mac.dist.name.version)-macos-$(shell uname -m)