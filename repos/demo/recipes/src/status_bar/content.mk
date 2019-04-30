content: src/app/status_bar \
         src/server/nitpicker \
         LICENSE

src/app/status_bar:
	mkdir -p $@
	cp -r $(GENODE_DIR)/repos/os/$@/* $@

src/server/nitpicker:
	mkdir -p $@
	cp -r $(GENODE_DIR)/repos/os/$@/* $@

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
