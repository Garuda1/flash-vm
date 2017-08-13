#include "../vm.h"

uint8_t vm_op_or(t_vm *dxvm)
{
  (dxvm->reg)[0] |= (dxvm->reg)[1];
  return (VM_STAT_RUN);
}
