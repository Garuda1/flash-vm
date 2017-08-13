#include "../vm.h"

uint8_t vm_op_eq(t_vm *dxvm)
{
  dxvm->flag = ((dxvm->reg)[0] == (dxvm->reg)[1] ? 1 : 0);
  return (VM_STAT_RUN);
}
