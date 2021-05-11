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

#ifndef REAL
# error "Must #define REAL (integer) before compiling this file."
#endif

#ifndef IMAG
# error "Must #define IMAG (integer) before compiling this file."
#endif

int main(int argc, char* argv[]) {
  // Technically, this style of initializing a complex value is an extension
  // and is not part of the C99 standard; compiling with `clang -pedantic` will
  // result in a warning:
  //
  //     complex initialization specifying real and imaginary components is an extension [-Wcomplex-component-init]
  //
  // The C11 standard includes the CMPLX(), CMPLXF(), CMPLXL() macros to help with
  // this. For more info, see:
  //
  // * https://stackoverflow.com/questions/5914590/c99-right-way-to-initialize-complex-variable-with-0-0-0i
  // * http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1464.htm
  // * https://en.cppreference.com/w/c/numeric/complex/CMPLX
  //
  // That said, we'll need to take a shortcut here at least initially to be able
  // to test creal() and cimag() functions easily without having a functional
  // implementation of any other parts of the C99 standard library.
  complex double i = REAL + IMAG * I;
  return creal(i) + cimag(i);
}
