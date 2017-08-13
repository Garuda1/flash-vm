#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "vm.h"

int vm_init(t_vm *vm, const uint8_t *prog)
{
  memset((void*)vm, 0, sizeof(t_vm)); /* Zero out the VM and its registers/memory */
  vm->sp = VM_MEM_SIZE;
  vm_load(vm, prog);
  puts(VM_MSG_INITIALIZED);
  return (EXIT_SUCCESS);
}

int vm_exec(t_vm *vm)
{
  uint32_t cycle;
  uint8_t vmstat;

  cycle = 0;
  puts(VM_MSG_EXECSTARTED);
  while ((vmstat = vm_op_tab[vm->mem[vm->ip]](vm)) != VM_STAT_STOP)
  {
    if (vmstat == VM_STAT_FATAL)
      printf(VM_MSG_FATALERROR "File: " __FILE__ "\nLine: %d\n", __LINE__);
    ++(vm->ip);              /* Increment the instruction pointer */
    vm->ip %= VM_MEM_SIZE; /* Increment the instruction pointer */
    ++cycle;
    if (cycle == VM_DUMP_CYCLE)
    {
      printf(VM_MSG_EXECSTOPPED, cycle);
      vm_dumpmem(vm);
      vmstat = VM_STAT_DUMP;
      break;
    }
  }
  if (vmstat == VM_STAT_STOP)
    puts(VM_MSG_EXECHALTED);
  return (vmstat);
}

int vm_load(t_vm *vm, const uint8_t *prog)
{
  memcpy((char*)(vm->mem), (char*)prog, VM_MEM_SIZE);
  return (EXIT_SUCCESS);
}
