#include "../vm.h"

uint8_t vm_op_loadb(t_vm *dxvm)
{
  (dxvm->reg)[1] = (dxvm->mem)[++(dxvm->ip) % VM_MEM_SIZE];
  return (VM_STAT_RUN);
}
