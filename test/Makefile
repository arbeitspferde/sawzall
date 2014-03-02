all: test

example_end_to_end:
	$(MAKE) -C $@

regression_1_default_field_buffer_overrun:
	$(MAKE) -C $@

test: example_end_to_end regression_1_default_field_buffer_overrun

.PHONY: example_end_to_end regression_1_default_field_buffer_overrun test
