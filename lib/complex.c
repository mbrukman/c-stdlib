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

// 7.3.9.2 The cimag functions
double cimag(double complex z) {
  return ((_Complex_Double*) &z)->imag;
}

float cimagf(float complex z) {
  return ((_Complex_Float*) &z)->imag;
}

long double cimagl(long double complex z) {
  return ((_Complex_Long_Double*) &z)->imag;
}

// 7.3.9.6 The creal functions
double creal(double complex z) {
  return ((_Complex_Double*) &z)->real;
}

float crealf(float complex z) {
  return ((_Complex_Float*) &z)->real;
}

long double creall(long double complex z) {
  return ((_Complex_Long_Double*) &z)->real;
}
