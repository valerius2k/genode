L4_BUILD_DIR := $(BUILD_BASE_DIR)/var/libcache/syscall-foc/build

SRC_C += errtostr.c
CC_OPT += -I$(L4_BUILD_DIR)/include/x86 \
          -I$(L4_BUILD_DIR)/include/x86/l4f \
          -I$(L4_BUILD_DIR)/include/x86/l4 \
          -I$(L4_BUILD_DIR)/include

vpath errtostr.c $(L4_BUILD_DIR)/source/pkg/l4re-core/l4sys/lib/src
