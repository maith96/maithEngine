#!/bin/bash

set -e
set -x

BUILD_DIR="build"

# Create the build directory if it does not exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

pushd $BUILD_DIR

cmake ..
cmake --build .

./maith

popd
