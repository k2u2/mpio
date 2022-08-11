CXXFLAGS = -pthread -std=c++2a -I.. -Wall
LDFLAGS =
LDLIBS = ../mpsrc/libmpio.a

TARGETS = $(basename $(wildcard *.cc))

.PHONY: all
all : $(TARGETS)

.PHONY: clean
clean :
	rm -rf $(TARGETS)

.PHONY: install
install : $(TARGETS)
