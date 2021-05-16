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

#ifndef _LIBC_COMPLEX_H_
#define _LIBC_COMPLEX_H_

typedef struct {
  float real, imag;
} _Complex_Float;

typedef struct {
  double real, imag;
} _Complex_Double;

typedef struct {
  long double real, imag;
} _Complex_Long_Double;

// 7.3.1 paragraph 4
#define complex _Complex
#define _Complex_I ((const float _Complex) {0, 1})

// 7.3.1 paragraph 5
#if defined(_Imaginary)
#  define _Imaginary_I ((const float _Imaginary) {0, 1})
#  define imaginary _Imaginary
#else // !defined(_Imaginary)
   // Clang does not support `_Imaginary`, but it does support `_Complex`.
#  define _Imaginary_I ((const float _Complex) {0, 1})
#  define imaginary _Complex
#endif // defined(_Imaginary)

// 7.3.1 paragraph 6
#define I _Imaginary_I

// 7.3.5.4: The ccos functions
double complex ccos(double complex z);
float complex ccosf(float complex z);
long double complex ccosl(long double complex z);

// 7.3.5.5: The csin functions
double complex csin(double complex z);
float complex csinf(float complex z);
long double complex csinl(long double complex z);

// 7.3.9.2 The cimag functions
double cimag(double complex z);
float cimagf(float complex z);
long double cimagl(long double complex z);

// 7.3.9.6 The creal functions
double creal(double complex z);
float crealf(float complex z);
long double creall(long double complex z);

#endif  // _LIBC_COMPLEX_H_
