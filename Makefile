include Makefile.compilation

archive:
	$(TAR) cvf $(TARNAME) code/*
