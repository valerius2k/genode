content: src/test/nitpicker LICENSE

src/test/nitpicker:
	mkdir -p $@
	cp -r $(GENODE_DIR)/repos/os/$@/* $@

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
