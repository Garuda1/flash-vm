#include "../vm.h"

uint8_t vm_op_dec(t_vm *dxvm)
{
  --((dxvm->reg)[0]);
  return (VM_STAT_RUN);
}
