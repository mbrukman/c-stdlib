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

#ifndef _LIBC_STDDEF_H_
#define _LIBC_STDDEF_H_

#include <internal/unimplemented.h>

////////////////////////////////////////////////////////////////////////////////
// 7.17 Common definitions
////////////////////////////////////////////////////////////////////////////////

typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef int wchar_t;

#define NULL ((void*) 0)

// Value type: `size_t`
#define offsetof(type, member_designator) UNIMPLEMENTED(offsetof)

#endif  // _LIBC_STDDEF_H_
