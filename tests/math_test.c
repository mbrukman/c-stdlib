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
int fabs_test() {
  int num_failures = 0;

  const double pos_zero = 0.0f;
  const double neg_zero = -0.0f;
  const double pos_one = 1.0f;
  const double neg_one = -1.0f;

  if (pos_zero != fabs(pos_zero)) {
    num_failures++;
  }

  if (pos_zero != fabs(neg_zero)) {
    num_failures++;
  }

  if (pos_one != fabs(pos_one)) {
    num_failures++;
  }

  if (pos_one != fabs(neg_one)) {
    num_failures++;
  }

  return num_failures;
}

int fabsf_test() {
  int num_failures = 0;

  const float pos_zero = 0.0f;
  const float neg_zero = -0.0f;
  const float pos_one = 1.0f;
  const float neg_one = -1.0f;

  if (pos_zero != fabsf(pos_zero)) {
    num_failures++;
  }

  if (pos_zero != fabsf(neg_zero)) {
    num_failures++;
  }

  if (pos_one != fabsf(pos_one)) {
    num_failures++;
  }

  if (pos_one != fabsf(neg_one)) {
    num_failures++;
  }

  return num_failures;
}

int fabsl_test() {
  int num_failures = 0;

  const long pos_zero = 0L;
  const long neg_zero = -0L;
  const long pos_one = 1L;
  const long neg_one = -1L;

  if (pos_zero != fabsl(pos_zero)) {
    num_failures++;
  }

  if (pos_zero != fabsl(neg_zero)) {
    num_failures++;
  }

  if (pos_one != fabsl(pos_one)) {
    num_failures++;
  }

  if (pos_one != fabsl(neg_one)) {
    num_failures++;
  }

  return num_failures;
}

int main(int argc, char* argv[]) {
  int num_failures = 0;

  //////////////////////////////////////////////////////////////////////////////
  // 7.12.7 Power and absolute-value functions
  //////////////////////////////////////////////////////////////////////////////

  // 7.12.7.2 The fabs functions
  num_failures += fabs_test();
  num_failures += fabsf_test();
  num_failures += fabsl_test();

  return num_failures;
}
