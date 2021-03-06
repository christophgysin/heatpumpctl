B = bin
T = all help clean depend edit_cache install install/local install/strip \
	list_install_components package package_source rebuild_cache test \

default: config all test

config:
	(mkdir -p ${B} && cd ${B} && cmake ..)

$(T):
	(cd ${B} && make $@ VERBOSE=$(VERBOSE))

clang:
	make CC=/usr/bin/clang CXX=/usr/bin/clang++ default

.PHONY: $(T)
