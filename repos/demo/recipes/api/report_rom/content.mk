content: include/report_rom LICENSE

include/report_rom:
	mkdir -p $(dir $@)
	cp -r $(GENODE_DIR)/repos/os/$@ $@

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
