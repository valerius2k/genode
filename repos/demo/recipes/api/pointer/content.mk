content: include/pointer LICENSE

include/pointer:
	mkdir -p $(dir $@)
	cp -r $(GENODE_DIR)/repos/os/$@ $@

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
