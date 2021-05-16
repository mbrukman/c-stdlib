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

#ifndef _LIBC_STDLIB_H_
#define _LIBC_STDLIB_H_

#include <stddef.h>
#include <internal/unimplemented.h>

// size_t is provided in <stddef.h> and #included here.
// wchar_t is provided in <stddef.h> and #included here.

typedef int div_t;
typedef long ldiv_t;
typedef long long lldiv_t;

// NULL is provided in <stddef.h> and #included here.

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX UNIMPLEMENTED(RAND_MAX)
#define MB_CUR_MAX UNIMPLEMENTED(MB_CUR_MAX)

////////////////////////////////////////////////////////////////////////////////
// 7.20.1 Numeric conversion functions
////////////////////////////////////////////////////////////////////////////////

// 7.20.1.1 The atof function
double atof(const char *nptr);

// 7.20.1.2 The atoi, atol, and atoll functions
int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);

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
void exit(int status);

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
void qsort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *));

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

#endif  // _LIBC_STDLIB_H_
