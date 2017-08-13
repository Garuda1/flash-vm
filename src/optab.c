#include "vm.h"
#include <stdint.h>

/* Opcode table */
uint8_t (*vm_op_tab[])(t_vm *dxvm) =
{
  vm_op_nop,
  vm_op_add,
  vm_op_sub,
  vm_op_xor,
  vm_op_or,
  vm_op_not,
  vm_op_and,
  vm_op_lshift,
  vm_op_rshift,
  vm_op_loada,
  vm_op_loadb,
  vm_op_loadc,
  vm_op_loadd,
  vm_op_push,
  vm_op_pusha,
  vm_op_pushb,
  vm_op_pushc,
  vm_op_pushd,
  vm_op_popa,
  vm_op_popb,
  vm_op_popc,
  vm_op_popd,
  vm_op_jmp,
  vm_op_cjmp,
  vm_op_stop,
  vm_op_eq,
  vm_op_neq,
  vm_op_less,
  vm_op_great,
  vm_op_inc,
  vm_op_dec,
  vm_op_disp
};
