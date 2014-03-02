all: test

clean:
	-rm script.actual

test:
	szl -program script.szl --print_source=true > script.actual
	diff -u script.actual script.golden

.PHONY: clean test
