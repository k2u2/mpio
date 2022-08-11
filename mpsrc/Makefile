INSTALL = install
INCLUDE_DIR ?= ../include
LIB_DIR ?= ../lib

CXXFLAGS = -pthread -std=c++2a -I.. -fPIC
ARFLAGS = rcs

SRCS := wavy_connect.cc wavy_listen.cc wavy_loop.cc wavy_signal.cc wavy_timer.cc
OBJS := $(addsuffix .o, $(basename $(SRCS)))

TARGETS = libmpio.so libmpio.a

.PHONY: all
all : $(TARGETS)

.PHONY: clean
clean:
	rm -rf $(TARGETS) $(OBJS)

.PHONY: install
install: $(TARGETS)
	mkdir -p $(LIB_DIR)
	$(INSTALL) $(TARGETS) $(LIB_DIR)

libmpio.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

.SUFFIXES: .so
%.so : %.a
	$(CXX) -shared $(CXXFLAGS) -o $@ $?

