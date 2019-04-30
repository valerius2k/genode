content: src/app/pointer \
         src/server/report_rom \
         LICENSE

src/app/pointer:
	mkdir -p $@
	cp -r $(GENODE_DIR)/repos/os/$@/* $@

src/server/report_rom:
	mkdir -p $@
	cp -r $(GENODE_DIR)/repos/os/$@/* $@

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
