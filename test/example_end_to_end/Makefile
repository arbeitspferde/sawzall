all: test

clean:
	-rm output.actual

test:
	szl -program example.szl example.input --table_output topwords > output.actual
	diff -u output.actual output.golden

.PHONY: clean test
