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

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

int atoi_test() {
  int num_failures = 0;

  typedef struct {
    const char* input;
    int output;
  } test_case;

  const test_case test_cases[] = {
    { .input = "0",           .output = 0 },
    { .input = "abc",         .output = 0 },
    { .input = "-abc",        .output = 0 },
    { .input = "-5",          .output = -5 },
    { .input = "42",          .output = 42 },
    { .input = "-42",         .output = -42 },
    { .input = "256q123",     .output = 256 },
    { .input = "2147483647",  .output = 2147483647 },  // 2**31 – 1
    { .input = "-2147483648", .output = -2147483648 },  // –(2**31)
  };

  for (int i = 0; i < ARRAY_LENGTH(test_cases); ++i) {
    const test_case tc = test_cases[i];
    if (atoi(tc.input) != tc.output) {
      ++num_failures;
    }
  }

  return num_failures;
}

int atol_test() {
  int num_failures = 0;

  typedef struct {
    const char* input;
    long output;
  } test_case;

  const test_case test_cases[] = {
    { .input = "0",                    .output = 0 },
    { .input = "abc",                  .output = 0 },
    { .input = "42",                   .output = 42 },
    { .input = "256q123",              .output = 256 },
    { .input = "2147483647",           .output = 2147483647 },  // 2**31 – 1
    { .input = "-2147483648",          .output = -2147483648 },  // –(2**31)
    { .input = "9223372036854775807",  .output = 9223372036854775807LL },  // 2**63 – 1
    { .input = "-9223372036854775807", .output = -9223372036854775807LL },  // −(2**63 − 1)
  };

  for (int i = 0; i < ARRAY_LENGTH(test_cases); ++i) {
    const test_case tc = test_cases[i];
    if (atol(tc.input) != tc.output) {
      ++num_failures;
    }
  }

  return num_failures;
}

int atoll_test() {
  int num_failures = 0;

  typedef struct {
    const char* input;
    long long output;
  } test_case;

  const test_case test_cases[] = {
    { .input = "0",                    .output = 0 },
    { .input = "abc",                  .output = 0 },
    { .input = "42",                   .output = 42 },
    { .input = "256q123",              .output = 256 },
    { .input = "2147483647",           .output = 2147483647 },  // 2**31 – 1
    { .input = "-2147483648",          .output = -2147483648 },  // –(2**31)
    { .input = "9223372036854775807",  .output = 9223372036854775807LL },  // 2**63 – 1
    { .input = "-9223372036854775807", .output = -9223372036854775807LL },  // −(2**63 − 1)
  };

  for (int i = 0; i < ARRAY_LENGTH(test_cases); ++i) {
    const test_case tc = test_cases[i];
    if (atoll(tc.input) != tc.output) {
      ++num_failures;
    }
  }

  return num_failures;
}

int main(int argc, char* argv[]) {
  int num_failures = 0;

  num_failures += atoi_test();
  num_failures += atol_test();
  num_failures += atoll_test();

  return num_failures;
}
