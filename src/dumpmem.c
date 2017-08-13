#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "vm.h"

static void dump_entry(const uint8_t add, const uint8_t val)
{
  printf("%2X:%2X ", add, val);
}

void vm_dumpmem(const t_vm *dxvm)
{
  size_t x;
  size_t y;

  puts("--- MEMORY DUMP ---");
  y = 0;
  while (y < (VM_MEM_SIZE / (VM_DUMPMEM_ENTRIES_PER_LINE-1)))
  {
    putchar('\n');
    x = 0;
    while (x < VM_DUMPMEM_ENTRIES_PER_LINE && (y * VM_DUMPMEM_ENTRIES_PER_LINE) + x < VM_MEM_SIZE)
    {
      dump_entry((y * VM_DUMPMEM_ENTRIES_PER_LINE) + x, dxvm->mem[(y * VM_DUMPMEM_ENTRIES_PER_LINE) + x]);
      ++x;
    }
    ++y;
  }
  #if VM_DUMPREGS == 1
  puts("Registers:");
  printf("%a:  "); tty_putn_hex2(dxvm->reg[0]);
  printf("\n%b:  "); tty_putn_hex2(dxvm->reg[1]);
  printf("\n%c:  "); tty_putn_hex2(dxvm->reg[2]);
  printf("\n%d:  "); tty_putn_hex2(dxvm->reg[3]);
  printf("\n%sp: "); tty_putn_hex2(dxvm->sp);
  printf("\n%ip: "); tty_putn_hex2(dxvm->ip);
  #endif
  puts("\n--- MEMORY DUMP ---\n");
}
