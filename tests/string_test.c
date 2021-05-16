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

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

////////////////////////////////////////////////////////////////////////////////
// 7.21.6 Miscellaneous functions
////////////////////////////////////////////////////////////////////////////////

// 7.21.6.3 The strlen function
int strlen_test() {
  int num_failures = 0;

  typedef struct {
    const char* input;
    size_t length;
  } test_case;

  const test_case test_cases[] = {
    { .input = NULL,       .length = 0 },
    { .input = "",         .length = 0 },
    { .input = "a",        .length = 1 },
    { .input = "ABCabc",   .length = 6 },
    { .input = "ABC\0abc", .length = 3 },
  };

  for (int i = 0; i < ARRAY_LENGTH(test_cases); ++i) {
    const test_case tc = test_cases[i];
    if (strlen(tc.input) != tc.length) {
      ++num_failures;
    }
  }

  return num_failures;
}

int main(int argc, char* argv[]) {
  int num_failures = 0;

  //////////////////////////////////////////////////////////////////////////////
  // 7.21.6 Miscellaneous functions
  //////////////////////////////////////////////////////////////////////////////

  // 7.21.6.3 The strlen function
  num_failures += strlen_test();

  return num_failures;
}
