# Makefile pour le module iZap

KERNELDIR = /usr/src/linux

include $(KERNELDIR)/.config

CFLAGS = -D__KERNEL__ -DMODULE -I$(KERNELDIR)/include \
	-O -Wall

ifdef CONFIG_SMP
	CFLAGS += -D__SMP__ -DSMP
endif

all: izap.o

# Décommenter les lignes suivantes en cas de plusieurs fichiers objets
# izap.o: fichier1.o fichier2.o
#	$(LD) -r $^ -o $@

clean:
	rm -f *.o *~ core
