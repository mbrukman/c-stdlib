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

////////////////////////////////////////////////////////////////////////////////
// 7.20.1 Numeric conversion functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.1.1 The atof function
double atof(const char *nptr);

// 7.20.1.2 The atoi, atol, and atoll functions
int atoi(const char *nptr) {
  int negative = 0;
  int value = 0;

  if (nptr[0] == '-') {
    negative = 1;
    ++nptr;
  }

  while (nptr != NULL) {
    int digit = 0;
    if ('0' <= *nptr && *nptr <= '9') {
      digit = *nptr - '0';
    } else {
      break;
    }
    value = value * 10 + digit;
    ++nptr;
  }

  return negative ? -value : value;
}

long int atol(const char *nptr) {
  int negative = 0;
  long int value = 0;

  if (nptr[0] == '-') {
    negative = 1;
    ++nptr;
  }

  while (nptr != NULL) {
    int digit = 0;
    if ('0' <= *nptr && *nptr <= '9') {
      digit = *nptr - '0';
    } else {
      break;
    }
    value = value * 10 + digit;
    ++nptr;
  }

  return negative ? -value : value;
}

long long int atoll(const char *nptr) {
  int negative = 0;
  long long int value = 0;

  if (nptr[0] == '-') {
    negative = 1;
    ++nptr;
  }

  while (nptr != NULL) {
    int digit = 0;
    if ('0' <= *nptr && *nptr <= '9') {
      digit = *nptr - '0';
    } else {
      break;
    }
    value = value * 10 + digit;
    ++nptr;
  }

  return negative ? -value : value;
}

// 7.20.1.3 The strtod, strtof, and strtold functions
double strtod(const char * restrict nptr, char ** restrict endptr);
float strtof(const char * restrict nptr, char ** restrict endptr);
long double strtold(const char * restrict nptr, char ** restrict endptr);

// 7.20.1.4 The strtol, strtoll, strtoul, and strtoull functions
long int strtol(const char * restrict nptr, char ** restrict endptr, int base);
long long int strtoll(const char * restrict nptr, char ** restrict endptr, int base);
unsigned long int strtoul(const char * restrict nptr, char ** restrict endptr, int base);
unsigned long long int strtoull(const char * restrict nptr, char ** restrict endptr, int base);

////////////////////////////////////////////////////////////////////////////////
// 7.20.2 Pseudo-random sequence generation functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.2.1 The rand function
int rand(void);

// 7.20.2.2 The srand function
void srand(unsigned int seed);

////////////////////////////////////////////////////////////////////////////////
// 7.20.3 Memory management functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.3.1 The calloc function
void *calloc(size_t nmemb, size_t size);

// 7.20.3.2 The free function
void free(void *ptr);

// 7.20.3.3 The malloc function
void *malloc(size_t size);

// 7.20.3.4 The realloc function
void *realloc(void *ptr, size_t size);

////////////////////////////////////////////////////////////////////////////////
// 7.20.4 Communication with the environment
////////////////////////////////////////////////////////////////////////////////

// 7.20.4.1 The abort function
void abort(void);

// 7.20.4.2 The atexit function
int atexit(void (*func)(void));

// 7.20.4.3 The exit function

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

// macOS references:
//
// * https://stackoverflow.com/questions/48845697/macos-64-bit-system-call-table
// * https://stackoverflow.com/questions/11179400/basic-assembly-not-working-on-mac-x86-64lion
// * https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master
// * https://stackoverflow.com/questions/14307623/how-do-i-call-the-write-syscall-using-inline-assembler-in-gcc-under-macos-x
// * https://stackoverflow.com/questions/47801580/can-i-do-ret-instruction-from-code-at-start-in-macos-linux

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
#elif defined(__APPLE__)
  const unsigned int sys_exit = (2 << 24) + 1;
  __asm("movq %0, %%rax\n"
        "movq %1, %%rdi\n"
        "syscall"
        : // no outputs
        : "m" (sys_exit), "m" (status)
        : "rax", "rdi");
#else
#  error "This OS is not 64-bit Linux or macOS (not yet supported)."
#endif
}

// 7.20.4.4 The _Exit function
void _Exit(int status);

// 7.20.4.5 The getenv function
char *getenv(const char *name);

// 7.20.4.6 The system function
int system(const char *string);

////////////////////////////////////////////////////////////////////////////////
// 7.20.5 Searching and sorting utilities
////////////////////////////////////////////////////////////////////////////////

// 7.20.5.1 The bsearch function
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

// 7.20.5.2 The qsort function
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

////////////////////////////////////////////////////////////////////////////////
// 7.20.6 Integer arithmetic functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.6.1 The abs, labs and llabs functions
int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);

// 7.20.6.2 The div, ldiv, and lldiv functions
div_t div(int numer, int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);

////////////////////////////////////////////////////////////////////////////////
// 7.20.7 Multibyte/wide character conversion functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.7.1 The mblen function
int mblen(const char *s, size_t n);

// 7.20.7.2 The mbtowc function
int mbtowc(wchar_t * restrict pwc, const char * restrict s, size_t n);

// 7.20.7.3 The wctomb function
int wctomb(char *s, wchar_t wc);

// 7.20.8.1 The mbstowcs function
size_t mbstowcs(wchar_t * restrict pwcs, const char * restrict s, size_t n);

// 7.20.8.2 The wcstombs function
size_t wcstombs(char * restrict s, const wchar_t * restrict pwcs, size_t n);
