#Platform specific file for *nixes


FULLVERSION = $(MAJORVERSION).$(MINORVERSION).$(REVISION)

ECHO = echo
#TEST = $(ECHO) #comment to enable build
SLASH = /
COPY = $(TEST) cp -r
REMOVE = $(TEST) rm -f
REMDIR = $(TEST) rm -rf
MKDIR = $(TEST) mkdir -p
AR = ar
GMON =
FIXDFILES = ./Fixdfiles
DIREXISTS = ./DirExists
EXTRACFLAGS = -fPIC

SHAREDLIBEXT = .so

PLATFORM = NIX

ifndef INSTALLDIR
   INSTALLDIR = /usr/local
endif


