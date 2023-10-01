cmake_minimum_required(VERSION 3.5)
project(Miura)

add_custom_command(
    OUTPUT limine
    COMMAND git clone https://github.com/limine-bootloader/limine.git --branch=v5.x-branch-binary --depth=1
    COMMAND make -C ${PROJECT_BINARY_DIR}/limine
)
add_custom_target(limine-build ALL DEPENDS limine)

file(GLOB ARCH ${PROJECT_SOURCE_DIR}/arch/*)
add_subdirectory(${PROJECT_SOURCE_DIR}/library/libk)
add_subdirectory(${PROJECT_SOURCE_DIR}/kernel)
add_subdirectory(${ARCH})

make_directory(${PROJECT_BINARY_DIR}/iso)

# set(TARGET_ARCH x86_64)
# file(GLOB_RECURSE ARCH_FILE ${PROJECT_BINARY_DIR}/arch/*/miura.elf)

add_custom_command(
    OUTPUT miura.iso
    DEPENDS ${PROJECT_BINARY_DIR}/limine ${ARCH_FILE} $<TARGET_FILE:miura.elf> limine-build    
    COMMAND cp ${PROJECT_BINARY_DIR}/limine/limine-bios.sys
        ${PROJECT_BINARY_DIR}/limine/limine-bios-cd.bin     
        ${PROJECT_BINARY_DIR}/limine/limine-uefi-cd.bin     
        ${PROJECT_SOURCE_DIR}/limine.cfg      
        $<TARGET_FILE:miura.elf>
        ${PROJECT_BINARY_DIR}/iso
        COMMAND xorriso -as mkisofs -b limine-bios-cd.bin
        -no-emul-boot -boot-load-size 4 -boot-info-table        
        --efi-boot limine-uefi-cd.bin   
        -efi-boot-part --efi-boot-image --protective-msdos-label
        ${PROJECT_BINARY_DIR}/iso -o ${PROJECT_BINARY_DIR}/miura.iso
        COMMAND ${PROJECT_BINARY_DIR}/limine/limine bios-install ${PROJECT_BINARY_DIR}/miura.iso        
    )
add_custom_target(generate-iso ALL DEPENDS miura.iso )

# shortcut for qemu
add_custom_target(run
    COMMAND qemu-system-x86_64 -m 1G -smp 1 -s  -serial stdio  --enable-kvm
	-drive file=${PROJECT_BINARY_DIR}/miura.iso,if=none,media=disk,id=disk,index=3,format=raw
	-device ahci,id=ahci
	-device ide-hd,drive=disk,bus=ahci.0
	-device qemu-xhci,id=xhci -device usb-kbd,id=kbd,bus=xhci.0
	-device usb-mouse,id=mouse,bus=xhci.0 
	# -d trace:usb_*
)