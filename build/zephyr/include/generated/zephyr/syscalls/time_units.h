/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_TIME_UNITS_H
#define Z_INCLUDE_SYSCALLS_TIME_UNITS_H


#include <zephyr/tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <stdarg.h>

#include <zephyr/syscall_list.h>
#include <zephyr/syscall.h>

#include <zephyr/linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_sys_clock_hw_cycles_per_sec_runtime_get(void);

__pinned_func
static inline int sys_clock_hw_cycles_per_sec_runtime_get(void)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke0(K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET);
	}
#endif
	compiler_barrier();
	return z_impl_sys_clock_hw_cycles_per_sec_runtime_get();
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define sys_clock_hw_cycles_per_sec_runtime_get() ({ 	int syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET, sys_clock_hw_cycles_per_sec_runtime_get); 	syscall__retval = sys_clock_hw_cycles_per_sec_runtime_get(); 	sys_port_trace_syscall_exit(K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET, sys_clock_hw_cycles_per_sec_runtime_get, syscall__retval); 	syscall__retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */
