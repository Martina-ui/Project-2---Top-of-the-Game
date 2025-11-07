#!/usr/bin/env bash
set -e

SRCDIR=bridges-cxx
BRIDGE_SRCS=$(find "${SRCDIR}/src" -name '*.cpp' -print | tr '\n' ' ')
INCLUDE_DIRS="-I${SRCDIR}/src -I${SRCDIR}/src/data_src -I${SRCDIR}/include -I/opt/homebrew/include -I./bridges-cxx/src/data_src"

CPPFLAGS="-std=c++17 -O2 -pthread -w"

if [ -z "$SECRET_HOLDING_USER_ID" ] || [ -z "$SECRET_HOLDING_API_KEY" ]; then
  echo "ERROR: set SECRET_HOLDING_USER_ID and SECRET_HOLDING_API_KEY in the shell."
  exit 1
fi

rm -f heap_test.o 2>/dev/null || true

g++ $CPPFLAGS \
  "Menu/main.cpp" \
  "Menu/Menu.cpp" \
  "Menu/MenuManager.cpp" \
  "Game and Sorting/Merge Sort/mergeSort.cpp" \
  "Game and Sorting/Heap Sort/HeapSort.cpp" \
  $BRIDGE_SRCS \
  $INCLUDE_DIRS \
  $(curl-config --cflags --libs 2>/dev/null || true) \
  -ljsoncpp -lcurl -lssl -lcrypto -L/opt/homebrew/lib \
  -o read_ign

echo "Built ./read_ign"
./read_ign
