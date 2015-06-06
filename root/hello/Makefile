ifneq ($(KERNELRELEASE),)
obj-m := hello_version.o
else
KDIR := /media/padmakar/WORK/Device-Drivers/Device-drivers-practice/free-electronics/linux-kernel-labs//src/kernel/kernel
all:
	$(MAKE) -C $(KDIR) M=$$PWD

clean:	
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif

