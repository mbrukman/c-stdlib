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

#ifndef _LIBC_MATH_H_
#define _LIBC_MATH_H_

#include <internal/unimplemented.h>

// 7.12.3.6 The signbit macro
#define signbit(x) UNIMPLEMENTED(signbit)

////////////////////////////////////////////////////////////////////////////////
// 7.12.4 Trigonometric functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.4.1 The acos functions
double acos(double x);
float acosf(float x);
long double acosl(long double x);

// 7.12.4.2 The asin functions
double asin(double x);
float asinf(float x);
long double asinl(long double x);

// 7.12.4.3 The atan functions
double atan(double x);
float atanf(float x);
long double atanl(long double x);

// 7.12.4.4 The atan2 functions
double atan2(double y, double x);
float atan2f(float y, float x);
long double atan2l(long double y, long double x);

// 7.12.4.5 The cos functions
double cos(double x);
float cosf(float x);
long double cosl(long double x);

// 7.12.4.6 The sin functions
double sin(double x);
float sinf(float x);
long double sinl(long double x);

// 7.12.4.7 The tan functions
double tan(double x);
float tanf(float x);
long double tanl(long double x);

////////////////////////////////////////////////////////////////////////////////
// 7.12.5 Hyperbolic functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.5.1 The acosh functions
double acosh(double x);
float acoshf(float x);
long double acoshl(long double x);

// 7.12.5.2 The asinh functions
double asinh(double x);
float asinhf(float x);
long double asinhl(long double x);

// 7.12.5.3 The atanh functions
double atanh(double x);
float atanhf(float x);
long double atanhl(long double x);

// 7.12.5.4 The cosh functions
double cosh(double x);
float coshf(float x);
long double coshl(long double x);

// 7.12.5.5 The sinh functions
double sinh(double x);
float sinhf(float x);
long double sinhl(long double x);

// 7.12.5.6 The tanh functions
double tanh(double x);
float tanhf(float x);
long double tanhl(long double x);

////////////////////////////////////////////////////////////////////////////////
// 7.12.6 Exponential and logarithmic functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.6.1 The exp functions
double exp(double x);
float expf(float x);
long double expl(long double x);

// 7.12.6.2 The exp2 functions
double exp2(double x);
float exp2f(float x);
long double exp2l(long double x);

// 7.12.6.3 The expm1 functions
double expm1(double x);
float expm1f(float x);
long double expm1l(long double x);

// 7.12.6.4 The frexp functions
double frexp(double value, int *exp);
float frexpf(float value, int *exp);
long double frexpl(long double value, int *exp);

// 7.12.6.5 The ilogb functions
int ilogb(double x);
int ilogbf(float x);
int ilogbl(long double x);

// 7.12.6.6 The ldexp functions
double ldexp(double x, int exp);
float ldexpf(float x, int exp);
long double ldexpl(long double x, int exp);

// 7.12.6.7 The log functions
double log(double x);
float logf(float x);
long double logl(long double x);

// 7.12.6.8 The log10 functions
double log10(double x);
float log10f(float x);
long double log10l(long double x);

// 7.12.6.9 The log1p functions
double log1p(double x);
float log1pf(float x);
long double log1pl(long double x);

// 7.12.6.10 The log2 functions
double log2(double x);
float log2f(float x);
long double log2l(long double x);

// 7.12.6.11 The logb functions
double logb(double x);
float logbf(float x);
long double logbl(long double x);

// 7.12.6.12 The modf functions
double modf(double value, double *iptr);
float modff(float value, float *iptr);
long double modfl(long double value, long double *iptr);

// 7.12.6.13 The scalbn and scalbln functions
double scalbn(double x, int n);
float scalbnf(float x, int n);
long double scalbnl(long double x, int n);
double scalbln(double x, long int n);
float scalblnf(float x, long int n);
long double scalblnl(long double x, long int n);

////////////////////////////////////////////////////////////////////////////////
// 7.12.7 Power and absolute-value functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.7.1 The cbrt functions
double cbrt(double x);
float cbrtf(float x);
long double cbrtl(long double x);

// 7.12.7.2 The fabs functions
double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

// 7.12.7.3 The hypot functions
double hypot(double x, double y);
float hypotf(float x, float y);
long double hypotl(long double x, long double y);

// 7.12.7.4 The pow functions
double pow(double x, double y);
float powf(float x, float y);
long double powl(long double x, long double y);

// 7.12.7.5 The sqrt functions
double sqrt(double x);
float sqrtf(float x);
long double sqrtl(long double x);

////////////////////////////////////////////////////////////////////////////////
// 7.12.8 Error and gamma functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.8.1 The erf functions
double erf(double x);
float erff(float x);
long double erfl(long double x);

// 7.12.8.2 The erfc functions
double erfc(double x);
float erfcf(float x);
long double erfcl(long double x);

// 7.12.8.3 The lgamma functions
double lgamma(double x);
float lgammaf(float x);
long double lgammal(long double x);

// 7.12.8.4 The tgamma functions
double tgamma(double x);
float tgammaf(float x);
long double tgammal(long double x);

////////////////////////////////////////////////////////////////////////////////
// 7.12.9 Nearest integer functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.9.1 The ceil functions
double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

// 7.12.9.2 The floor functions
double floor(double x);
float floorf(float x);
long double floorl(long double x);

// 7.12.9.3 The nearbyint functions
double nearbyint(double x);
float nearbyintf(float x);
long double nearbyintl(long double x);

// 7.12.9.4 The rint functions
double rint(double x);
float rintf(float x);
long double rintl(long double x);

// 7.12.9.5 The lrint and llrint functions
long int lrint(double x);
long int lrintf(float x);
long int lrintl(long double x);
long long int llrint(double x);
long long int llrintf(float x);
long long int llrintl(long double x);

// 7.12.9.6 The round functions
double round(double x);
float roundf(float x);
long double roundl(long double x);

// 7.12.9.7 The lround and llround functions
long int lround(double x);
long int lroundf(float x);
long int lroundl(long double x);
long long int llround(double x);
long long int llroundf(float x);
long long int llroundl(long double x);

// 7.12.9.8 The trunc functions
double trunc(double x);
float truncf(float x);
long double truncl(long double x);

////////////////////////////////////////////////////////////////////////////////
// 7.12.10 Remainder functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.10.1 The fmod functions
double fmod(double x, double y);
float fmodf(float x, float y);
long double fmodl(long double x, long double y);

// 7.12.10.2 The remainder functions
double remainder(double x, double y);
float remainderf(float x, float y);
long double remainderl(long double x, long double y);

// 7.12.10.3 The remquo functions
double remquo(double x, double y, int *quo);
float remquof(float x, float y, int *quo);
long double remquol(long double x, long double y, int *quo);

////////////////////////////////////////////////////////////////////////////////
// 7.12.11 Manipulation functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.11.1 The copysign functions
double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

// 7.12.11.2 The nan functions
double nan(const char *tagp);
float nanf(const char *tagp);
long double nanl(const char *tagp);

// 7.12.11.3 The nextafter functions
double nextafter(double x, double y);
float nextafterf(float x, float y);
long double nextafterl(long double x, long double y);

// 7.12.11.4 The nexttoward functions
double nexttoward(double x, long double y);
float nexttowardf(float x, long double y);
long double nexttowardl(long double x, long double y);

////////////////////////////////////////////////////////////////////////////////
// 7.12.12 Maximum, minimum, and positive difference functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.12.1 The fdim functions
double fdim(double x, double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);

// 7.12.12.2 The fmax functions
double fmax(double x, double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);

// 7.12.12.3 The fmin functions
double fmin(double x, double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);

////////////////////////////////////////////////////////////////////////////////
// 7.12.13 Floating multiply-add
////////////////////////////////////////////////////////////////////////////////

// 7.12.13.1 The fma functions
double fma(double x, double y, double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);

////////////////////////////////////////////////////////////////////////////////
// 7.12.14 Comparison macros
////////////////////////////////////////////////////////////////////////////////

// 7.12.14.1 The isgreater macro
// int isgreater(real-floating x, real-floating y);
#define isgreater(x, y) UNIMPLEMENTED(isgreater)

// 7.12.14.2 The isgreaterequal macro
// int isgreaterequal(real-floating x, real-floating y);
#define isgreaterequal(x, y) UNIMPLEMENTED(isgreaterequal)

// 7.12.14.3 The isless macro
// int isless(real-floating x, real-floating y);
#define isless(x, y) UNIMPLEMENTED(isless)

// 7.12.14.4 The islessequal macro
// int islessequal(real-floating x, real-floating y);
#define islessequal(x, y) UNIMPLEMENTED(islesequal)

// 7.12.14.5 The islessgreater macro
// int islessgreater(real-floating x, real-floating y);
#define islessgreater(x, y) UNIMPLEMENTED(islessgreater)

// 7.12.14.6 The isunordered macro
// int isunordered(real-floating x, real-floating y);
#define isunordered(x, y) UNIMPLEMENTED(isunordered)

#endif  // _LIBC_MATH_H_
