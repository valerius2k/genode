PORT_DIR := $(call port_dir,$(REP_DIR)/ports/fatfs)

content: src/lib/fatfs/source \
         include/fatfs \
         src/server/fatfs_fs \
         LICENSE

include/fatfs:
	mkdir -p $@
	cp -r $(PORT_DIR)/include/fatfs/* $@

src/lib/fatfs/source:
	mkdir -p $@
	cp -r $(PORT_DIR)/src/lib/fatfs/source/* $@

src/server/fatfs_fs:
	$(mirror_from_rep_dir)

LICENSE:
	cp $(PORT_DIR)/src/lib/fatfs/LICENSE.txt $@
