# #!/bin/bash
# g++ -std=c++14 -I. -I./rapidjson/include $(curl-config --cflags) main.cpp $(curl-config --libs) -o game_program && ./game_program
#!/usr/bin/env bash
set -e

SRCDIR=bridges-cxx
# only include the library src folder (avoid examples/packaging)
BRIDGE_SRCS=$(find "${SRCDIR}/src" -name '*.cpp' -print | tr '\n' ' ')
INCLUDE_DIRS="-I${SRCDIR}/src -I${SRCDIR}/include -I${SRCDIR}/third_party/rapidjson/include"
CPPFLAGS="-std=c++17 -O2 -pthread"

# ensure environment vars are set
if [ -z "$SECRET_HOLDING_USER_ID" ] || [ -z "$SECRET_HOLDING_API_KEY" ]; then
  echo "ERROR: set SECRET_HOLDING_USER_ID and SECRET_HOLDING_API_KEY in the shell."
  exit 1
fi

# collect project sources (top-level .cpp files except main.cpp)
PROJECT_SRCS=$(find . -maxdepth 1 -name '*.cpp' -not -name 'main.cpp' -print | tr '\n' ' ')

# compile
if [ -n "$BRIDGE_SRCS" ]; then
  g++ $CPPFLAGS main.cpp $PROJECT_SRCS $BRIDGE_SRCS $INCLUDE_DIRS \
    $(curl-config --cflags --libs 2>/dev/null || true) -ljsoncpp -lcurl -lssl -lcrypto -o read_ign
else
  g++ $CPPFLAGS main.cpp $PROJECT_SRCS $INCLUDE_DIRS $(curl-config --cflags --libs 2>/dev/null || true) \
    -ljsoncpp -lcurl -lssl -lcrypto -o read_ign
fi

echo "Built ./read_ign"
./read_ign