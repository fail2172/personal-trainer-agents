#!/usr/bin/env bash

cd "$(dirname "$0")"

source ../set_vars.sh

set -eo pipefail

python3 ${APP_ROOT_PATH}/scripts/clang/format-code.py --check ${APP_ROOT_PATH}/problem-solver/cxx/
