MEMORY
{
    rom (rx) : ORIGIN = 0, LENGTH = 2M
    ram (rwx) : ORIGIN = 0x20000000, LENGTH = 4M
}

SECTIONS
{
    . = 0x0;
    
    .text : {
        *(vectors)
        *(.text)
        *(.rodata)
    }
    
    . = 0x20000000;
        .data : {
        *(.data)
    }
    
    .bss : {
        *(.bss)
    }
}


