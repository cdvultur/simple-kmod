obj-m += simple-kmod.o

ifndef KVER
KVER=$(shell uname -r)
endif

ifndef VER
VER=$(shell git describe HEAD 2>/dev/null || git rev-parse --short HEAD)
endif

buildprep:
	sudo yum install -y make gcc kernel-{core,devel,headers,modules}-$(KVER)
all:
	make -C /lib/modules/$(KVER)/build M=$(PWD) EXTRA_CFLAGS=-DKMODVERSION=\\\"$(VER)\\\" modules
clean:
	make -C /lib/modules/$(KVER)/build M=$(PWD) clean
install:
	sudo install -v -m 755 -d /lib/modules/$(KVER)/
	sudo install -v -m 644 simple-kmod.ko /lib/modules/$(KVER)/simple-kmod.ko
