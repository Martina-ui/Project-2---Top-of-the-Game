#!/usr/bin/env bash
set -e

SRCDIR=bridges-cxx
BRIDGE_SRCS=$(find "${SRCDIR}/src" -name '*.cpp' -print | tr '\n' ' ')
INCLUDE_DIRS="-I${SRCDIR}/src -I${SRCDIR}/src/data_src -I${SRCDIR}/include -I/opt/homebrew/include -I./bridges-cxx/src/data_src"

CPPFLAGS="-std=c++17 -O2 -pthread"

# ensure environment vars are set
if [ -z "$SECRET_HOLDING_USER_ID" ] || [ -z "$SECRET_HOLDING_API_KEY" ]; then
  echo "ERROR: set SECRET_HOLDING_USER_ID and SECRET_HOLDING_API_KEY in the shell."
  exit 1
fi

# ignore heap_test if it exists
rm -f heap_test.o 2>/dev/null || true

# compile only real project files (not heap_test)
g++ $CPPFLAGS main.cpp Menu.cpp MenuManager.cpp mergeSort.cpp HeapSort.cpp $BRIDGE_SRCS $INCLUDE_DIRS \
  $(curl-config --cflags --libs 2>/dev/null || true) \
  -ljsoncpp -lcurl -lssl -lcrypto -L/opt/homebrew/lib -I/opt/homebrew/include -o read_ign

echo "Built ./read_ign"
./read_ign
