#include "../vm.h"
#include <stdio.h>

uint8_t vm_op_disp(t_vm *dxvm)
{
  ++(dxvm->ip);
  (dxvm->ip) %= VM_MEM_SIZE;
  putchar((dxvm->mem)[dxvm->ip]);
  return (VM_STAT_RUN);
}
