# Copyright (c) 2022 ZKM | Hertz-Lab
# Dan Wilcox <dan.wilcox@zkm.de>
#
# BSD Simplified License.
# For information on usage and redistribution, and for a DISCLAIMER OF ALL
# WARRANTIES, see the file, "LICENSE.txt," in this distribution.
#
# This code has been developed at ZKM | Hertz-Lab as part of "The Intelligent
# Museum" generously funded by the German Federal Cultural Foundation.
#
# See https://github.com/zkmkarlsruhe/mac-dist-helper-examples

# app name to build (no extension)
mac.app.name = HelloWorld

# pull version string from project, this is slow...
#mac.dist.version := $(shell xcodebuild -showBuildSettings 2> /dev/null | grep MARKETING_VERSION | tr -d 'MARKETING_VERSION =')
# ... or set it manually
mac.dist.version = 0.1.0

# additional files to add to distribution
mac.dist.include = README.txt

# add link to /Applications in dmg
mac.dmg.appslink = true

# codesign identity, usually a Developer ID Application string
# REPLACE this with your own or set it via the commandline:
# make app dist-dmg mac.codesign.identity="Foo Bar Baz Developers"
mac.codesign.identity = ZKM | Zentrum fuer Kunst und Medientechnologie Karlsruhe

MACDISTHELPER_DIR=../mac-dist-helper
include $(MACDISTHELPER_DIR)/Makefile-mac-dist.mk

# for completeness
.PHONY: clean
clean:
