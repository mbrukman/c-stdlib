#!/bin/bash -u
#
# Copyright 2021 Google LLC
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

# Runs a command, expecting it to exit with the given status code.
#
# Exit status codes are as follows:
# * 0 (success) iff the command exists with the expected status code
# * 1 (failure) otherwise
#
# Args:
#   $1: status code to expect
#   $*: command to execute

declare -ir EXPECTED_STATUS_CODE="$1"
shift

"$@"
declare -ir ACTUAL_STATUS_CODE="$?"
if [[ ${EXPECTED_STATUS_CODE} -eq ${ACTUAL_STATUS_CODE} ]]; then
  echo "PASSED"
  exit 0
else
  echo "FAILED" >&2
  echo "Expected status code: ${EXPECTED_STATUS_CODE}" >&2
  echo "  Actual status code: ${ACTUAL_STATUS_CODE}" >&2
  exit 1
fi
