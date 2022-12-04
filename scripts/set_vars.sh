#!/bin/bash

echo "$1"

APP_ROOT_PATH=$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && cd .. && pwd)

if [ "$1" == "-ci" ]; then
  {
    echo PLATFORM_PATH="${APP_ROOT_PATH}/ostis-web-platform"
    echo SC_MACHINE_PATH="${PLATFORM_PATH}/sc-machine"
    echo INTERFACE_PATH="${APP_ROOT_PATH}"/interface
    echo SCRIPTS_PATH="${APP_ROOT_PATH}"/scripts
    echo KB_PATH="${APP_ROOT_PATH}"/kb
  } >>"$GITHUB_ENV"
  echo APP_ROOT_PATH="$(pwd)" >>"$GITHUB_ENV"
else
  export PLATFORM_PATH="${APP_ROOT_PATH}/ostis-web-platform"
  export SC_MACHINE_PATH="${PLATFORM_PATH}/sc-machine"
  export INTERFACE_PATH="${APP_ROOT_PATH}"/interface
  export SCRIPTS_PATH="${APP_ROOT_PATH}"/scripts
  export KB_PATH="${APP_ROOT_PATH}"/kb
fi
