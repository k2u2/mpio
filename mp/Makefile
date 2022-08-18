INSTALL = install
MPLEX = ../mplex
INCLUDE_DIR ?= ../include
LIB_DIR ?= ../lib

build_HEADERS = $(addsuffix .h, $(basename $(wildcard *.hmpl)))
TARGETS = $(build_HEADERS)

.PHONY: all
all : $(TARGETS)

.PHONY: clean
clean :
	@rm -rf $(TARGETS)

.PHONY: install
install : $(TARGETS)
	@mkdir -p $(join $(INCLUDE_DIR),/mp)
	$(INSTALL) *.h $(join $(INCLUDE_DIR),/mp)

.SUFFIXES: .hmpl
%.h : %.hmpl
	$(MPLEX) -r../mpl $< -o $@

