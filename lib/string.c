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

#include <string.h>

#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// 7.21.2 Copying functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.2.1 The memcpy function
void *memcpy(void * restrict s1, const void * restrict s2, size_t n);

// 7.21.2.2 The memmove function
void *memmove(void *s1, const void *s2, size_t n);

// 7.21.2.3 The strcpy function
char *strcpy(char * restrict s1, const char * restrict s2);

// 7.21.2.4 The strncpy function
char *strncpy(char * restrict s1, const char * restrict s2, size_t n);

////////////////////////////////////////////////////////////////////////////////
// 7.21.3 Concatenation functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.3.1 The strcat function
char *strcat(char * restrict s1, const char * restrict s2);

// 7.21.3.2 The strncat function
char *strncat(char * restrict s1, const char * restrict s2, size_t n);

////////////////////////////////////////////////////////////////////////////////
// 7.21.4 Comparison functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.4.1 The memcmp function
int memcmp(const void *s1, const void *s2, size_t n);

// 7.21.4.2 The strcmp function
int strcmp(const char *s1, const char *s2);

// 7.21.4.3 The strcoll function
int strcoll(const char *s1, const char *s2);

// 7.21.4.4 The strncmp function
int strncmp(const char *s1, const char *s2, size_t n);

// 7.21.4.5 The strxfrm function
size_t strxfrm(char * restrict s1, const char * restrict s2, size_t n);

////////////////////////////////////////////////////////////////////////////////
// 7.21.5 Search functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.5.1 The memchr function
void *memchr(const void *s, int c, size_t n);

// 7.21.5.2 The strchr function
char *strchr(const char *s, int c);

// 7.21.5.3 The strcspn function
size_t strcspn(const char *s1, const char *s2);

// 7.21.5.4 The strpbrk function
char *strpbrk(const char *s1, const char *s2);

// 7.21.5.5 The strrchr function
char *strrchr(const char *s, int c);

// 7.21.5.6 The strspn function
size_t strspn(const char *s1, const char *s2);

// 7.21.5.7 The strstr function
char *strstr(const char *s1, const char *s2);

// 7.21.5.8 The strtok function
char *strtok(char * restrict s1, const char * restrict s2);

////////////////////////////////////////////////////////////////////////////////
// 7.21.6 Miscellaneous functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.6.1 The memset function
void *memset(void *s, int c, size_t n);

// 7.21.6.2 The strerror function
char *strerror(int errnum);

// 7.21.6.3 The strlen function
size_t strlen(const char *s) {
  if (s == NULL) {
    return 0;
  }

  size_t length = 0;
  while (*s++ != '\0') {
    ++length;
  }
  return length;
}
