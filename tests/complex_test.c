// Copyright 2020 Google LLC
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

#include <complex.h>

// Technically, the style of initializing complex values in this file is an
// extension and is not part of the C99 standard; compiling with `clang
// -pedantic` will result in a warning:
//
//     complex initialization specifying real and imaginary components is an extension [-Wcomplex-component-init]
//
// The C11 standard includes the make_complex(), make_complexF(), make_complexL() macros to help with
// this. For more info, see:
//
// * https://stackoverflow.com/questions/5914590/c99-right-way-to-initialize-complex-variable-with-0-0-0i
// * http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1464.htm
// * https://en.cppreference.com/w/c/numeric/complex/make_complex
//
// That said, we'll need to take a shortcut here at least initially to be able
// to test creal() and cimag() functions easily without having a functional
// implementation of any other parts of the C99 standard library.

// 7.3.9.2 The cimag functions
int cimag_test() {
  int num_failures = 0;

  if (cimag(2 + 5 * I) != 5) {
    num_failures++;
  }
  if (cimag(-3 - 8 * I) != -8) {
    num_failures++;
  }

  return num_failures;
}

int cimagf_test() {
  int num_failures = 0;

  if (cimagf(2 + 5 * I) != 5) {
    num_failures++;
  }
  if (cimagf(-3 - 8 * I) != -8) {
    num_failures++;
  }

  return num_failures;
}

int cimagl_test() {
  int num_failures = 0;

  if (cimagl(2 + 5 * I) != 5) {
    num_failures++;
  }
  if (cimagl(-3 - 8 * I) != -8) {
    num_failures++;
  }

  return num_failures;
}

// 7.3.9.6 The creal functions
int creal_test() {
  int num_failures = 0;

  if (creal(2 + 5 * I) != 2) {
    num_failures++;
  }
  if (creal(-3 - 8 * I) != -3) {
    num_failures++;
  }

  return num_failures;
}

int crealf_test() {
  int num_failures = 0;

  if (crealf(2 + 5 * I) != 2) {
    num_failures++;
  }
  if (crealf(-3 - 8 * I) != -3) {
    num_failures++;
  }

  return num_failures;
}

int creall_test() {
  int num_failures = 0;

  if (creall(2 + 5 * I) != 2) {
    num_failures++;
  }
  if (creall(-3 - 8 * I) != -3) {
    num_failures++;
  }

  return num_failures;
}

int main(int argc, char* argv[]) {
  int num_failures = 0;

  // 7.3.9.2 The cimag functions
  num_failures += cimag_test();

  // TODO(mbrukman): enable these tests once they work on Linux.
  // num_failures += cimagf_test();
  // num_failures += cimagl_test();

  // 7.3.9.6 The creal functions
  num_failures += creal_test();

  // TODO(mbrukman): enable these tests once they work on Linux.
  // num_failures += crealf_test();
  // num_failures += creall_test();

  return num_failures;
}
