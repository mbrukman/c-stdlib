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

#ifndef _LIBC_INTERNAL_UNIMPLEMENTED_H_
#define _LIBC_INTERNAL_UNIMPLEMENTED_H_

// A nice placeholder for macros to allow them to be defined, but which will
// fail compilation if they're ever used, and point the developer to the issue.
#define UNIMPLEMENTED(x) UNIMPLEMENTED_ ## x

#endif  // _LIBC_INTERNAL_UNIMPLEMENTED_H_
