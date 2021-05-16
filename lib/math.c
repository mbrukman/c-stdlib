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

#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// 7.12.7 Power and absolute-value functions
////////////////////////////////////////////////////////////////////////////////

// 7.12.7.2 The fabs functions
double fabs(double x) {
  // TODO(mbrukman): add support for NaN and Infinity.
  if (x == 0.0 || x == -0.0) {
    return 0.0;
  }
  return (x > 0) ? x : -x;
}

float fabsf(float x) {
  // TODO(mbrukman): add support for NaN and Infinity.
  if (x == 0.0 || x == -0.0) {
    return 0.0;
  }
  return (x > 0) ? x : -x;
}

long double fabsl(long double x) {
  // TODO(mbrukman): add support for NaN and Infinity.
  if (x == 0 || x == -0) {
    return 0;
  }
  return (x > 0) ? x : -x;
}
