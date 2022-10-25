# Attempt to load a config.make file.
# If none is found, project defaults in config.project.make will be used.
ifneq ($(wildcard config.make),)
	include config.make
endif

# make sure the the OF_ROOT location is defined
ifndef OF_ROOT
	OF_ROOT=$(realpath ../../of/of_v0.11.2_osx_release)
endif

# call the project makefile!
include $(OF_ROOT)/libs/openFrameworksCompiled/project/makefileCommon/compile.project.mk

##### mac-dist-helpers

# app name to build
mac.app.name = HelloOF

# set version manually
mac.dist.version = 0.1.0

# openFrameworks projects use the "APPNAME Release" and "APPNAME Debug" naming
mac.app.project.scheme = $(mac.app.name) Release

# include openFrameworks project data
mac.dist.include = bin/data

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make app distdmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

include ../mac-dist-helpers/Makefile-mac-app.mk
include ../mac-dist-helpers/Makefile-mac-dist.mk
