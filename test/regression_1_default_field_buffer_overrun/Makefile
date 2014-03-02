all: test

clean:
	-rm script.actual

test:
	szl -program script.szl \
	  --protocol_compiler=$(ROOT)/bin/protoc \
	  --protocol_compiler_plugin=$(ROOT)/bin/protoc-gen-szl \
	  --print_source=true > script.actual
	diff -u script.actual script.golden

.PHONY: clean test
