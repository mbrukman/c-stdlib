// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdlib.h>

// Relevant docs:
//
// * How system calls work on Linux (covers 32-bit and 64-bit):
//   https://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/
// * 64-bit system call numbers (this points to syscall 231, `sys_exit_group`):
//   https://github.com/torvalds/linux/blob/17ae69aba89dbfa2139b7f8024b757ab3cc42f59/arch/x86/entry/syscalls/syscall_64.tbl#L242
// * https://man7.org/linux/man-pages/man3/exit.3.html
// * https://man7.org/linux/man-pages/man2/exit.2.html
// * https://man7.org/linux/man-pages/man2/_exit.2.html
// * https://pubs.opengroup.org/onlinepubs/7908799/xsh/_exit.html
// * https://stackoverflow.com/questions/46903180/syscall-implementation-of-exit

// TODO(mbrukman): this function definition is not complete as we are not
// handling all the relevant cleanup operations that need to happen here.
__attribute__((used))
void exit(int status) {
#if defined(__linux__) && defined(__LP64__)
  const unsigned long sys_exit_group = 231;
  __asm("movq %0, %%rax\n"
        "movq %1, %%rdi\n"
        "syscall"
        : // no outputs
        : "m" (sys_exit_group), "m" (status)
        : "rax", "rdi");
#else
#  error "This OS is not 64-bit Linux (not yet supported)."
#endif
}
