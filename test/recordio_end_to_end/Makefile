all: test

clean:
	-rm src/main/java/Event.java
	mvn clean
	-rm events.recordio
	-rm output.actual

src/main/java/Event.java: event.proto
	protoc --java_out=src/main/java event.proto

test: event.proto events.recordio output.golden summary.szl
	szl -program summary.szl \
	    --protocol_compiler=$(ROOT)/bin/protoc \
	    --protocol_compiler_plugin=$(ROOT)/bin/protoc-gen-szl \
	    --use_recordio=true \
	    events.recordio \
	    --table_output="*" > output.actual
	diff -u output.golden output.actual

events.recordio: target/recordioentoend-1-jar-with-dependencies.jar
	java -jar target/recordioentoend-1-jar-with-dependencies.jar > $@

target/recordioentoend-1-jar-with-dependencies.jar: $(STAMPS)/jdk src/main/java/Event.java
	mvn compile
	mvn assembly:assembly
	mvn assembly:single

$(STAMPS)/jdk:
	$(AG_INSTALL) openjdk-6-jdk
	touch $@

.PHONY: clean test
