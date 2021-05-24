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

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// 7.19.2 Streams
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// 7.19.3 Files
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// 7.19.4 Operations on files
////////////////////////////////////////////////////////////////////////////////

// 7.19.4.1 The remove function
int remove(const char *filename);

// 7.19.4.3 The tmpfile function
FILE* tmpfile(void);

// 7.19.4.4 The tmpnam function
char* tmpnam(char *s);

////////////////////////////////////////////////////////////////////////////////
// 7.19.5 File access functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.5.1 The fclose function
int fclose(FILE *stream);

// 7.19.5.2 The fflush function
int fflush(FILE *stream);

// 7.19.5.3 The fopen function
FILE *fopen(const char * restrict filename, const char * restrict mode);

// 7.19.5.4 The freopen function
FILE *freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);

// 7.19.5.6 The setvbuf function
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);

////////////////////////////////////////////////////////////////////////////////
// 7.19.6 Formatted input/output functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.6.1 The fprintf function
int fprintf(FILE * restrict stream, const char * restrict format, ...);

// 7.19.6.2 The fscanf function
int fscanf(FILE * restrict stream, const char * restrict format, ...);

// 7.19.6.3 The printf function
int printf(const char * restrict format, ...);

// 7.19.6.4 The scanf function
int scanf(const char * restrict format, ...);

// 7.19.6.5 The snprintf function
int snprintf(char * restrict s, size_t n, const char * restrict format, ...);

// 7.19.6.6 The sprintf function
int sprintf(char * restrict s, const char * restrict format, ...);

// 7.19.6.7 The sscanf function
int sscanf(const char * restrict s, const char * restrict format, ...);

// 7.19.6.8 The vfprintf function
int vfprintf(FILE * restrict stream, const char * restrict format, va_list arg);

// 7.19.6.9 The vfscanf function
int vfscanf(FILE * restrict stream, const char * restrict format, va_list arg);

// 7.19.6.10 The vprintf function
int vprintf(const char * restrict format, va_list arg);

// 7.19.6.11 The vscanf function
int vscanf(const char * restrict format, va_list arg);

// 7.19.6.12 The vsnprintf function
int vsnprintf(char * restrict s, size_t n, const char * restrict format, va_list arg);

// 7.19.6.13 The vsprintf function
int vsprintf(char * restrict s, const char * restrict format, va_list arg);

// 7.19.6.14 The vsscanf function
int vsscanf(const char * restrict s, const char * restrict format, va_list arg);

////////////////////////////////////////////////////////////////////////////////
// 7.19.7 Character input/output functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.7.1 The fgetc function
int fgetc(FILE *stream);

// 7.19.7.2 The fgets function
char *fgets(char * restrict s, int n, FILE * restrict stream);

// 7.19.7.3 The fputc function
int fputc(int c, FILE *stream);

// 7.19.7.4 The fputs function
int fputs(const char * restrict s, FILE * restrict stream);

// 7.19.7.5 The getc function
int getc(FILE *stream);

// 7.19.7.6 The getchar function
int getchar(void);

// 7.19.7.7 The gets function
char *gets(char *s);

// 7.19.7.8 The putc function
int putc(int c, FILE *stream);

// 7.19.7.9 The putchar function
int putchar(int c);

// 7.19.7.10 The puts function
int puts(const char *s) {
#if defined(__linux__) && defined(__LP64__)
  int ret;
  const unsigned long sys_write = 1;
  __asm("syscall"
        : "=a" (ret)
        : "a" (sys_write), "D" (1 /* stdout */), "S" (s), "d" (strlen(s))
        : "rcx", "r11");
  return ret;
#elif defined(__APPLE__)
  const unsigned int sys_write = (2 << 24) + 4;
  int ret;
  __asm("syscall"
        : "=a" (ret)
        : "a" (sys_write), "D" (1 /* stdout */), "S" (s), "d" (strlen(s))
        : "rcx", "r11");
  return ret;
#else
#  error "This OS is not 64-bit Linux or macOS (not yet supported)."
#endif
}

// 7.19.7.11 The ungetc function
int ungetc(int c, FILE *stream);

////////////////////////////////////////////////////////////////////////////////
// 7.19.8 Direct input/output functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.8.1 The fread function
size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);

// 7.19.8.2 The fwrite function
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);

////////////////////////////////////////////////////////////////////////////////
// 7.19.9 File positioning functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.9.1 The fgetpos function
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);

// 7.19.9.2 The fseek function
int fseek(FILE *stream, long int offset, int whence);

// 7.19.9.3 The fsetpos function
int fsetpos(FILE *stream, const fpos_t *pos);

// 7.19.9.4 The ftell function
long int ftell(FILE *stream);

// 7.19.9.5 The rewind function
void rewind(FILE *stream);

////////////////////////////////////////////////////////////////////////////////
// 7.19.10 Error-handling functions
////////////////////////////////////////////////////////////////////////////////

// 7.19.10.1 The clearerr function
void clearerr(FILE *stream);

// 7.19.10.2 The feof function
int feof(FILE *stream);

// 7.19.10.3 The ferror function
int ferror(FILE *stream);

// 7.19.10.4 The perror function
void perror(const char *s);
