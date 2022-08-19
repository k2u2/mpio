INSTALL = install
INCLUDE_DIR ?= ../include
LIB_DIR ?= ../lib

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

CXXFLAGS = -pthread -std=c++2a -I.. -fPIC
ARFLAGS = rcs

CPPFLAGS = -I..

SRCS := wavy_connect.cc wavy_listen.cc wavy_loop.cc wavy_signal.cc wavy_timer.cc
OBJS := $(addsuffix .o, $(basename $(SRCS)))
DEPS := $(addprefix deps/, $(addsuffix _dep, $(SRCS)))

TARGETS =  libmpio.so libmpio.a

.PHONY: all
all : $(TARGETS)

.PHONY: clean
clean :
	rm -rf $(TARGETS) $(OBJS) deps

.PHONY: install
install : $(TARGETS)
	@mkdir -p $(LIB_DIR)
	$(INSTALL) $(TARGETS) $(LIB_DIR)

libmpio.a : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

.SUFFIXES: .so
%.so : %.a
	$(CXX) -shared $(CXXFLAGS) -o $@ $?

.SUFFIXES: .cc_dep
deps/%.cc_dep : %.cc
	@mkdir -p deps
	@$(CPP) $(CPPFLAGS) -MM $< -MF $@

-include $(DEPS)
