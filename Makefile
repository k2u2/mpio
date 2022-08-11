SUBDIRS = mp mpsrc
PREFIX := $(shell pwd)

export INCLUDE_DIR = $(addprefix $(PREFIX), /include)
export LIB_DIR = $(addprefix $(PREFIX), /lib)

.PHONY: all
all : $(SUBDIRS)
	@for d in $(SUBDIRS); do make -C $$d ; done

.PHONY: clean
clean : $(SUBDIRS)
	@for d in $(SUBDIRS); do make -C $$d clean ; done

.PHONY: install
install : $(SUBDIRS)
	@for d in $(SUBDIRS); do make -C $$d install ; done
