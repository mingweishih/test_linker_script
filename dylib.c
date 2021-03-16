#include <stdio.h>
#include <stdint.h>

extern char __reloc_start;
extern char __reloc_end;

uint64_t reloc_start;
uint64_t reloc_end;


void test_dylib()
{
    reloc_start = (uint64_t)&__reloc_start;
    reloc_end = (uint64_t)&__reloc_end;

    printf("[dylib] relo section range: 0x%lx - 0x%lx\n", reloc_start, reloc_end);
}
