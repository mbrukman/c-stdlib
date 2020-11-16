#!/bin/bash -u
#
# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

echo "Complex test..."

declare -r INCLUDE="../lib/include"
declare -r LIBC="../lib/libc.a"
# FIXME(mbrukman): this is macOS-specific; figure out Linux equivalent.
declare -r LIBSYSTEM="/usr/lib/libSystem.dylib"

declare -r SRC="complex_test.c"
declare -r OBJ="complex_test.o"
declare -r EXE="complex_test"

declare -i status=0

function run_complex_test() {
  local real="$1"
  local imag="$2"
  local expected="$3"

  # Compile
  ../clang.sh "-I${INCLUDE}" -DREAL="${real}" -DIMAG="${imag}" "${SRC}" -c -o "${OBJ}"

  # Link
  ld -arch x86_64 -execute "${OBJ}" "${LIBC}" "${LIBSYSTEM}" -o "${EXE}"

  # Run
  ./"${EXE}"

  local actual=$?
  if [ ${actual} -ne ${expected} ]; then
    status=1
    echo -n "  test case FAILED: "
  else
    echo -n "  test case PASSED: "
  fi
  echo -n "Input: real=${real}, imag=${imag}, "
  echo "expected=${expected}, actual=${actual}"
}

run_complex_test 2 5 7
run_complex_test 3 8 11

if [ ${status} -eq 0 ]; then
  echo "PASSED"
else
  echo "FAILED"
fi

exit ${status}
