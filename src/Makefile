CC= i686-elf-g++
LD = i686-elf-gcc
AS = nasm
ASPARAMS = -f elf32
CCPARAMS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fpermissive
LDPARAMS = -ffreestanding -O2 -nostdlib -lgcc -T linker.ld

objects = boot.o kernel.o

%.o: %.cpp
	$(CC) $(CCPARAMS) -c $< -o $@

%.o: %.s
	$(AS) $(ASPARAMS) $< -o $@

kernel.bin: $(objects)
	$(LD) $(LDPARAMS) $(objects) -o $@

sys.iso: kernel.bin
	mkdir -p build/boot/grub
	echo 'set timeout=0' > build/boot/grub/grub.cfg
	echo 'set default=0' >> build/boot/grub/grub.cfg
	echo 'menuentry "AnaOS"{' >> build/boot/grub/grub.cfg
	echo 'multiboot /boot/$<' >> build/boot/grub/grub.cfg
	echo 'boot' >> build/boot/grub/grub.cfg
	echo '}'  >> build/boot/grub/grub.cfg
	mv $< build/boot
	grub-mkrescue -o $@ build

clean:
	rm *.o
	rm -rf build
	rm *.iso
