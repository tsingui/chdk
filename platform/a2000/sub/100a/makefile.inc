# a2000 - 100a uses 100c source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100c

include $(camfw)/makefile.inc
