#include "../vm.h"

uint8_t vm_op_loadd(t_vm *dxvm)
{
  (dxvm->reg)[3] = (dxvm->mem)[++(dxvm->ip) % VM_MEM_SIZE];
  return (VM_STAT_RUN);
}
