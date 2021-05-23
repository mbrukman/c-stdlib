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
#   $2: file with expected stdout
#   $3: file with expected stderr
#   $*: command to execute

declare -i status=0

declare -ir EXPECTED_STATUS_CODE="$1"
declare -r EXPECTED_STDOUT="$2"
declare -r EXPECTED_STDERR="$3"
shift 3

declare -r TEMP_DIR="${TMPDIR:-${TMP:-/tmp}}"
declare -r TEST_CMD="$(basename "$0")"

declare -r ACTUAL_STDOUT="$(mktemp "${TEMP_DIR}/${TEST_CMD}.stdout.XXXXXX")"
declare -r ACTUAL_STDERR="$(mktemp "${TEMP_DIR}/${TEST_CMD}.stderr.XXXXXX")"

"$@" > "${ACTUAL_STDOUT}" 2> "${ACTUAL_STDERR}"
declare -ir ACTUAL_STATUS_CODE="$?"
if [[ ${EXPECTED_STATUS_CODE} -ne ${ACTUAL_STATUS_CODE} ]]; then
  echo "Expected status code: ${EXPECTED_STATUS_CODE}" >&2
  echo "  Actual status code: ${ACTUAL_STATUS_CODE}" >&2
  status=1
fi

if ! diff -u "${EXPECTED_STDOUT}" "${ACTUAL_STDOUT}" ; then
  echo "Found differences in stdout"
  status=2
fi

if ! diff -u "${EXPECTED_STDERR}" "${ACTUAL_STDERR}" ; then
  echo "Found differences in stderr"
  status=3
fi

if [ ${status} -eq 0 ]; then
  echo "PASSED"
else
  echo "FAILED"
fi

exit ${status}
