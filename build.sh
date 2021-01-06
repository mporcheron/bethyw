#!/bin/bash

BIN_DIR="bin"
TESTS_DIR="tests"
SORUCE_FILES="bethyw.cpp input.cpp data.cpp"
MAIN_FILE="main.cpp"
EXECUTABLE="./${BIN_DIR}/bethyw"

set -x
cd "${0%/*}"

if [ $# -gt 1 ]; then
  echo "Unknown arguments!" "Only one argument accepted, and must begin with test"
  exit
elif [ $# -eq 1 ]; then
  if [[ $1 == test* ]]; then
    SOURCE_FILES="${SOURCE_FILES} ./${TESTS_DIR}/$1.cpp"
    MAIN_FILE="./${BIN_DIR}/catch.o"
    EXECUTABLE="./${TESTS_DIR}/$1.cpp"

    # Do we need to compile Catch2?
    if [ ! -f ./${BIN_DIR}/catch.o ]; then
      g++ --std=c++11 -c ./libs/catch2/catch_main.cpp -o ./${BIN_DIR}/catch.o
    else
      set -x
    fi
  fi
fi

echo "$# args"

mkdir -p ${BIN_DIR}
rm ${EXECUTABLE} 2> /dev/null
g++ --std=c++14 -Wall ${SORUCE_FILES} ${MAIN_FILE} -o ${EXECUTABLE}