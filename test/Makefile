all: test

clean:
	$(MAKE) -C example_end_to_end clean
	$(MAKE) -C recordio_end_to_end clean
	$(MAKE) -C regression_1_default_field_buffer_overrun clean

example_end_to_end:
	$(MAKE) -C $@

recordio_end_to_end:
	$(MAKE) -C $@

regression_1_default_field_buffer_overrun:
	$(MAKE) -C $@

test: example_end_to_end recordio_end_to_end regression_1_default_field_buffer_overrun

.PHONY: clean example_end_to_end recordio_end_to_end regression_1_default_field_buffer_overrun test
