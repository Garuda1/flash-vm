#include "../vm.h"

uint8_t vm_op_pushc(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->reg)[2];
  return (VM_STAT_RUN);
}
